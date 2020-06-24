#include "MovableDrawable.hpp"

MovableDrawable::MovableDrawable(const std::string &spritePath, const sf::Vector2f &position, const sf::Vector2f &scale): sprite(), texture() {
    if (!this->texture.loadFromFile(spritePath)) {
        throw std::runtime_error("Can't load asset \"" + spritePath + "\"");
    }
    this->sprite = sf::Sprite(this->texture);
    auto bounds = this->sprite.getGlobalBounds();
    this->sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    this->sprite.setScale(scale);
    this->sprite.setPosition(position);
}

const float MovableDrawable::getX() {
    return this->sprite.getPosition().x;
}

const float MovableDrawable::getY() {
    return this->sprite.getPosition().y;
}

void MovableDrawable::setX(float x) {
    this->sprite.setPosition(x, this->sprite.getPosition().y);
}

void MovableDrawable::setY(float y) {
 this->sprite.setPosition(this->sprite.getPosition().x, y);
}

bool MovableDrawable::doesIntersect(const MovableDrawable &drawable) {
    auto a = this->sprite.getGlobalBounds();
    auto b = drawable.sprite.getGlobalBounds();
    return a.intersects(b);
}

void MovableDrawable::draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
}
