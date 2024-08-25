#ifndef ARCHIVOESTADISTICA_H
#define ARCHIVOESTADISTICA_H
#include "Estadisticas.h"


class ArchivoEstadistica
{
private:
    char _nombre[30];

public:
    ArchivoEstadistica();
    Estadisticas leerRegistro();
    int cambiarContador(Estadisticas reg, int );
    int verificarArchivoCreado(Estadisticas reg);
};
#endif // ARCHIVOESTADISTICA_H
