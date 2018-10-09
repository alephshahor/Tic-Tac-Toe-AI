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

bool Field::checkForWin(){

    int crossCounter = 0;
    int circleCounter = 0;

    // Check for first Diagonal

    for (int y = 0; y < 3; y++){
      if (field[y][y].isOccupied()){
        if (field[y][y].isCrossOccupied())
            crossCounter++;
        else circleCounter++;
      }
    }

    if (circleCounter == 3 || crossCounter == 3) return true;
    crossCounter = circleCounter = 0;

    // Check for second Diagonal

    for (int y = 2; y >= 0; y--){
      if (field[y][2 - y].isOccupied()){
        if (field[y][2 - y].isCrossOccupied())
            crossCounter++;
        else circleCounter++;
      }
    }

    if (circleCounter == 3 || crossCounter == 3) return true;
    crossCounter = circleCounter = 0;


    // Check for horizontals

    for (int y = 0; y < 3; y++){
      for (int x = 0; x < 3; x++){
        if (field[y][x].isOccupied()){
          if (field[y][x].isCrossOccupied())
              crossCounter++;
          else circleCounter++;
      }
    }
        if (circleCounter == 3 || crossCounter == 3) return true;
        crossCounter = circleCounter = 0;
  }



    // Check for verticals


    for (int y = 0; y < 3; y++){
      for (int x = 0; x < 3; x++){
        if (field[x][y].isOccupied()){
          if (field[x][y].isCrossOccupied())
              crossCounter++;
          else circleCounter++;
      }
    }
        if (circleCounter == 3 || crossCounter == 3) return true;
        crossCounter = circleCounter = 0;
  }



    return false;

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
