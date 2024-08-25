#include "Arena.h"

Arena::Arena()
{
    _circunferencia.setRadius(225);
    _circunferencia.setOrigin(_circunferencia.getGlobalBounds().width/2, _circunferencia.getGlobalBounds().height/2);
    _circunferencia.setPosition(400, 340);
}

void Arena::setRadio(int radio)
{
    _circunferencia.setRadius(radio);
}

float Arena::getPositionX()const
{
    return _circunferencia.getPosition().x;
}
float Arena::getPositionY()const
{
    return _circunferencia.getPosition().y;
}
float Arena::getRadio()const
{
    return _circunferencia.getGlobalBounds().width/2;
}

void Arena::draw(sf::RenderWindow& window)
{
    window.draw(_circunferencia);
}
