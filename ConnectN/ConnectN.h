#ifndef ConnectN_H
#define ConnectN_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QtDebug>
#include <QPointF>
#include <iostream>
#include <QMediaPlayer>
#include <stdlib.h>

namespace Ui {
class ConnectN;
}

class ConnectN : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectN(QWidget *parent = nullptr);
    ~ConnectN();
    bool eventFilter(QObject *target, QEvent *event);
    int startgame(int size_board);
    bool columnclicked(double posx);
    int numRows;
    int size_board;
    int currentPlayer = rand()%2+1;
    int numToConnect;
    int columnchosen;
    bool usermove_flag;
    bool gamestarted;
    int **board;
    Ui::ConnectN *ui;
    bool MakeMove(int** connectNBoard, int numRowsInBoard, int playerID, int columnChosen);
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private slots:
    void on_newgame_btn_clicked();
    void draw_board(int size);

private:
    int count, tie;
    QGraphicsScene *scene;
    QGraphicsLineItem *line;
    QGraphicsTextItem *text;
    QGraphicsView *view;
    QGraphicsTextItem *win_msg;
    QMediaPlayer* victory = new QMediaPlayer();
    QMediaPlayer* move = new QMediaPlayer();
    QMediaPlayer* error = new QMediaPlayer();
    QMediaPlayer* action = new QMediaPlayer();
    QMediaPlayer* tie_sound = new QMediaPlayer();
};

#endif // ConnectN_H
