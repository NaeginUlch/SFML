#include <SFML/Graphics.hpp>
#include "MovableDrawable.hpp"

class Cloud : public MovableDrawable {
public:
    Cloud(const sf::Vector2f &position);
};