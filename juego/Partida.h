#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
#include<stdlib.h>
#include "canon.h"


using namespace sf;

class Partida
{
private:
	
	RenderWindow* ventana1;

	Clock* reloj1;
	Time* tiempo1;
	float tiempo2;

	int balas;
	int cuadrados;

	SoundBuffer buffer;
	Sound disparo;

	SoundBuffer buffer1;
	Sound puntos;

	Font* fuente1;
	Text* txt_balas;

	Text* txt_puntosbalas;

	Text* txt_cuadrados;

	Text* txt_puntoscuadrados;

	Text* txt_gameover;

	Text* txt_victoria;
	
	Texture* txt_fondo;
	Sprite* spr_fondo;

	Texture* txt_canon;
	Sprite* spr_canon;

	Texture* txt_aim;
	Sprite* spr_aim;

	RectangleShape* piso;

	RectangleShape* columna;

	RectangleShape* columna1;

	RectangleShape* columna2;

	Texture* txt_caja;

	RectangleShape* rojo1;

	RectangleShape* rojo2;

	RectangleShape* rojo3;

	RectangleShape* rojo4;

	RectangleShape* rojo5;



	canon* bola1;

	Event* evento1;

	float fps;
	bool GameOver = false;

public:
	Partida(Vector2i dimension,std::string titulo);
	void GameLoop();
	void Procesar_eventos();
	float gradosaradianes(float grados) { return grados * 3.14 / 180; };
	void procesar_colisiones();
	
};

