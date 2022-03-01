#include "SFML/Graphics.hpp"
#include <iostream>
#include<stdlib.h>
#include "Partida.h"
#include "canon.h"

int main()
{
    Vector2i dimension;

    dimension.x = 800;
    dimension.y = 600;

    Partida* partida1;

    partida1 = new Partida(dimension, "Canonball");
}

