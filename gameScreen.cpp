#include "gameScreen.hpp"


int gameScreen::processResult(int result){
      switch(result){
        case -10:
        std::cout << "Circle Wins\n";
        std::cout << "Returning 2\n";
        return 2;
        break;
        case 10:
        std::cout << "Cross Wins\n";
        std::cout << "Returning 3\n";
        return 3;
        break;
        case 0:
        std::cout << "Tie\n";
        return 4;
        break;
        default:
        std::cout << "The game keeps goin on\n";
        return 15;
        break;
      }
}

int gameScreen::Run(sf::RenderWindow& window){


  bool running = true;

  int cellSize = 160;
  int fieldSize = 480;


  std::pair <int,int> calculatedMove = std::make_pair(0,0);


  Field gameField(fieldSize,fieldSize,cellSize);

  if (aiTurn){
    srand(time(NULL));
    int xPosition = rand() % 3 + 0;
    int yPosition = rand() % 3 + 0;

    gameField.changeCellState_(xPosition, yPosition, aiTurn);
    aiTurn = false;
  }

  while (running){
    sf::Event evnt;

    while (window.pollEvent(evnt)){
      switch(evnt.type){
        case sf::Event::Closed:
             window.close();
             return -1;
             break;
        case sf::Event::MouseButtonPressed:
              if ((evnt.mouseButton.button == sf::Mouse::Left)){
              if(gameField.changeCellState(evnt.mouseButton.x, evnt.mouseButton.y, aiTurn)){
                int result = gameField.checkForTerminalState(gameField.getField());
                result = processResult(result);
                std::cout << "Result equals -> " << result;
                if (result != 15)
                    return result;
                else
                    aiTurn = true;


              window.clear();
              for (int y = 0; y < fieldSize/ cellSize; y++)
                for (int x = 0; x < fieldSize / cellSize; x++)
                  window.draw(gameField.getCell(x,y));
              window.display();

                  calculatedMove = gameField.findBestMove(gameField.getField());
                  std::cout << "Should move to (y,x) -> " << calculatedMove.first << " , " << calculatedMove.second << "\n";
                  if(gameField.changeCellState_(calculatedMove.second, calculatedMove.first, aiTurn)){
                    int result = gameField.checkForTerminalState(gameField.getField());
                    result = processResult(result);
                    std::cout << "Result equals -> " << result;
                    if (result != 15)
                      return result;
                    else
                      aiTurn = false;

                  /*window.clear();
                  for (int y = 0; y < fieldSize/ cellSize; y++)
                    for (int x = 0; x < fieldSize / cellSize; x++)
                      window.draw(gameField.getCell(x,y));
                  window.display();*/

                }
              }
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
