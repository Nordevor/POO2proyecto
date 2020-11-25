#pragma once
#ifndef PACMAN_CMCIRCULOS_H
	#define PACMAN_CMCIRCULOS_H

	#include "CCirculo.h"

class CmCirculos
{
private:
	sf::RenderWindow* palCanvas = nullptr;
	vector<CCirculo> v;

public:
	CmCirculos(sf::RenderWindow* _palCanvas, size_t n);
	~CmCirculos();
	void mostrarCirculos();
	void moverCirculos();

	vector<CCirculo> getVectordeCirculos()
	{
		return v;
	}
};

#endif //PACMAN_CMCIRCULOS_H
