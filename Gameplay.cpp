#include "Gameplay.h"

Gameplay::Gameplay()
{
    _trompoCaballero.setSprite("sprites/trompo1.png");
    _trompoCaballero.setPosition(220, 340);
    _trompoCaballero.setVelocidad(5);
    _trompoCaballero.setEscudo();
    _trompoCaballero.setVelocidadEscudo("sprites/velocidadEscudo1.png");
    _trompoCaballero.setPositionVelocidadEscudo(10, 10);
    _trompoCaballero.setPositionNitroEstado(280,50);

    _trompoDragon.setSprite("sprites/trompo2.png");
    _trompoDragon.setPosition(580, 340);
    _trompoDragon.setVelocidad(5);
    _trompoDragon.setEscudo();
    _trompoDragon.setVelocidadEscudo("sprites/velocidadEscudo2.png");
    _trompoDragon.setPositionVelocidadEscudo(515, 10);
    _trompoDragon.setPositionNitroEstado(490,50);

    setCorona(1,1);
    setCorona(2,1);

    _nitroTemporizador = 0;
    _nitroPrimerRespawn = true;

    _reinicioRonda=false;

    _arena2.setRadio(112.5);

    _sonido.loadFromFile("sonidos/choque2.wav");
    _choque.setBuffer(_sonido);

    setFondo(1);
    setRonda(1);
}
//SETEA EL FONDO DE LA PANTALLA
void Gameplay::setFondo(int fondo)
{
    _texturaFondo.loadFromFile("sprites/fondo.png");
    _fondo.setTexture(_texturaFondo);
    switch(fondo)
    {
    case 1:
        _fondo.setTextureRect({0,0,800,600});
        break;
    case 2:
        _fondo.setTextureRect({800,0,800,600});
        break;
    case 3:
        _fondo.setTextureRect({1600,0,800,600});
        break;
    }
}
//CAMBIA EL FONDO DEPENDIENDO DEL TIEMPO
void Gameplay::cambiarFondo()
{
    int aux=0;
    aux=_clock.retornarTiempoTranscurrido();
    if(aux>=16 && aux<=30)
    {
        setFondo(2);
    }
    if(aux>=0 && aux<=15)
    {
        setFondo(3);
    }
}
//SETEA EL NUMERO DE RONDA
void Gameplay::setRonda(int ronda)
{

    _numeroRonda.setPosition(358, 90);
    _textureRonda.loadFromFile("sprites/rondas.png");
    _numeroRonda.setTexture(_textureRonda);

    switch(ronda)
    {
    case 1:
        _numeroRonda.setTextureRect({0,0,94,18});
        break;
    case 2:
        _numeroRonda.setTextureRect({94,0,94,18});
        break;
    case 3:
        _numeroRonda.setTextureRect({188,0,94,18});
        break;
    }
}
//CAMBIO DE RONDA
bool Gameplay::flagrondas()
{

    if(_reinicioRonda==true)
    {
        reiniciar();
        _reinicioRonda=false;
        return true;
    }
    else
    {
        return false;
    }
}
//SETEA LAS CORONAS DE CADA JUGADOR
void Gameplay::setCorona(int jugador, int corona)
{
    _coronaPlayer1.setPosition(100,100);
    _texturaCorona1.loadFromFile("sprites/rondasGanadas1.png");
    _coronaPlayer1.setTexture(_texturaCorona1);

    _coronaPlayer2.setPosition(637,100);
    _texturaCorona2.loadFromFile("sprites/rondasGanadas2.png");
    _coronaPlayer2.setTexture(_texturaCorona2);

    switch(corona)
    {
    case 1:
        if(jugador == 1)
        {
            _coronaPlayer1.setTextureRect({0,0,63,24});
        }
        else
        {
            _coronaPlayer2.setTextureRect({0,0,63,24});
        }
        break;
    case 2:
        if(jugador == 1)
        {
            _coronaPlayer1.setTextureRect({63,0,63,24});
        }
        else
        {
            _coronaPlayer2.setTextureRect({63,0,63,24});
        }
        break;
    case 3:
        if(jugador == 1)
        {
            _coronaPlayer1.setTextureRect({126,0,63,24});
        }
        else
        {
            _coronaPlayer2.setTextureRect({126,0,63,24});
        }
        break;
    }
}
//DEVUELVE EL PUNTAJE DEL  DRAGON
int Gameplay::getContadorDragon()
{
    return _contadorDragon;
}
//DEVUELVE EL PUNTAJE DEL CABALLERO
int Gameplay::getContadorCaballero()
{
    return _contadorCaballero;
}
//CONSOLA DE COMANDOS
void Gameplay::cmd()
{
    _controladorPlayer1.reset();
    _controladorPlayer2.reset();

    controladorPlayer1();
    controladorPlayer2();

    _trompoDragon.cmd(_controladorPlayer2);
    _trompoCaballero.cmd(_controladorPlayer1);
}
//CONTROLADOR DEL PLAYER 1
void Gameplay::controladorPlayer1()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _controladorPlayer1.presionar(Controlador::Botones::Arriba);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _controladorPlayer1.presionar(Controlador::Botones::Abajo);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _controladorPlayer1.presionar(Controlador::Botones::Derecha);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _controladorPlayer1.presionar(Controlador::Botones::Izquierda);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        _controladorPlayer1.presionar(Controlador::Botones::Nitro);
    }
}
//CONTROLADOR DEL PLAYER 2
void Gameplay::controladorPlayer2()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _controladorPlayer2.presionar(Controlador::Botones::Arriba);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _controladorPlayer2.presionar(Controlador::Botones::Abajo);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _controladorPlayer2.presionar(Controlador::Botones::Derecha);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        _controladorPlayer2.presionar(Controlador::Botones::Izquierda);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
    {
        _controladorPlayer2.presionar(Controlador::Botones::Nitro);
    }
}
//DESARROLLO DE JUEGO/ACTUALIZACION DE ESTADO DEL JUEGO
void Gameplay::update()
{
    reducirvelocidad();
    cambiarFondo();


    if(_nitroTemporizador > 0)
    {
        _nitroTemporizador--;
    }

    if(_nitroPrimerRespawn == true)
    {
        _nitro.respawn();
        _nitroPrimerRespawn = false;
    }
    _trompoCaballero.update();
    _trompoDragon.update();
    //TROMPO 1 CON ARENA GRANDE
    if(_trompoCaballero.colisionando(_arena))
    {
        _trompoCaballero.setPosition(-100, -100);
        _trompoCaballero.disminuirEscudo(true);
        _contadorDragon++;

        _reinicioRonda=true;
        setCorona(2,_contadorDragon+1);
    }
    //TROMPO 1 CON ARENA2 DE FUEGO
    if(!_trompoCaballero.colisionando(_arena))
    {
        if(_trompoCaballero.colisionando(_arena2) && _clock.retornarTiempoTranscurrido()<=15)
        {
            _contCaballeroArena++;
            std::cout<<_contCaballeroArena<<std::endl;
            if(_contCaballeroArena==120)
            {
                if(_trompoCaballero.getEscudo()>0)
                {
                    _trompoCaballero.disminuirEscudo();
                    _contCaballeroArena=0;
                }
            }
        }

    }

    //TROMPO 2 CON ARENA
    if(_trompoDragon.colisionando(_arena))
    {
        _trompoDragon.setPosition(-100, -100);
        _trompoDragon.disminuirEscudo(true);
        _contadorCaballero++;
        _reinicioRonda=true;
        setCorona(1,_contadorCaballero+1);
    }

    //TROMPO 2 CON ARENA2 DE FUEGO
    if(!_trompoDragon.colisionando(_arena))
    {

        if(_trompoDragon.colisionando(_arena2) && _clock.retornarTiempoTranscurrido()<=15)
        {
            _contDragonArena++;
            if(_contDragonArena==120)
            {
                if(_trompoDragon.getEscudo()>0)
                {
                    _trompoDragon.disminuirEscudo();
                    _contDragonArena=0;
                }
            }

        }
    }

    //COLISIONES ENTRE CABALLERO Y DRAGON
    if(_trompoCaballero.colisionando(_trompoDragon) && _trompoCaballero.getNitroUsado() == true)
    {
        _choque.play();
        _trompoDragon.disminuirEscudo();
        _trompoCaballero.setNitroUsado();
        if(_trompoDragon.getEscudo()<=0)
        {
            _trompoDragon.Rebotar(_trompoCaballero.getDireccion());
            _trompoDragon.Rebotar(_trompoCaballero.getDireccion());
            _contadorCaballero++;
            _reinicioRonda=true;
            setCorona(1,_contadorCaballero+1);
        }

    }
    else if(_trompoCaballero.colisionando(_trompoDragon) && _trompoCaballero.getNitroUsado() == false)
    {
        _choque.play();
        _trompoCaballero.Rebotar(_trompoDragon.getDireccion());
        _trompoDragon.Rebotar(_trompoCaballero.getDireccion());
    }

    //COLISIONES ENTRE DRAGON Y CABALLERO
    if(_trompoDragon.colisionando(_trompoCaballero) && _trompoDragon.getNitroUsado() == true)
    {
        _choque.play();
        _trompoCaballero.disminuirEscudo();
        _trompoDragon.setNitroUsado();
        if(_trompoCaballero.getEscudo()<=0)
        {
            _trompoDragon.Rebotar(_trompoCaballero.getDireccion());
            _trompoDragon.Rebotar(_trompoCaballero.getDireccion());
            _contadorDragon++;
            _reinicioRonda=true;
            setCorona(2,_contadorDragon+1);
        }
    }
    else if(_trompoCaballero.colisionando(_trompoDragon) && _trompoCaballero.getNitroUsado() == false)//COLISIONES DEL CABALLERO CON DRAGON CON NITRO
    {
        _choque.play();
        _trompoCaballero.Rebotar(_trompoDragon.getDireccion());
        _trompoDragon.Rebotar(_trompoCaballero.getDireccion());
    }
    if(_nitroTemporizador == 0 && _trompoCaballero.colisionando(_nitro))//RENOVACION DEL NITRO EN CABALLERO
    {
        _nitroTemporizador = 60*3;
        _nitro.respawn();
        _trompoCaballero.setNitroUsable();
    }
    if(_nitroTemporizador == 0 && _trompoDragon.colisionando(_nitro))//RENOVACION DEL NITRO DEL DRAGON
    {
        _nitroTemporizador = 60*3;
        _nitro.respawn();
        _trompoDragon.setNitroUsable();
    }
}
//REDUCE VELOCIDAD DE TROMPO X TIEMPO
void Gameplay::reducirvelocidad()
{
    if(_clock.retornarTiempoTranscurrido()<38 && _clock.retornarTiempoTranscurrido()>=31)
    {
        _trompoCaballero.setVelocidad(4);
        _trompoDragon.setVelocidad(4);
    }
    if(_clock.retornarTiempoTranscurrido()<31 && _clock.retornarTiempoTranscurrido()>=24)
    {
        _trompoCaballero.setVelocidad(3);
        _trompoDragon.setVelocidad(3);

    }
    if(_clock.retornarTiempoTranscurrido()<24 && _clock.retornarTiempoTranscurrido()>=10)
    {
        _trompoCaballero.setVelocidad(2);
        _trompoDragon.setVelocidad(2);

    }
    if(_clock.retornarTiempoTranscurrido()<10 && _clock.retornarTiempoTranscurrido()>0)
    {
        _trompoCaballero.setVelocidad(1);
        _trompoDragon.setVelocidad(1);

    }
    else if(_clock.retornarTiempoTranscurrido()==0)
    {

        _trompoCaballero.setVelocidad(0);
        _trompoDragon.setVelocidad(0);


        if(_trompoCaballero.getEscudo()>_trompoDragon.getEscudo())
        {
            _contadorCaballero++;
            setCorona(1,_contadorCaballero+1);
        }
        else if(_trompoCaballero.getEscudo()<_trompoDragon.getEscudo())
        {
            _contadorDragon++;
            setCorona(2,_contadorDragon+1);
        }
        else if(_trompoCaballero.getEscudo()==_trompoDragon.getEscudo())
        {
            _contadorDragon++;
            _contadorCaballero++;
            setCorona(1,_contadorCaballero+1);
            setCorona(2,_contadorDragon+1);
        }
        _reinicioRonda=true;
    }
}
//REINICIO DEL JUEGO
void Gameplay::reiniciar()
{

    setFondo(1);
    _trompoCaballero.setEscudo();
    _trompoDragon.setEscudo();
    _trompoCaballero.setVelocidad(5);
    _trompoDragon.setVelocidad(5);
    _trompoCaballero.setPosition(220,340);
    _trompoDragon.setPosition(580,340);
    _nitroTemporizador = 0;
    _nitroPrimerRespawn = true;
    _trompoCaballero.reinicioNitroxRonda();
    _trompoDragon.reinicioNitroxRonda();
    sf::sleep(sf::seconds(2.f));
    _clock.reiniciarTiempo();
    std::cout<<"Reinicio RONDA"<<std::endl;

}
//DIBUJA
void Gameplay::draw(sf::RenderWindow& window)
{
    _arena.draw(window);
    window.draw(_fondo);
    window.draw(_numeroRonda);
    window.draw(_coronaPlayer1);
    window.draw(_coronaPlayer2);
    _trompoCaballero.draw(window);
    _trompoDragon.draw(window);
    _clock.draw(window);
    if(_nitroTemporizador == 0)
    {
        _nitro.draw(window);
    }
}
