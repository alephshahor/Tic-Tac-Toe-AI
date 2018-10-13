#include "circleWinScreen.hpp"


int circleWinScreen::Run(sf::RenderWindow& window){

  std::cout << "Arriving at Circle Screen\n";

  sf::RectangleShape gameScreen(sf::Vector2f(480.0f, 480.0f));
  sf::Texture gameScreenTexture;

  gameScreenTexture.loadFromFile("./art/humanwins.png");
  gameScreen.setTexture(&gameScreenTexture);


  sf::Time delayTime = sf::seconds(3);
  bool running;

    while(running){

    window.clear();
    window.draw(gameScreen);
    window.display();

    sf::sleep(delayTime);

    return -1;

  }

}
