#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Controlador.h"
#include "Trompo.h"
#include "Arena.h"
#include "Nitro.h"
#include "Tiempo.h"


class Gameplay
{
private:
    Arena _arena;
    Arena _arena2;

    Trompo _trompoCaballero;
    Trompo _trompoDragon;
    Tiempo _clock;

    Controlador _controladorPlayer1;
    Controlador _controladorPlayer2;

    Nitro _nitro;
    int _nitroTemporizador;
    bool _nitroPrimerRespawn;
    bool _reinicioRonda;
    int _contCaballeroArena=0;
    int _contDragonArena=0;
    int _contadorCaballero=0;
    int _contadorDragon=0;

    //FONDO
    sf::Sprite _fondo;
    sf::Texture _texturaFondo;

    //NUMERO DE RONDA
    sf::Sprite _numeroRonda;
    sf::Texture _textureRonda;

    //NUMERO DE CORONAS
    sf::Sprite _coronaPlayer1;
    sf::Texture _texturaCorona1;

    sf::Sprite _coronaPlayer2;
    sf::Texture _texturaCorona2;

    //RUIDO DE COLISION
    sf::SoundBuffer _sonido;
    sf::Sound _choque;



public:
    Gameplay();

    void setFondo(int fondo);
    void cambiarFondo();

    void setRonda(int ronda);
    bool flagrondas();
    void setCorona(int jugador, int corona);

    int getContadorDragon();
    int getContadorCaballero();

    void cmd();
    void controladorPlayer1();
    void controladorPlayer2();
    void update();

    void reducirvelocidad();

    void reiniciar();
    void draw(sf::RenderWindow& window);
};

#endif // GAMEPLAY_H
