#ifndef ARENA_H
#define ARENA_H
#include "Colisionable.h"
#include <SFML/Graphics.hpp>

class Arena : public Colisionable
{
    private:
        sf::CircleShape _circunferencia;

    public:
        Arena();

        void setRadio(int radio);
        float getPositionX()const;
        float getPositionY()const;
        float getRadio()const;

        void draw(sf::RenderWindow& window);
};

#endif // ARENA_H
