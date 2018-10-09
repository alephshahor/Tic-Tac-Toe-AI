#include "cell.hpp"

Cell::Cell(float cellDimension, std::pair<int,int> position):
  cellDimension(cellDimension),
  occupied(false),
  crossOccupied(false)
  {
    crossTexture.loadFromFile("cross.png");
    circleTexture.loadFromFile("circle.png");
    freeTexture.loadFromFile("white.png");

    cellDrawable.setSize(sf::Vector2f(cellDimension,cellDimension));
    cellDrawable.setPosition(position.first, position.second);
  }

 Cell::Cell(float cellDimension, int posX, int posY):
    cellDimension(cellDimension),
    occupied(false),
    crossOccupied(false)
    {
      crossTexture.loadFromFile("cross.png");
      circleTexture.loadFromFile("circle.png");
      freeTexture.loadFromFile("white.png");

      cellDrawable.setSize(sf::Vector2f(cellDimension,cellDimension));
      cellDrawable.setPosition(posX, posY);
    }



void Cell::setTexture(texture targetTexture){

     switch(targetTexture){

       case 0:
       cellDrawable.setTexture(&freeTexture);
       break;

       case 1:
       cellDrawable.setTexture(&crossTexture);
       break;

       case 2:
       cellDrawable.setTexture(&circleTexture);
       break;

     }

}

void Cell::occupyCell(){
    occupied = true;
}

void Cell::crossOccupy(){
    crossOccupied = true;
}

void Cell::releaseCell(){
   occupied = false;
}

bool Cell::isOccupied(){
   return occupied;
}

bool Cell::isCrossOccupied(){
    return crossOccupied;
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const{
  target.draw(cellDrawable);
}
