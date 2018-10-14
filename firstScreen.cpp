#include "firstScreen.hpp"

int firstScreen::Run(sf::RenderWindow& window){


  bool running = true;

  sf::Texture mainScreenTexture;
  mainScreenTexture.loadFromFile("./art/tictactoeaimainscreen.png");
  sf::RectangleShape mainScreen(sf::Vector2f(480.0f, 480.0f));
  mainScreen.setTexture(&mainScreenTexture);

  while (running){



    sf::Event evnt;
    while(window.pollEvent(evnt)){

      switch(evnt.type){

        case sf::Event::Closed:
             window.close();
             return -1;
             break;
        case sf::Event::MouseButtonPressed:
             if ((evnt.mouseButton.button == sf::Mouse::Left)){
                  int xPos = evnt.mouseButton.x;
                  int yPos = evnt.mouseButton.y;

                 for (int y = 295; y < 330; y++){
                    for (int x = 285; x < 450; x++){

                      if ((xPos == x) && (yPos == y)){
                           aiTurn = false; // Human begins
                           return 1;
                    }

                 }
              }

              for (int y = 365; y < 400; y++){
                 for (int x = 285; x < 450; x++){

                   if ((xPos == x) && (yPos == y)){
                        aiTurn = true; // Ai begins
                        return 1;
                 }

              }
           }

      }

    }
  }

  window.clear();
  window.draw(mainScreen);
  window.display();

  }
}
