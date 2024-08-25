#include "Colisionable.h"

bool Colisionable::colisionando(Colisionable &obj) const
{
    float distancia, x, y;

    x = std::abs(getPositionX() - obj.getPositionX());
    y = std::abs(getPositionY() - obj.getPositionY());

    distancia = std::sqrt(x*x + y*y);

    if(getRadio()>= obj.getRadio() && distancia < (getRadio() + obj.getRadio()))return true;
    else if(getRadio() < obj.getRadio() && distancia > obj.getRadio()) return true;
    else return false;
}
