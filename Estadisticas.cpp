#include "Estadisticas.h"

Estadisticas::Estadisticas()
{
    _contCaballero = 0;
    _contDragon = 0;
}

int Estadisticas::getContCaballero()
{
    return _contCaballero;
}
int Estadisticas::getContDragon()
{
    return _contDragon;
}
void Estadisticas::IncrementarContCaballero()
{
    _contCaballero++;
}
void Estadisticas::IncrementarContDragon()
{
    _contDragon++;

}
