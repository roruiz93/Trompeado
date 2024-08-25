#ifndef TROMPO_H
#define TROMPO_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Colisionable.h"
#include "Controlador.h"

enum class TrompoEstado
{
    Quieto,
    Movimiento,
    UsandoNitro
};

class Trompo : public Colisionable
{
private:
    //SPRITE DE TROMPO
    sf::Sprite _sprite;
    sf::Texture _texture;
    //DIRECCION Y ESTADO DEL TROMPO
    sf::Vector2f _direccion;
    TrompoEstado _estado = TrompoEstado::Quieto;
    //MOVIMIENTO DEL TROMPO
    float _velocidadMovimiento;
    float _velocidadGiro;
    float _frame;

    sf::Sprite _nitroEstado;
    sf::Texture _textureNitroEstado;
    bool _nitroUsable;
    bool _nitroUsado;
    //SPRITE VELOCIDAD Y ESCUDO DEL TROMPO
    sf::Sprite _velocidadEscudo;
    sf::Texture _textureVelocidadEscudo;
    int _velocidadPos;
    int _escudoPos;



public:
    Trompo();

    void setPosition(float x, float y);
    void setSprite(std::string sprite);

    void setVelocidad(int velocidad);
    float getVelocidad();

    void setEscudo();
    int getEscudo();
    void disminuirEscudo();
    void disminuirEscudo(bool disminuirTodoElEscudo);
    void setVelocidadEscudo(std::string sprite);
    void setPositionVelocidadEscudo(float x, float y);

    void Rebotar(sf::Vector2f direccion);

    void setPositionNitroEstado(float x, float y);
    void setNitroUsable();
    void setNitroUsado();
    bool getNitroUsado();
    void reinicioNitroxRonda();

    sf::Vector2f getDireccion();
    float getPositionX()const;
    float getPositionY()const;
    float getRadio()const;

    void cmd(Controlador &controlador);
    void update();

    void draw(sf::RenderWindow& window);

};

#endif // TROMPO_H
