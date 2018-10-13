#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cell.hpp"
#include "field.hpp"
#include "turn.hpp"
#include "cScreen.hpp"


// Screen nº 0
class firstScreen : public cScreen {

public:
    virtual int Run(sf::RenderWindow& window);

};
