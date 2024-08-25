#ifndef COLISIONABLE_H
#define COLISIONABLE_H
#include <cmath>

class Colisionable
{
    public:
        virtual float getPositionX() const = 0;
        virtual float getPositionY() const = 0;
        virtual float getRadio() const = 0;

        bool colisionando(Colisionable &colisionable) const;
};

#endif // COLISIONABLE_H
