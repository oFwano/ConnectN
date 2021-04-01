#include <iostream>
#include <iomanip>
#include <limits>
#include "ui_ConnectN.h"



using namespace std;

bool userConnectInput(int numToConnect, int numRows,const int MINCONNECTNUM);
bool InitializeBoard(int **connectNBoard,int numRowsInBoard);
bool DisplayBoard(int **connectNBoard, int numRowsInBoard);
char BoardChar(int value);
bool CheckWinner(int** connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int playerID);
bool userColumnMove(int **connectNBoard, int numRows, int columnChosen);
bool MakeMove(int** connectNBoard, int numRowsInBoard, int playerID, int columnChosen);
int columnFull(int **connectNBoard, int column, int numRows);


bool userConnectInput(int numToConnect, int numRows, int MINCONNECTNUM)
{
  int connect = numToConnect;
      if ((connect > numRows)||(connect < MINCONNECTNUM) ) {return false;}
      else
      {
        numToConnect = connect;
        return true;
      }
  return false;
}

bool InitializeBoard(int **connectNBoard,int numRowsInBoard){
  //if board pointer in NULL show an error
  if(connectNBoard == nullptr)
  {
    return false;
  }
  //initialize every board(connectNBoard) element to 0 if there are no errors
  for(int i = 0; i < numRowsInBoard ; i++){
    for(int j =0 ; j < numRowsInBoard ; j++){
        connectNBoard[i][j] = 0;
    }
  }
  return true;
}
bool DisplayBoard(int **connectNBoard, int numRowsInBoard){
  //if board pointer in NULL show an error
  if(connectNBoard == nullptr){
    return false;
  }
  // print the number heading column for the board
  for(int i = 0 ; i < numRowsInBoard; i++){
    if(i == 0){
      cout<<setw(3)<<" ";
    }
    cout<<setw(3)<<i;
    if( i == numRowsInBoard -1){
      cout<<endl;
    }
  }
  // print the rows with numbered row heading
  for(int i = 0; i < numRowsInBoard ; i++){
    for(int j = 0 ; j < numRowsInBoard; j++){
      if(j == 0 ){
        cout<<setw(3) << i;
      }
        cout<<setw(3)<<BoardChar(connectNBoard[i][j]);
    }
      cout<<endl;
  }
  return true;
}
char BoardChar(int value){
  if( value == 1 ){
    return 'R';
  }
  else if(value == 2){
    return 'B';
  }
  else{
    return 'o';
  }
}


//checking if column is a valid and error handling
bool userColumnMove(int **connectNBoard, int numRows, int columnChosen)
{
    int pos = -1;
    pos = columnFull(connectNBoard, columnChosen, numRows);
    if(pos == -1) {return false;}
    return true;
}

bool MakeMove(int** connectNBoard, int numRowsInBoard, int playerID, int columnChosen){
  int pos = columnFull(connectNBoard, columnChosen, numRowsInBoard);
  if (playerID == 1){
    connectNBoard[pos][columnChosen] = 1;
    return true;
  }
  else if(playerID ==2)
  {
    connectNBoard[pos][columnChosen] =2;
    return true;
  }
  return false;
}
int columnFull(int **connectNBoard, int column, int numRows)
{
  for(int i = 0; i < numRows; i++)
  {
    if(connectNBoard[i][column] != 0)
    {
      return i-1;
    }
    if(connectNBoard[i][column] == 0 && i == numRows -1 )
    {
      return i;
    }
  }
  return -1;
}
bool CheckWinner(int** connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int playerID){
  int horizontalCount = 0;
  int verticalCount = 0;
  int diagonalCount = 0;
  int invdiagonalCount = 0;
  int pos = 0;
    //finding the last the position the playerID has played
    //the pos is at connectNBoard[pos,columnChosen]
    for(int i = 0 ; i < numRowsInBoard; i++)
    {
      if(connectNBoard[i][columnChosen] == playerID)
      {
        pos = i;
        break;
      }
    }

    //checking if there are  player piecies connsectively vertically down the column with fixed column at columnChosen
    for(int i = pos; i < numRowsInBoard; i++)
    {
      if(connectNBoard[i][columnChosen] != playerID)
      {
        break;
      }
      else
      {
        verticalCount++;
      }
    }
    if(verticalCount >= numConnect)
    {
      return true;
    }


    //checking if there are player pieces connsectively horitzonally accross the row with fixed row at pos we found
    //checking on the right side of pos including pos
    for(int i = columnChosen; i < numRowsInBoard; i++)
    {
      if(connectNBoard[pos][i] != playerID){
        break;
      }
      else{
        horizontalCount++;
      }
    }
    //checking on left side  of pos exculding pos as it was already counted
    if(columnChosen-1 >=0)
    {
      for(int i = columnChosen-1; i >=0 ; i--)
      {
        if(connectNBoard[pos][i] != playerID)
        {
          break;
        }
        else
        {
          horizontalCount++;
        }
      }
    }
    if(horizontalCount >= numConnect)
    {
      return true;
    }

    // checking if there are player piecies diagonally(upper left to lower right) from pos f
    // this is checking downward positive diagonals
    for(int i = pos, j = columnChosen; i<numRowsInBoard && j < numRowsInBoard; i++, j++)
    {
      if(connectNBoard[i][j]!= playerID)
      {
        break;
      }
      else
      {
        diagonalCount++;
      }
    }
    //this is checking upward diagonal
    if((columnChosen-1 >= 0)&&(pos -1 >=0))
    {
      for(int i = pos-1, j = columnChosen-1; i >= 0 && j >= 0 ; i-- , j-- )
      {
        if(connectNBoard[i][j] != playerID)
        {
          break;
        }
        else{
          diagonalCount++;
        }
      }
    }
    if(diagonalCount >= numConnect){
      return true;
    }




    //checking if there are player piecies diagonally (lower left to upper right) from pos
    //checking upward diagonal

    for(int i = pos, j = columnChosen; i>=0 && j < numRowsInBoard; i--, j++)
    {
      if(connectNBoard[i][j]!= playerID)
      {
        break;
      }
      else
      {
        invdiagonalCount++;
      }
    }


    //this is checking downward diagonal
    if((columnChosen-1 >= 0)&&(pos +1 <= numRowsInBoard))
    {
      for(int i = pos+1, j = columnChosen-1; i < numRowsInBoard && j >= 0 ; i++ , j-- )
      {
        if(connectNBoard[i][j] != playerID)
        {
          break;
        }
        else
        {
          invdiagonalCount++;
        }
      }
    }
    if(invdiagonalCount >= numConnect){
      return true;
    }

  return false;
}
