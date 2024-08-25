#include "Nitro.h"

Nitro::Nitro()
{
    _texture.loadFromFile("sprites/nitro.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);

    _primerRespawn = true;
}

float Nitro::getPositionX()const
{
    return _sprite.getPosition().x;
}
float Nitro::getPositionY()const
{
    return _sprite.getPosition().y;
}
float Nitro::getRadio()const
{
    return _sprite.getGlobalBounds().width/2;
}

void Nitro::respawn()
{
    srand(time(NULL));
    int posicionNitro;

    if(_primerRespawn == true)
    {
        posicionNitro = 1+rand()%(3-1);
        switch(posicionNitro)
        {
        case 1:
            _sprite.setPosition(400, 240);
            _primerRespawn = false;
            break;
        case 2:
            _sprite.setPosition(400, 440);
            _primerRespawn = false;
            break;
        }
    }
    else
    {
        posicionNitro = 1+rand()%(5-1);
        switch(posicionNitro)
        {
        case 1:
            _sprite.setPosition(400, 240);
            break;
        case 2:
            _sprite.setPosition(400, 440);
            break;
        case 3:
            _sprite.setPosition(300, 340);
            break;
        case 4:
            _sprite.setPosition(500, 340);
            break;
        }
    }
}

void Nitro::draw(sf::RenderWindow& window)
{
    window.draw(_sprite);
}
