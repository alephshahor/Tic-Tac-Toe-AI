#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "common.hpp"


class Cell : public sf::Drawable{

  private:

    sf::Texture crossTexture;
    sf::Texture circleTexture;
    sf::Texture freeTexture;
    sf::RectangleShape cellDrawable;
    float cellDimension;
    bool occupied;
    bool crossOccupied;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


    public:

      Cell(float cellDimension, std::pair<int,int> position);
      Cell(float cellDimension, int posX, int posY);


      void occupyCell();
      void crossOccupy();
      void releaseCell();

      void setTexture(texture targetTexture);

      bool isOccupied();
      bool isCrossOccupied();





};
