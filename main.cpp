#include <SFML/Graphics.hpp>
#include <iostream>
#include "cell.hpp"
#include "field.hpp"

int main(){


  int cellSize = 160;
  int fieldSize = 480;

  bool crossTurn = true;


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
              if ((evnt.mouseButton.button == sf::Mouse::Left) && (crossTurn)){ // Cross turn
                if(gameField.changeCellState(evnt.mouseButton.x, evnt.mouseButton.y,crossTurn)){
                  int result = gameField.checkForTerminalState(gameField.getField());
                  switch(result){
                    case -10:
                    std::cout << "Circle Wins\n";
                    return false;
                    break;
                    case 10:
                    std::cout << "Cross Wins\n";
                    return false;
                    break;
                    case 0:
                    std::cout << "Tie\n";
                    return false;
                    break;
                    case 3:
                    std::cout << "The game keeps goin on\n";
                    crossTurn = false;
                    break;
                  }

                  }



            }else{
              if(gameField.changeCellState(evnt.mouseButton.x, evnt.mouseButton.y,crossTurn)){
                int result = gameField.checkForTerminalState(gameField.getField());
                switch(result){
                  case -10:
                  std::cout << "Circle Wins\n";
                  return false;
                  break;
                  case 10:
                  std::cout << "Cross Wins\n";
                  return false;
                  break;
                  case 0:
                  std::cout << "Tie\n";
                  return false;
                  break;
                  default:
                  std::cout << "The game keeps goin on\n";
                  crossTurn = true;
                  break;
                }
              }
              std::pair <int,int> calculatedMove = gameField.findBestMove(gameField.getField());
              std::cout << "Should move to (y,x) -> " << calculatedMove.first << " , " << calculatedMove.second << "\n";
            }

      }
    }

    window.clear();
    for (int y = 0; y < fieldSize/ cellSize; y++)
      for (int x = 0; x < fieldSize / cellSize; x++)
        window.draw(gameField.getCell(x,y));
    window.display();


  }

}
