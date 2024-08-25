#include "Trompo.h"

Trompo::Trompo()
{
    _direccion = {0,0};
    _textureNitroEstado.loadFromFile("sprites/nitroInterfaz.png");
    _nitroEstado.setTexture(_textureNitroEstado);
    _nitroEstado.setTextureRect({0,0,30,30});
    _nitroUsable = false;
}
void Trompo::setPosition(float x, float y)
{
    _sprite.setPosition(x, y);
}
void Trompo::setSprite(std::string sprite)
{
    _texture.loadFromFile(sprite);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({0,0,60,60});
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);
}
//SETEA LAS 5 VELOCIDADES
void Trompo::setVelocidad(int velocidad)
{
    _velocidadPos = velocidad;

    switch(_velocidadPos)
    {
    case 0:
        _velocidadGiro = 0.f;
        _velocidadMovimiento = 0.f;
        _velocidadEscudo.setTextureRect({_escudoPos*276,_velocidadPos*400,276,400});
        break;
    case 1:
        _velocidadGiro = 0.1f;
        _velocidadMovimiento = 1.5f;
        _velocidadEscudo.setTextureRect({_escudoPos*276,_velocidadPos*400,276,400});
        break;
    case 2:
        _velocidadGiro = 0.325f;
        _velocidadMovimiento = 1.875f;
        _velocidadEscudo.setTextureRect({_escudoPos*276,_velocidadPos*400,276,400});
        break;
    case 3:
        _velocidadGiro = 0.55f;
        _velocidadMovimiento = 2.25f;
        _velocidadEscudo.setTextureRect({_escudoPos*276,_velocidadPos*400,276,400});
        break;
    case 4:
        _velocidadGiro = 0.775f;
        _velocidadMovimiento = 2.625f;
        _velocidadEscudo.setTextureRect({_escudoPos*276,_velocidadPos*400,276,400});
        break;
    case 5:
        _velocidadGiro = 1.f;
        _velocidadMovimiento = 3.f;
        _velocidadEscudo.setTextureRect({_escudoPos*276,_velocidadPos*400,276,400});
        break;
    }
}
float Trompo::getVelocidad()
{
    return  _velocidadMovimiento;
}
void Trompo::setEscudo()
{
    _escudoPos = 3;
    _velocidadEscudo.setTextureRect({_escudoPos * 276,_velocidadPos*400,276,400});
}
int Trompo::getEscudo()
{
    return _escudoPos;

}
void Trompo::disminuirEscudo()
{
    _escudoPos--;

    if(_escudoPos >= 0)
    {
        _velocidadEscudo.setTextureRect({_escudoPos * 276,_velocidadPos*400,276,400});
    }
}

void Trompo::disminuirEscudo(bool disminuirTodoElEscudo)
{
    if(disminuirTodoElEscudo)
    {
        _escudoPos = 0;
        _velocidadEscudo.setTextureRect({_escudoPos *= 276,_velocidadPos,276,400});
    }
}

void Trompo::setVelocidadEscudo(std::string sprite)
{
    _textureVelocidadEscudo.loadFromFile(sprite);
    _velocidadEscudo.setTexture(_textureVelocidadEscudo);
}

void Trompo::setPositionVelocidadEscudo(float x, float y)
{
    _velocidadEscudo.setPosition(x, y);
}
//REBOTE ENTRE TROMPOS
void Trompo::Rebotar(sf::Vector2f direccion)
{
    direccion = 10.f*direccion;//10.F ES LA DISTANCIA DE REBOTE
    _sprite.move(direccion);
}
void Trompo::setPositionNitroEstado(float x, float y)
{
    _nitroEstado.setPosition(x, y);
}
//NITRO DISPONIBLE PARA USAR
void Trompo::setNitroUsable()
{
    _nitroUsable = true;
    _nitroEstado.setTextureRect({30,0,30,30});
}
//NITRO USADO
void Trompo::setNitroUsado()
{
    _nitroUsado = true;
}

bool Trompo::getNitroUsado()
{
    return _nitroUsado;
}

void Trompo::reinicioNitroxRonda()
{
    _nitroEstado.setTextureRect({0,0,30,30});
}


sf::Vector2f Trompo::getDireccion()
{
    return _direccion;
}

float Trompo::getPositionX()const
{
    return _sprite.getPosition().x;
}

float Trompo::getPositionY()const
{
    return _sprite.getPosition().y;
}
//RADIO DEL TROMPO
float Trompo::getRadio()const
{
    return _sprite.getGlobalBounds().width/2;
}
//COMANDOS
void Trompo::cmd(Controlador &controlador)
{
    _direccion = {0,0};

    if(controlador.presionando(Controlador::Botones::Arriba))
    {
        _direccion.y = -1;
        _estado = TrompoEstado::Movimiento;
    }
    if(controlador.presionando(Controlador::Botones::Abajo))
    {
        _direccion.y = 1;
        _estado = TrompoEstado::Movimiento;
    }
    if(controlador.presionando(Controlador::Botones::Derecha))
    {
        _direccion.x = 1;
        _estado = TrompoEstado::Movimiento;
    }
    if(controlador.presionando(Controlador::Botones::Izquierda))
    {
        _direccion.x = -1;
        _estado = TrompoEstado::Movimiento;
    }

    if(controlador.presionando(Controlador::Botones::Nitro))
    {
        if(_nitroUsable == true)
        {
            _estado = TrompoEstado::UsandoNitro;
            _nitroEstado.setTextureRect({0,0,30,30});
            _nitroUsable = false;
            _nitroUsado = true;
        }
    }
}
//ACTUALIZACION DE ESTADO
void Trompo::update()
{
    _frame += _velocidadGiro;

    if(_frame>=10)
    {
        _frame=0;
    }
    _sprite.setTextureRect({0 + int(_frame)*60, 0, 60, 60});
    switch(_estado)
    {
    case TrompoEstado::Quieto:
        break;
    case TrompoEstado::Movimiento:
        _sprite.move(_direccion * _velocidadMovimiento);
        _nitroUsado = false;
        break;
    case TrompoEstado::UsandoNitro:
        _sprite.move(_direccion * 74.f);
        break;
    }
}
//DIBUJA
void Trompo::draw(sf::RenderWindow& window)
{
    window.draw(_sprite);
    window.draw(_velocidadEscudo);
    window.draw(_nitroEstado);
}




