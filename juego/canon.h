#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include<iostream>
#include<stdlib.h>


using namespace sf;
using namespace std;
class canon
{
private:

	Texture* txt_ball;
	Sprite* spr_ball;
	
	Vector2f velocidad;
	Vector2f aceleracion;


public:
	canon(Vector2f pos_inicial,Vector2f vel);
	void actualizar(float delta_t);
	Sprite get_sprite() { return *spr_ball; }
};

