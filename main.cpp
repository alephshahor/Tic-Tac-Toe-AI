#include <SFML/Graphics.hpp>
#include <iostream>
#include "cell.hpp"
#include "field.hpp"

int main(){


  int cellSize = 160;
  int fieldSize = 480;

  bool crossTurn = false;


  Field gameField(fieldSize,fieldSize,cellSize);
      std::cout << "IMhere\n";
  sf::RenderWindow window(sf::VideoMode(fieldSize,fieldSize), "Tic Tac Toe", sf::Style::Close);

  while (true){
    sf::Event evnt;
    while (window.pollEvent(evnt)){
      switch(evnt.type){
        case sf::Event::Closed:
             window.close();
             break;
        case sf::Event::MouseButtonPressed:
              if ((evnt.mouseButton.button == sf::Mouse::Left) && (crossTurn)){
                if(gameField.changeCellState(evnt.mouseButton.x, evnt.mouseButton.y,crossTurn)){
                  if(gameField.checkForWin())
                     std::cout << "Cross wins\n";
                     crossTurn = false;
                  }
            }else{
              if(gameField.changeCellState(evnt.mouseButton.x, evnt.mouseButton.y,crossTurn)){
                   if(gameField.checkForWin())
                      std::cout << "Circle wins\n";
                      crossTurn = true;
                 }
            }
              break;

      }
    }

    window.clear();
    for (int y = 0; y < fieldSize/ cellSize; y++)
      for (int x = 0; x < fieldSize / cellSize; x++)
        window.draw(gameField.getCell(x,y));
    window.display();


  }

}
