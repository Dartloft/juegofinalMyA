#include "SFML/Graphics.hpp"
#include "Partida.h"
#include <iostream>

using namespace sf;

Partida::Partida(Vector2i dimension, std::string titulo)
{
	fps = 1 / 60.f;

	balas = 10;

	cuadrados = 0;

	ventana1 = new RenderWindow(VideoMode(dimension.x, dimension.y), titulo);

	ventana1->setFramerateLimit(fps);

	if (!buffer.loadFromFile("disparo.wav"))
	{
		cout << "no se pudo cargar el sonido" << endl;
	}
	disparo.setBuffer(buffer);

	if (!buffer1.loadFromFile("punto.wav"))
	{
		cout << "no se puedo cargar el sonido" << endl;
	}
	puntos.setBuffer(buffer1);

	txt_fondo = new Texture;
	txt_fondo->loadFromFile("fondo.jpg");

	spr_fondo = new Sprite;
	spr_fondo->setTexture(*txt_fondo);

	txt_canon = new Texture;
	txt_canon->loadFromFile("canon.png");

	spr_canon = new Sprite;
	spr_canon->setTexture(*txt_canon);
	spr_canon->setScale(0.1f, 0.1f);
	spr_canon->setPosition(20, 500);

	txt_aim = new Texture;
	txt_aim->loadFromFile("cross.png");

	spr_aim = new Sprite;
	spr_aim->setTexture(*txt_aim);
	spr_aim->setScale(0.04f, 0.04f);
	spr_aim->setPosition(spr_canon->getPosition().x + 80, spr_canon->getPosition().y + 25);
	spr_aim->setOrigin(spr_aim->getTexture()->getSize().x / 1.f, spr_aim->getTexture()->getSize().y / 1.f);

	piso = new RectangleShape({800,20});
	piso->setFillColor(Color::Cyan);
	piso->setOutlineColor(Color::White);
	piso->setOutlineThickness(2);
	piso->setPosition(0, 580);

	columna = new RectangleShape({50,100});
	columna->setFillColor(Color::Cyan);
	columna->setOutlineColor(Color::White);
	columna->setOutlineThickness(2);
	columna->setPosition(250, 478);

	columna1 = new RectangleShape({ 50,150 });
	columna1->setFillColor(Color::Cyan);
	columna1->setOutlineColor(Color::White);
	columna1->setOutlineThickness(2);
	columna1->setPosition(450, 428);

	columna2 = new RectangleShape({ 50,200 });
	columna2->setFillColor(Color::Cyan);
	columna2->setOutlineColor(Color::White);
	columna2->setOutlineThickness(2);
	columna2->setPosition(650, 378);

	txt_caja = new Texture;
	txt_caja->loadFromFile("caja.png");


	rojo1 = new RectangleShape({ 50,50 });
	rojo1->setTexture(txt_caja);
	rojo1->setOutlineThickness(2);
	rojo1->setPosition(350, 528);

	rojo2 = new RectangleShape({ 50,50 });
	rojo2->setTexture(txt_caja);
	rojo2->setOutlineThickness(2);
	rojo2->setPosition(550, 528);

	rojo3 = new RectangleShape({ 50,50 });
	rojo3->setTexture(txt_caja);
	rojo3->setOutlineThickness(2);
	rojo3->setPosition(650, 300);

	rojo4 = new RectangleShape({ 50,50 });
	rojo4->setTexture(txt_caja);
	rojo4->setOutlineThickness(2);
	rojo4->setPosition(450, 350);

	rojo5 = new RectangleShape({ 50,50 });
	rojo5->setTexture(txt_caja);
	rojo5->setOutlineThickness(2);
	rojo5->setPosition(250, 400);

	fuente1 = new Font();
	fuente1->loadFromFile("airstrike.ttf");

	txt_balas = new Text();
	txt_balas->setFont(*fuente1);
	txt_balas->setString("balas=");
	txt_balas->setPosition(15, 10);
	txt_balas->setOutlineThickness(1);
	txt_balas->setOutlineColor(Color::Black);

	txt_puntosbalas = new Text();
	txt_puntosbalas->setFont(*fuente1);
	txt_puntosbalas->setString(to_string(balas));
	txt_puntosbalas->setPosition(140, 10);
	txt_puntosbalas->setOutlineThickness(1);
	txt_puntosbalas->setOutlineColor(Color::Black);

	txt_cuadrados = new Text();
	txt_cuadrados->setFont(*fuente1);
	txt_cuadrados->setString("Puntos=");
	txt_cuadrados->setPosition(220, 10);
	txt_cuadrados->setOutlineThickness(1);
	txt_cuadrados->setOutlineColor(Color::Black);

	txt_puntoscuadrados = new Text();
	txt_puntoscuadrados->setFont(*fuente1);
	txt_puntoscuadrados->setString(to_string(cuadrados));
	txt_puntoscuadrados->setPosition(365, 10);
	txt_puntoscuadrados->setOutlineThickness(1);
	txt_puntoscuadrados->setOutlineColor(Color::Black);

	txt_gameover = new Text();
	txt_gameover->setFont(*fuente1);
	txt_gameover->setString("Gameover");
	txt_gameover->setPosition(300, 300);
	txt_gameover->setOutlineThickness(1);
	txt_gameover->setOutlineColor(Color::Black);


	txt_victoria = new Text();
	txt_victoria->setFont(*fuente1);
	txt_victoria->setString("Victory");
	txt_victoria->setPosition(300, 300);
	txt_victoria->setOutlineThickness(1);
	txt_victoria->setOutlineColor(Color::Black);

	reloj1 = new Clock();
	tiempo1 = new Time();
	tiempo2 = 0.f;

	evento1 = new Event;
	
	GameLoop();
}

void Partida::GameLoop()
{
	while (!GameOver)
	{
		*tiempo1 = reloj1->getElapsedTime();
		if (tiempo1->asSeconds() > tiempo2 + fps)
		{
			tiempo2 = tiempo1->asSeconds();
		
			ventana1->clear();

			ventana1->draw(*spr_fondo);

			txt_puntosbalas->setString(std::to_string(balas));
			ventana1->draw(*txt_puntosbalas);

			ventana1->draw(*txt_balas);


			txt_puntoscuadrados->setString(std::to_string(cuadrados));
			ventana1->draw(*txt_puntoscuadrados);
			ventana1->draw(*txt_cuadrados);

			ventana1->draw(*piso);

			ventana1->draw(*spr_canon);

			ventana1->draw(*spr_aim);

			ventana1->draw(*columna);

			ventana1->draw(*columna1);

			ventana1->draw(*columna2);

			ventana1->draw(*rojo1);

			ventana1->draw(*rojo2);

			ventana1->draw(*rojo3);

			ventana1->draw(*rojo4);

			ventana1->draw(*rojo5);


			if (bola1 != NULL)
			{
				bola1->actualizar(tiempo2);
				ventana1->draw(bola1->get_sprite());

			}

			if (balas == 0) {
				
				ventana1->draw(*txt_gameover);
				GameOver = true;
				
			}

			Procesar_eventos();
			procesar_colisiones();

			ventana1->display();
		
		}


		if (cuadrados >= 110)
		{
			*tiempo1 = reloj1->getElapsedTime();
			if (tiempo1->asSeconds() >  + tiempo2)
			{
				tiempo2 = tiempo1->asSeconds();
				ventana1->draw(*txt_victoria);
				GameOver = true;
			}

		}

	}
}

void Partida::Procesar_eventos()
{
	while (ventana1->pollEvent(*evento1))
	{
		switch (evento1->type)
		{
		case Event::Closed:
			exit(1);
			break;
		case Event::KeyPressed:

			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				float potencia_disparo = 80;
				float angulo_mira = spr_aim->getRotation();
				bola1 = new canon(spr_aim->getPosition(), { potencia_disparo * cos(gradosaradianes(angulo_mira)),potencia_disparo * sin(gradosaradianes(angulo_mira)) });
				disparo.play();
				balas--;
			}

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				spr_aim->rotate(-5);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				spr_aim->rotate(5);
			}
			break;
		}
	}
}

void Partida::procesar_colisiones()
{
	if (bola1)
	{
		if (bola1->get_sprite().getGlobalBounds().intersects(rojo1->getGlobalBounds())) 
		{
			rojo1->setFillColor(Color::Green);
			puntos.play();
			cuadrados += 5;
		}
		
		if (bola1->get_sprite().getGlobalBounds().intersects(rojo2->getGlobalBounds()))
		{
			rojo2->setFillColor(Color::Yellow);
			puntos.play();
			cuadrados += 5;
		}
		
		if (bola1->get_sprite().getGlobalBounds().intersects(rojo3->getGlobalBounds()))
		{
			rojo3->setFillColor(Color::Magenta);
			puntos.play();
			cuadrados += 5;
		}

		if (bola1->get_sprite().getGlobalBounds().intersects(rojo4->getGlobalBounds()))
		{
			rojo4->setFillColor(Color::Red);
			puntos.play();
			cuadrados += 5;
		}


		if (bola1->get_sprite().getGlobalBounds().intersects(rojo5->getGlobalBounds()))
		{
			rojo5->setFillColor(Color::Cyan);
			puntos.play();
			cuadrados += 5;
		}
	}
	

	
}



