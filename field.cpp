#include "field.hpp"
#include "common.hpp"


Field::Field(std::pair<int,int> fieldDimension, float cellSize):
       fieldDimension(fieldDimension),
       cellSize(cellSize),
       field(){
         for (int y = 0; y < fieldDimension.first / cellSize; y++){
              std::vector<Cell> vCells;
            for (int x = 0; x < fieldDimension.second / cellSize; x++){
                 vCells.push_back(Cell(cellSize, x * cellSize, y * cellSize));
               }
               field.push_back(vCells);
             }

            for (int y = 0; y < fieldDimension.first / cellSize ; y++)
             for (int x = 0; x < fieldDimension.second / cellSize; x++){
                  texture freeTexture = freeTexture_;
                  field[y][x].setTexture(freeTexture);
                }

       }

Field::Field(int xAxisSize, int yAxisSize, float cellSize){
       fieldDimension.first = xAxisSize;
       fieldDimension.second = yAxisSize;
       this -> cellSize = cellSize;
       for (int y = 0; y < fieldDimension.first / cellSize; y++){
            std::vector<Cell> vCells;
          for (int x = 0; x < fieldDimension.second / cellSize; x++){
               vCells.push_back(Cell(cellSize, x * cellSize, y * cellSize));
             }
             field.push_back(vCells);
           }

          for (int y = 0; y < fieldDimension.first / cellSize; y++)
           for (int x = 0; x < fieldDimension.second / cellSize; x++){
             texture freeTexture = freeTexture_;
             field[y][x].setTexture(freeTexture);
           }

     }


Cell Field::getCell(int posX, int posY){
       return field[posY][posX];
}

std::vector <std::vector <Cell> > Field::getField(){
      return field;
}

int Field::checkForTerminalState(std::vector< std::vector <Cell> > field_){

    int crossCounter = 0;
    int circleCounter = 0;

    // Check for first Diagonal

    for (int y = 0; y < 3; y++){
      if (field_[y][y].isOccupied()){
        if (field_[y][y].isCrossOccupied())
            crossCounter++;
        else circleCounter++;
      }
    }

    if (circleCounter == 3 )
      return -10;
    else if (crossCounter == 3)
      return 10;

    crossCounter = circleCounter = 0;

    // Check for second Diagonal

    for (int y = 2; y >= 0; y--){
      if (field_[y][2 - y].isOccupied()){
        if (field_[y][2 - y].isCrossOccupied())
            crossCounter++;
        else circleCounter++;
      }
    }

    if (circleCounter == 3 )
      return -10;
    else if (crossCounter == 3)
      return 10;
    crossCounter = circleCounter = 0;


    // Check for horizontals

    for (int y = 0; y < 3; y++){
      for (int x = 0; x < 3; x++){
        if (field_[y][x].isOccupied()){
          if (field_[y][x].isCrossOccupied())
              crossCounter++;
          else circleCounter++;
      }
    }

    if (circleCounter == 3 )
      return -10;
    else if (crossCounter == 3)
      return 10;
        crossCounter = circleCounter = 0;
  }



    // Check for verticals


    for (int y = 0; y < 3; y++){
      for (int x = 0; x < 3; x++){
        if (field_[x][y].isOccupied()){
          if (field_[x][y].isCrossOccupied())
              crossCounter++;
          else circleCounter++;
      }
    }

    if (circleCounter == 3 )
      return -10;
    else if (crossCounter == 3)
      return 10;
        crossCounter = circleCounter = 0;
  }



  // Check for full board
  int fullboardCounter = 0;

  for (int y = 0; y < 3; y++){
    for (int x = 0; x < 3; x++){
      if (field_[x][y].isOccupied()){
          fullboardCounter++;
      }
    }
  }


  if (fullboardCounter == 9)
      return 0;

  return 3;

}



 std::pair<int,int> Field::findBestMove(std::vector < std::vector <Cell> > currentBoard){


   std::pair <int,int> bestMove;
   int bestResult = -99999;

   for (int y = 0; y < 3; y++){
     for (int x = 0; x < 3; x++){
       std::vector < std::vector <Cell> > currentBoard_ = currentBoard;
       if (!currentBoard[y][x].isOccupied()){
          currentBoard_[y][x].occupyCell();
          currentBoard_[y][x].crossOccupy();
          int result = minimax(currentBoard_, 0, false);
          std::cout << "RESULT --> " << result << "\n";
          if (result > bestResult){
            bestResult = result;
            bestMove = std::make_pair(y,x);
          }
        }
       }
     }

  return bestMove;


 }

int Field::minimax (std::vector < std::vector <Cell> > currentBoard, int depth, bool isMaximizingPlayer){


    if (depth < 3){

    int boardState = checkForTerminalState(currentBoard);
    if (boardState != 3){
     /*std::cout << "TERMINAL STATE RESULT: " << boardState << " in depth -> " << depth;
      if (isMaximizingPlayer)
           std::cout << " Maximizing\n";
      else std::cout << " Minimizing\n";*/
      if(boardState == -10)
         return boardState + depth;
      else if (boardState == 10)
         return boardState - depth;
      else if (boardState == 0)
          return boardState;
    }

    if (isMaximizingPlayer){
       int bestValue = -99999;
       for (int y = 0; y < 3; y++){
         for (int x = 0; x < 3; x++){
           std::vector < std::vector <Cell> > currentBoard_ = currentBoard;
           if (!currentBoard[y][x].isOccupied()){
              currentBoard_[y][x].crossOccupy();
              int value = minimax(currentBoard_, depth + 1, false);
            //  if (value != 0)
              //    std::cout << "IN MAX THE VALUE IS -> " << value << "\n";
              bestValue = std::max(value, bestValue);
           }
         }
       }

       return bestValue;

    }else{
      int bestValue = 99999;
      for (int y = 0; y < 3; y++){
        for (int x = 0; x < 3; x++){
          std::vector < std::vector <Cell> > currentBoard_ = currentBoard;
          if (!currentBoard[y][x].isOccupied()){
             currentBoard_[y][x].occupyCell();
             int value = minimax(currentBoard_, depth + 1, true);
          //   if (value != 0)
            //     std::cout << "IN MIN THE VALUE IS -> " << value << "\n";
             bestValue = std::min(value, bestValue);
          }
        }
      }
      return bestValue;

    }
  } else return 0;


 }

// If it changes returns true, in the negative case it was occupied
// so the player needs to select other cell

bool Field::changeCellState(int posX, int posY, bool crossTurn){

      posX /= cellSize;
      posY /= cellSize;

      std::cout << "PosX -> " << posX << " PosY -> " << posY << "\n";



      if(field[posY][posX].isOccupied())
         return false;
      else{
        if (crossTurn){
          texture crossTexture = crossTexture_;
          field[posY][posX].setTexture(crossTexture);
          field[posY][posX].occupyCell();
          field[posY][posX].crossOccupy();
        }else{
          texture circleTexture = circleTexture_;
          field[posY][posX].setTexture(circleTexture);
          field[posY][posX].occupyCell();
        }
      }


      return true;
}

bool Field::changeCellState_(int posX, int posY, bool crossTurn){

      if(field[posY][posX].isOccupied())
         return false;
      else{
        if (crossTurn){
          texture crossTexture = crossTexture_;
          field[posY][posX].setTexture(crossTexture);
          field[posY][posX].occupyCell();
          field[posY][posX].crossOccupy();
        }else{
          texture circleTexture = circleTexture_;
          field[posY][posX].setTexture(circleTexture);
          field[posY][posX].occupyCell();
        }
      }


      return true;
}
