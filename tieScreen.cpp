#include "tieScreen.hpp"


int tieScreen::Run(sf::RenderWindow& window){

  sf::RectangleShape gameScreen(sf::Vector2f(480.0f, 480.0f));
  sf::Texture gameScreenTexture;

  gameScreenTexture.loadFromFile("./art/tie.png");
  gameScreen.setTexture(&gameScreenTexture);


  sf::Time delayTime = sf::seconds(3);
  bool running = true;

    while(running){

    window.clear();
    window.draw(gameScreen);
    window.display();

    sf::sleep(delayTime);

    return -1;

  }

}
