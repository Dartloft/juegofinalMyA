#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>

using namespace sf;

class cajas
{
private:
	Texture txt_cajas;
	Sprite spr_cajas;
public:
	cajas(Vector2f posicion);
	Sprite get_sprite2() {
		return spr_cajas;
	}
};

