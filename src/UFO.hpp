#include <SFML/Graphics.hpp>
#include "MovableDrawable.hpp"

# pragma once

class UFO : public MovableDrawable {
public:
    UFO(const sf::Vector2f &position);
};