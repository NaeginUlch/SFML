#include <SFML/Graphics.hpp>

# pragma once

class MovableDrawable {
public:
    MovableDrawable(const std::string &spritePath, const sf::Vector2f &postion, const sf::Vector2f &scale);
    const float getX();
    const float getY();
    void setX(float x);
    void setY(float y);
    void draw(sf::RenderWindow &window);
    bool doesIntersect(const MovableDrawable &drawable);
private:
    sf::Sprite sprite;
    sf::Texture texture;
};