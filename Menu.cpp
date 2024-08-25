#include "Menu.h"


Menu::Menu()
{
    _texturaFondo.loadFromFile("sprites/fondoMenu.png");
    _fondo.setTexture(_texturaFondo);

    _texturaTitulo.loadFromFile("sprites/trompeandoMenu.png");
    _titulo.setTexture(_texturaTitulo);
    _titulo.setPosition(25, 50);

    _texturaMenuOpciones[0].loadFromFile("sprites/jugarPartidaMenu.png");
    _menuOpciones[0].setTexture(_texturaMenuOpciones[0]);
    _menuOpciones[0].setTextureRect({0,0,356,42});
    _menuOpciones[0].setPosition(222, 268);

    _texturaMenuOpciones[1].loadFromFile("sprites/estadisticasMenu.png");
    _menuOpciones[1].setTexture(_texturaMenuOpciones[1]);
    _menuOpciones[1].setTextureRect({0,0,288,44});
    _menuOpciones[1].setPosition(256, 337);

    _texturaMenuOpciones[2].loadFromFile("sprites/creditosMenu.png");
    _menuOpciones[2].setTexture(_texturaMenuOpciones[2]);
    _menuOpciones[2].setTextureRect({0,0,220,44});
    _menuOpciones[2].setPosition(290, 408);

    _texturaMenuOpciones[3].loadFromFile("sprites/salirMenu.png");
    _menuOpciones[3].setTexture(_texturaMenuOpciones[3]);
    _menuOpciones[3].setTextureRect({0,0,128,44});
    _menuOpciones[3].setPosition(336, 479);

    _menuSeleccionado = 0;

    _frame = 0;
}


int Menu::menuPresionado()
{
    return _menuSeleccionado;
}

void Menu::menucorrer(Menu& menu)
{


    sf::RenderWindow menuPrincipal(sf::VideoMode(800, 600), "Menu");
    menuPrincipal.setFramerateLimit(60);
    int flagronda=1;
    Estadisticas estadisticasGanadores;
    ArchivoEstadistica archivoEstadistica;
    sf::Music _tema;
     _tema.openFromFile("sonidos/cancion.wav");
     _tema.play();
     _tema.setVolume(07);
     _tema.setLoop(true);
    while (menuPrincipal.isOpen())
    {
        sf::Event event;
        while (menuPrincipal.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)menuPrincipal.close();
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Up)
                {
                    menu.moverArriba();
                    break;
                }
                if(event.key.code == sf::Keyboard::Down)
                {
                    menu.moverAbajo();
                    break;
                }
                if(event.key.code == sf::Keyboard::Enter)
                {
                    sf::RenderWindow jugarPartida(sf::VideoMode(800, 600), "TROMPEANDO");
                    jugarPartida.setFramerateLimit(60);
                    sf::RenderWindow estadisticas(sf::VideoMode(800, 600), "ESTADISTICAS");
                    sf::RenderWindow creditos(sf::VideoMode(800, 600), "CREDITOS");

                    int x = menu.menuPresionado();

                    if(x==0)
                    {
                         flagronda=1;
                        menuPrincipal.setVisible(false);
                        estadisticas.close();
                        creditos.close();
                        Gameplay gm;
                        while(jugarPartida.isOpen()&& flagronda<4)
                        {
                            sf::Event aevent;

                                if(gm.flagrondas())
                                {
                                    std::cout<<flagronda<<std::endl;

                                    if(flagronda==2 && gm.getContadorCaballero()==2 && gm.getContadorDragon()==2)
                                    {
                                        flagronda=4;
                                        std::cout<<"EMPATA"<<std::endl;
                                        if(archivoEstadistica.verificarArchivoCreado(estadisticasGanadores) >= 0)
                                        {
                                            estadisticasGanadores = archivoEstadistica.leerRegistro();
                                            archivoEstadistica.cambiarContador(estadisticasGanadores,1);
                                            archivoEstadistica.cambiarContador(estadisticasGanadores,2);
                                        }

                                        jugarPartida.close();
                                        menuPrincipal.setVisible(true);

                                    }
                                    else if(flagronda==2 && gm.getContadorCaballero()>gm.getContadorDragon())
                                    {
                                        flagronda=4;
                                        std::cout<<"GANA CABALLERO"<<std::endl;
                                        if(archivoEstadistica.verificarArchivoCreado(estadisticasGanadores) >= 0)
                                        {
                                            estadisticasGanadores = archivoEstadistica.leerRegistro();
                                            archivoEstadistica.cambiarContador(estadisticasGanadores,1);
                                        }

                                        jugarPartida.close();
                                        menuPrincipal.setVisible(true);
                                    }
                                    else if(flagronda==2 && gm.getContadorDragon()>gm.getContadorCaballero())
                                    {
                                        flagronda=4;
                                        std::cout<<"GANA DRAGON"<<std::endl;
                                        if(archivoEstadistica.verificarArchivoCreado(estadisticasGanadores) >= 0)
                                        {
                                            estadisticasGanadores = archivoEstadistica.leerRegistro();
                                            archivoEstadistica.cambiarContador(estadisticasGanadores,2);
                                        }

                                        jugarPartida.close();
                                        menuPrincipal.setVisible(true);
                                    }

                                    if(flagronda==3 && gm.getContadorCaballero()>gm.getContadorDragon())
                                    {
                                        flagronda=4;
                                        std::cout<<"GANA CABALLERO"<<std::endl;
                                        if(archivoEstadistica.verificarArchivoCreado(estadisticasGanadores) >= 0)
                                        {
                                            estadisticasGanadores = archivoEstadistica.leerRegistro();
                                            archivoEstadistica.cambiarContador(estadisticasGanadores,1);
                                        }

                                        jugarPartida.close();
                                        menuPrincipal.setVisible(true);
                                    }
                                    else if(flagronda==3 && gm.getContadorCaballero()<gm.getContadorDragon())
                                    {
                                        flagronda=4;
                                        std::cout<<"GANA DRAGON"<<std::endl;
                                        if(archivoEstadistica.verificarArchivoCreado(estadisticasGanadores) >= 0)
                                        {
                                            estadisticasGanadores = archivoEstadistica.leerRegistro();
                                            archivoEstadistica.cambiarContador(estadisticasGanadores,2);
                                        }

                                        jugarPartida.close();
                                        menuPrincipal.setVisible(true);
                                    }
                                    flagronda++;
                                    gm.setRonda(flagronda);
                                }

                            while(jugarPartida.pollEvent(aevent))
                            {
                                if(aevent.type == sf::Event::Closed)
                                {
                                    jugarPartida.close();
                                    menuPrincipal.setVisible(true);
                                }
                                if(aevent.type == sf::Event::KeyReleased)
                                {
                                    if(aevent.key.code == sf::Keyboard::Escape)
                                    {
                                        jugarPartida.close();
                                        menuPrincipal.setVisible(true);
                                    }
                                }
                            }
                            gm.cmd();
                            gm.update();

                            jugarPartida.clear();

                            gm.draw(jugarPartida);
                            jugarPartida.display();
                        }
                    }

                    if(x==1)
                    {
                        jugarPartida.close();
                        creditos.close();
                        menuPrincipal.setVisible(false);

                        sf::Sprite _fondoEstadisticas;
                        sf::Texture _texturaFondoEstadistica;
                        _texturaFondoEstadistica.loadFromFile("sprites/fondoEstadisticas.png");
                        _fondoEstadisticas.setTexture(_texturaFondoEstadistica);

                        sf::Text _textoCaballero;
                        sf::Font _fuenteCaballero;
                        _fuenteCaballero.loadFromFile("fuentes/Lady Radical.ttf");
                        _textoCaballero.setFont(_fuenteCaballero);
                        _textoCaballero.setPosition(575,400);
                        _textoCaballero.setCharacterSize(85);
                        _textoCaballero.setFillColor(sf::Color::Green);

                        sf::Text _textoDragon;
                        sf::Font _fuenteDragon;
                        _fuenteDragon.loadFromFile("fuentes/Lady Radical.ttf");
                        _textoDragon.setFont(_fuenteDragon);
                        _textoDragon.setPosition(165,400);
                        _textoDragon.setCharacterSize(85);
                        _textoDragon.setFillColor(sf::Color::Green);

                        if(archivoEstadistica.verificarArchivoCreado(estadisticasGanadores) >= 0)
                        {
                            estadisticasGanadores = archivoEstadistica.leerRegistro();
                        }

                        while(estadisticas.isOpen())
                        {
                            sf::Event aevent;
                            while(estadisticas.pollEvent(aevent))
                            {
                                if(aevent.type == sf::Event::Closed)
                                {
                                    estadisticas.close();
                                    menuPrincipal.setVisible(true);
                                }
                                if(aevent.type == sf::Event::KeyReleased)
                                {
                                    if(aevent.key.code == sf::Keyboard::Escape)
                                    {
                                        estadisticas.close();
                                        menuPrincipal.setVisible(true);
                                    }
                                }
                            }
                            _textoCaballero.setString(std::to_string(estadisticasGanadores.getContCaballero()));
                            _textoDragon.setString(std::to_string(estadisticasGanadores.getContDragon()));

                            estadisticas.clear();
                            estadisticas.draw(_fondoEstadisticas);
                            estadisticas.draw(_textoCaballero);
                            estadisticas.draw(_textoDragon);
                            estadisticas.display();
                        }
                    }
                    if(x==2)
                    {
                        sf::Sprite _fondo;
                        sf::Texture _texturaFondo;
                        _texturaFondo.loadFromFile("sprites/creditos.png");
                        _fondo.setTexture(_texturaFondo);

                        jugarPartida.close();
                        estadisticas.close();
                        menuPrincipal.setVisible(false);
                        while(creditos.isOpen())
                        {
                            sf::Event aevent;
                            while(creditos.pollEvent(aevent))
                            {
                                if(aevent.type == sf::Event::Closed)
                                {
                                    creditos.close();
                                    menuPrincipal.setVisible(true);
                                }
                                if(aevent.type == sf::Event::KeyReleased)
                                {
                                    if(aevent.key.code == sf::Keyboard::Escape)
                                    {
                                        creditos.close();
                                        menuPrincipal.setVisible(true);
                                    }
                                }
                            }
                            creditos.clear();
                            creditos.draw(_fondo);
                            creditos.display();
                        }
                    }
                    if(x==3)
                    {
                        menuPrincipal.close();
                        break;
                    }
                }
            }
        }
        menu.animarSprite(2);

        menuPrincipal.clear();
        menu.draw(menuPrincipal);
        menuPrincipal.display();
    }
}

void Menu::animarSprite(int cantidadImagenes)
{
    if(_menuSeleccionado >= 0 && _menuSeleccionado <=4)
    {
        _frame += 0.1f;

        if(_frame >= cantidadImagenes)
        {
            _frame=0;
        }

        sf::IntRect rectangulo(0 + int(_frame) * (_menuOpciones[_menuSeleccionado].getTexture()->getSize().x/cantidadImagenes),0,_menuOpciones[_menuSeleccionado].getTexture()->getSize().x/cantidadImagenes,_menuOpciones[_menuSeleccionado].getTexture()->getSize().y);
        _menuOpciones[_menuSeleccionado].setTextureRect(rectangulo);
    }
}

void Menu::moverArriba()
{
    if(_menuSeleccionado - 1 >= -1)
    {
        _menuSeleccionado--;

        if(_menuSeleccionado == -1) _menuSeleccionado = 3;

    }
}

void Menu::moverAbajo()
{
    if(_menuSeleccionado + 1 <= 4)
    {
        _menuSeleccionado++;

        if(_menuSeleccionado == 4) _menuSeleccionado = 0;

    }
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(_fondo);
    window.draw(_titulo);
    for(int i=0; i<4; i++)
    {
        window.draw(_menuOpciones[i]);
    }
}
