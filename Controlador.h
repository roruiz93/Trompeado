#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <iostream>

class Controlador
{
    private:
        bool _botones[5];

    public:
        enum class Botones
        {
            Arriba=0,
            Abajo,
            Izquierda,
            Derecha,
            Nitro
        };

        void reset();

        void presionar(Botones boton);
        bool presionando(Botones boton);
};

#endif // CONTROLADOR_H
