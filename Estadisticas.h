#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H
#include <stdio.h>
#include <cstring>
#include <iostream>

class Estadisticas
{
private:
    int _contCaballero;
    int _contDragon;

public:
    Estadisticas();

    int getContCaballero();
    int getContDragon();

    void IncrementarContCaballero();
    void IncrementarContDragon();
};

#endif // ESTADISTICAS_H
