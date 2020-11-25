#include "CCirculo.h"
#include <SFML/Graphics.hpp>

CCirculo::CCirculo(sf::RenderWindow* _palCanvas, tnumeroReal _radio,
	tnumeroReal _posX, tnumeroReal _posY,
	tnumeroReal _desX, tnumeroReal _desY, sf::Color _color) :
	palCanvas(_palCanvas),
	radio(_radio),
	posX(_posX),
	posY(_posY),
	desX(_desX),
	desY(_desY),
	color(_color)
{
}

void CCirculo::Muestrate()
{
	sf::CircleShape shape;
	shape.setRadius(radio);
	shape.setPosition(posX, posY);
	//shape.setFillColor(sf::Color::Cyan);
	shape.setFillColor(color);
	palCanvas->draw(shape);
}

void CCirculo::Muevete()
{
	if (posX + desX + 2 * radio > palCanvas->getSize().x)
		desX = desX * (-1);
	if (posX + desX < 0)
		desX = desX * (-1);
	if (posY + desY + 2 * radio > palCanvas->getSize().y)
		desY = desY * (-1);
	if (posY + desY < 0)
		desY = desY * (-1);
	posX += desX;
	posY += desY;
}
