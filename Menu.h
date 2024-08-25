#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "Gameplay.h"
#include "ArchivoEstadistica.h"

class Menu
{
    private:
        // OPCION DE MENU
        int _menuSeleccionado;
        //SPRITE DE FONDO MENU
        sf::Sprite _fondo;
        sf::Texture _texturaFondo;
        //SPRITE DE TITULO DE MENU
        sf::Sprite _titulo;
        sf::Texture _texturaTitulo;
        //SPRITE DE OPCIONES DE MENU
        sf::Sprite _menuOpciones[4];
        sf::Texture _texturaMenuOpciones[4];
        // MOVIMIENTO DEL SPRITE
        float _frame;


    public:
        Menu();

        int menuPresionado();
        void menucorrer(Menu& menu);

        void animarSprite(int cantidadImagenes);
        void moverArriba();
        void moverAbajo();

        void draw(sf::RenderWindow& window);
};

#endif // MENU_H
