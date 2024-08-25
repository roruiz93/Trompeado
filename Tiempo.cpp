#include "Tiempo.h"

Tiempo::Tiempo()
{
    _tiempo=46;
    _text.setFont(_font);
    _font.loadFromFile("fuentes/Lady Radical.ttf");
    _text.setPosition(370,00);
    _text.setCharacterSize(85);
    _text.setFillColor(sf::Color::Cyan);

}

std::string Tiempo::cuentaregresiva()
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(0) <<retornarTiempoTranscurrido();
    std::string timeString = oss.str();
    if(retornarTiempoTranscurrido()<=0)
    {
        return "0";
    }
    else
    {
        return timeString;
    }
}

int Tiempo::retornarTiempoTranscurrido()
{
    _tiempoTranscurrido = _clock.getElapsedTime();
    return (_tiempo - _tiempoTranscurrido.asSeconds());
}

void Tiempo::reiniciarTiempo()
{
    _clock.restart();
}

void Tiempo::draw(sf::RenderWindow& window)
{
    _text.setString(cuentaregresiva());
    window.draw(_text);
}



