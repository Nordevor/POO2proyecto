#pragma once
#ifndef PACMAN_CCIRCULO_H
	#define PACMAN_CCIRCULO_H

	#include "Udefiniciones.h"

class CCirculo
{
private:
	sf::RenderWindow* palCanvas = nullptr;
	tnumeroReal radio;
	tnumeroReal posX;
	tnumeroReal posY;
	tnumeroReal desX;
	tnumeroReal desY;
	sf::Color color;

public:
	CCirculo(sf::RenderWindow* _palCanvas, tnumeroReal _radio, tnumeroReal _posX, tnumeroReal _posY,
		tnumeroReal _desX, tnumeroReal _desY, sf::Color _color);
	virtual ~CCirculo() {};
	void Muestrate();
	void Muevete();
	//--- metodos de acceso ---
	void setRadio(tnumeroReal _radio)
	{
		radio = _radio;
	}
	tnumeroReal getRadio()
	{
		return radio;
	}

	void setPosX(tnumeroReal _posX)
	{
		posX = _posX;
	}
	tnumeroReal getPosX()
	{
		return posX;
	}

	void setPosY(tnumeroReal _posY)
	{
		posY = _posY;
	}
	tnumeroReal getPosY()
	{
		return posX;
	}

	void setDesX(tnumeroReal _desX)
	{
		desX = _desX;
	}
	tnumeroReal getDesX()
	{
		return desX;
	}

	void setDesY(tnumeroReal _desY)
	{
		desY = _desY;
	}
	tnumeroReal getDesY()
	{
		return desY;
	}

	void setColor(sf::Color _color)
	{
		color = _color;
	}
	sf::Color getColor()
	{
		return color;
	}
};

#endif //PACMAN_CCIRCULO_H
