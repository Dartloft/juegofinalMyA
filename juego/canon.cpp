#include "canon.h"

canon::canon(Vector2f pos_inicial, Vector2f vel)
{
	txt_ball = new Texture;
	txt_ball->loadFromFile("pokeball.png");

	spr_ball = new Sprite;
	spr_ball->setTexture(*txt_ball);

	spr_ball->setPosition(pos_inicial);
	spr_ball->setScale(0.1f, 0.1f);
	spr_ball->setColor(Color::Black);

	velocidad = vel;

	aceleracion.x = 0;
	aceleracion.y = 7;

}

void canon::actualizar(float delta_t)
{
	delta_t /= 10;
	velocidad.x += aceleracion.x * delta_t;
	velocidad.y += aceleracion.y * delta_t;

	spr_ball->setPosition(spr_ball->getPosition().x + velocidad.x * delta_t, spr_ball->getPosition().y + velocidad.y * delta_t);
}
