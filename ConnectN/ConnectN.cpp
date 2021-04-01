#include "ConnectN.h"
#include "ui_ConnectN.h"
#include "logic.h"

ConnectN::ConnectN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConnectN)
{
    //setting up the ui
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->installEventFilter(this);
    size_board = 8;
    numToConnect = 0;
    columnchosen = 0;
    usermove_flag = false;
    ui->gamewindow->setScene(scene);
    // combo box for board size and number of pieces to connect
    for (int i = 8; i<=16; i++){
        ui->size_cbox->addItem(QString::number(i));
    }
    for (int i = 4; i<=16; i++){
        ui->win_cbox->addItem(QString::number(i));
    }
    ui->statuslabel->setText("Click New Game to begin");
    setWindowIcon(QIcon(":/icon/icon.png"));
    setWindowTitle("Connect N");
    move->setMedia(QUrl("qrc:/icon/Sounds/c4_piece.wav"));
    move->setVolume(30);
    error->setMedia(QUrl("qrc:/icon/Sounds/sfx_sounds_error2.wav"));
    error->setVolume(30);
    action->setMedia(QUrl("qrc:/icon/Sounds/button_sound.wav"));
    action->setVolume(75);
    tie_sound->setMedia(QUrl("qrc:/icon/Sounds/270329__littlerobotsoundfactory__jingle-lose-00.wav"));
    tie_sound->setVolume(75);
    victory->setMedia(QUrl("qrc:/icon/Sounds/270333__littlerobotsoundfactory__jingle-win-00.wav"));
    victory->setVolume(75);
}

ConnectN::~ConnectN()
{  delete ui; }

//clicking new game draws_board and starts new game
void ConnectN::on_newgame_btn_clicked()
{

    int size_board_check = (ui->size_cbox->currentText()).toInt();
    int numToConnect_check = (ui->win_cbox->currentText().toInt());
    if (numToConnect_check > size_board_check){
      ui->statuslabel2->  setText("Board is smaller than pieces needed to win");
      error->play();
      return;
    }

    action->play();
    size_board = size_board_check;
    tie = size_board * size_board;
    count = 0;
    numToConnect = numToConnect_check;
    draw_board(size_board);
    startgame(size_board);
    if (currentPlayer == 1){
    ui->statuslabel->setText("Player 1's turn (red)");
    ui->statuslabel2->setText("Click on a column to place your piece");}
    else {
        ui->statuslabel->setText("Player 2's turn (red)");
        ui->statuslabel2->setText("Click on a column to place your piece");}
    return;
}
//draw board based on board size
void ConnectN::draw_board(int size)
{
    //pen setup
    QPen outlinePen(Qt::black);
    QPen circlePenGray(Qt::black);   
    QBrush bbrush(QColor(161,196,253));
    QBrush graybrush(QColor(207,217,223));
    outlinePen.setWidth(2);
    circlePenGray.setWidth(1);
    //victory msg setup
    win_msg = new QGraphicsTextItem;
    win_msg->setPos(110,380);
    win_msg->setFont(QFont("Courier New", 30, QFont::Bold));

    //set up board display
    scene->clear();
    scene->setSceneRect(0,0,1050,750);
    int xcolumns = 1050/size;
    int yrows = 750/size;
    for (int i =0; i<=size-1 ; i++)
    {
        for (int j =0; j<=size-1 ; j++)
        {
            scene->addRect(j*xcolumns,i*yrows,xcolumns,yrows,outlinePen,bbrush);
            scene->addEllipse(((j)*xcolumns)+1050/(size*4), ((i)*yrows)+750/(size*7),65-(32/8)*(size-8),65-(32/8)*(size-8),circlePenGray,graybrush);
        }
      }
    return;
}

//to catch when the mouse is being clicked in graphicscene and gives column clicked xpos, ypos to determine which column to place piecec into
bool ConnectN::eventFilter(QObject *target, QEvent *event)
{
    if (target == scene)
    {
        if (event->type() == QEvent::GraphicsSceneMousePress)
        {
            const QGraphicsSceneMouseEvent* const me = static_cast<const QGraphicsSceneMouseEvent*>(event);
            const QPointF position = me->scenePos();
            double posx = position.x();
            columnclicked(posx);
        }
    }
    return QMainWindow::eventFilter(target, event);
}

/*
called by eventFilter. takes the column in which the player clicked, places it,
checks for winner and switches to next player
algorithm for making move
determine which player is moving, check if move is legal, if legal place this piece,
check if there is a winner, turn player switches, await next input
*/

bool ConnectN::columnclicked(double posx)
{
  if(gamestarted == true)
  {
      int xcolumns = 1050/size_board;
      for(int i=0; i<=size_board-1; i++)
      {
        if((xcolumns*i < posx)  && (posx < xcolumns*(i+1)))
        {
          columnchosen = i;
          usermove_flag = true;
          break;
        }
      }

      if(usermove_flag == true)
      {

          if(currentPlayer == 1)
          {

              if(!userColumnMove(board,numRows, columnchosen))
              {
                currentPlayer = 1;
                usermove_flag = false;
                ui->statuslabel->setText("Selected column was full please try again");
                ui->statuslabel2->setText("Player 1 (red) click on a column to place your piece");
                error->play();
              }
              else
              {
                MakeMove(board, numRows, currentPlayer, columnchosen);
                if (move->state() == QMediaPlayer::PlayingState){   // play sound
                    move->setPosition(0);
                }
                else if(move->state() == QMediaPlayer::StoppedState){
                    move->play();
                }

                if(CheckWinner(board,numRows,numToConnect,columnchosen,currentPlayer)){
                  QPen outlinePen2(Qt::black);
                  outlinePen2.setWidth(4);
                  scene->addRect(100,372,840,90,outlinePen2,QBrush(QColor(255,0,0)));
                  ui->statuslabel->setText("Player 1 (red) has won!");
                  ui->statuslabel2->setText("Select new game to play again");
                  win_msg->setPlainText("Player 1 (red) won the game");
                  win_msg->setPos(110,380);

                  scene->addItem(win_msg);
                  victory->play();
                  gamestarted = false;
                  return true;
                }
                count++;
                if (tie == count){
                    QPen outlinePen2(Qt::white);
                    outlinePen2.setWidth(4);
                    scene->addRect(100,372,840,90,outlinePen2,QBrush(QColor(128,128,128)));
                    win_msg->setPlainText("Tie Game");
                    win_msg->setPos(410,380);

                    scene->addItem(win_msg);
                    tie_sound->play();
                    gamestarted = false;
                }
                // DisplayBoard(board,numRows); for testing
                ui->statuslabel->setText("Player 2's turn (yellow)");
                ui->statuslabel2->setText("Click on a column to place your piece");
                currentPlayer = 2;
                usermove_flag = false;
              }
          }
          else if(currentPlayer == 2)
          {


              if(!userColumnMove(board,numRows, columnchosen))
              {
                currentPlayer = 2;
                usermove_flag = false;
                ui->statuslabel->setText("Selected column was full please try again");
                ui->statuslabel2->setText("Player 2 (yellow) click on a column to place your piece");
                error->play();
              }
              else
              {
                MakeMove(board, numRows, currentPlayer, columnchosen);
                if (move->state() == QMediaPlayer::PlayingState){   // play sound
                    move->setPosition(0);
                }
                else if(move->state() == QMediaPlayer::StoppedState){
                    move->play();
                }
                if(CheckWinner(board,numRows,numToConnect,columnchosen,currentPlayer)){
                          QPen outlinePen2(Qt::black);
                          outlinePen2.setWidth(4);
                          scene->addRect(100,372,920,90,outlinePen2,QBrush(QColor(255,255,0)));
                          ui->statuslabel->setText("Player 2 (yellow) has won!");
                          ui->statuslabel2->setText("Select new game to play again");
                          win_msg->setPlainText("Player 2 (yellow) won the game");
                          win_msg->setPos(110,380);

                          scene->addItem(win_msg);
                          victory->play();
                          gamestarted = false;
                          return true;
                }
                //DisplayBoard(board,numRows); for testing
                count++;
                if (tie == count){
                    QPen outlinePen2(Qt::white);
                    outlinePen2.setWidth(4);
                    scene->addRect(100,372,840,90,outlinePen2,QBrush(QColor(128,128,128)));
                    win_msg->setPlainText("Tie Game");
                    win_msg->setPos(410,380);

                    scene->addItem(win_msg);
                    tie_sound->play();
                    gamestarted = false;
                }
                currentPlayer = 1;
                usermove_flag = false;
                ui->statuslabel->setText("Player 1's turn (red)");
                ui->statuslabel2->setText("Click on a column to place your piece");

              }
          }
          return true;
      }
    }
  return false;
}

//called by on_newgame_btn_clciked
//turns the flag gamestarted to be true to allow columnclicked to start accepting player actions
int ConnectN::startgame(int size_board)
{
  const int MINCONNECTNUM = 4;
  numRows = size_board;
  if (currentPlayer == 1) currentPlayer = 2;
  else currentPlayer = 1;
  qDebug() << currentPlayer;
  columnchosen = 0;
  gamestarted = true;
  if(userConnectInput(numToConnect, numRows, MINCONNECTNUM))
  {
    //decleraton of board
    board = NULL;
    board = new int*[numRows];
    for(int i = 0; i < numRows ; i++)
    {
      board[i] = new int[numRows];
    }
    InitializeBoard(board, numRows);
  }
  return 0;
}

//places the piece onto the board
//algorithm for drawing the piece at the desired column
bool ConnectN::MakeMove(int** connectNBoard, int numRowsInBoard, int playerID, int columnChosen){
  int pos = columnFull(connectNBoard, columnChosen, numRowsInBoard);
  int xcolumns = 1050/size_board;
  int yrows = 750/size_board;
  QBrush rbrush(Qt::red);
  QBrush ybrush(Qt::yellow);
  QPen  rpen(Qt::red);
  QPen  ypen(Qt::yellow);
  ypen.setWidth(3);
  rpen.setWidth(3);
  if (playerID == 1){
    connectNBoard[pos][columnChosen] = 1;
    scene->addEllipse(((columnChosen)*xcolumns)+1050/(size_board*4), ((pos)*yrows)+750/(size_board*7),65-(32/8)*(size_board-8),65-(32/8)*(size_board-8),rpen,rbrush);

    return true;
  }
  else if(playerID ==2)
  {
    connectNBoard[pos][columnChosen] = 2;
    scene->addEllipse(((columnChosen)*xcolumns)+1050/(size_board*4), ((pos)*yrows)+750/(size_board*7),65-(32/8)*(size_board-8),65-(32/8)*(size_board-8),ypen,ybrush);

    return true;
  }
  return false;
}
