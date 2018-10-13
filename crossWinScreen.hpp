#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cell.hpp"
#include "field.hpp"
#include "cScreen.hpp"


// Screen nº 3
class crossWinScreen : public cScreen {

  public:
    virtual int Run(sf::RenderWindow& window);

};
