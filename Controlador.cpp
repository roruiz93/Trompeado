#include "Controlador.h"

void Controlador::reset()
{
    std::fill(_botones, _botones+5, false);
}

void Controlador::presionar(Botones boton)
{
    _botones[(int)boton] = true;
}

bool Controlador::presionando(Botones boton)
{
    return _botones[(int)boton];
}
