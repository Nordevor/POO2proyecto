#include "CmCirculos.h"

CmCirculos::CmCirculos(sf::RenderWindow* _palCanvas, size_t n) :
	palCanvas(_palCanvas)
{
	//--- creamos todos los circulos con valores al azar
	tnumeroReal _radio;
	tnumeroReal _posX;
	tnumeroReal _posY;
	tnumeroReal _desX;
	tnumeroReal _desY;
	for (size_t i = 0; i < n; i++)
	{
		_radio = 25;
		_posX = (float)palCanvas->getSize().x / 2 - _radio;
		_posY = (float)palCanvas->getSize().y / 2 - _radio;
		_desX = rand() % 9;
		_desY = rand() % 9;
		auto _color = sf::Color(rand() % 250, rand() % 250, rand() % 250);
		CCirculo unCirculo(palCanvas, _radio, _posX, _posY, _desX, _desY, _color);
		v.push_back(unCirculo);
	}
}

CmCirculos::~CmCirculos()
{}

void CmCirculos::mostrarCirculos()
{
	for (size_t i = 0; i < v.size(); i++)
		v[i].Muestrate();
}

void CmCirculos::moverCirculos()
{
	for (size_t i = 0; i < v.size(); i++)
		v[i].Muevete();
}
