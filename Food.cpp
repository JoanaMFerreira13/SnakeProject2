#include "Food.h"



void Food::gen_food() //criar a comida da cobra de forma aleatória
{
	pos.X = (rand() % (Width - 3)) + 1; // para nao aparecer nas paredes do jogo ou nao aparecer de todo daí o numero 3 25-3=22
	pos.Y = (rand() % (Height - 3)) + 1;
}

COORD Food::get_pos() { return pos; }
