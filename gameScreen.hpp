#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "cell.hpp"
#include "field.hpp"
#include "turn.hpp"
#include "cScreen.hpp"

// Screen nº 1
class gameScreen : public cScreen{


public:
    virtual int Run(sf::RenderWindow& window);
    int processResult(int result);

};
