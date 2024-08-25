#ifndef NITRO_H
#define NITRO_H
#include <SFML/Graphics.hpp>
#include<stdlib.h>
#include<time.h>
#include "Colisionable.h"

class Nitro : public Colisionable
{
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;

        bool _primerRespawn;

    public:
        Nitro();

        float getPositionX()const;
        float getPositionY()const;
        float getRadio()const;

        void respawn();

        void draw(sf::RenderWindow& window);
};

#endif // NITRO_H
