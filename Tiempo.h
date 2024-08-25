#ifndef TIEMPO_H
#define TIEMPO_H
#include <SFML/Graphics.hpp>
#include <iomanip>

class Tiempo
{
private:
    sf::Text _text;
    sf::Font _font;

    int _tiempo;

    sf::Time _tiempoTranscurrido;
    sf::Clock _clock;
public:
    Tiempo();

    std::string cuentaregresiva();
    int retornarTiempoTranscurrido();
    void reiniciarTiempo();

    void draw(sf::RenderWindow& window);
};

#endif // TIEMPO_H
