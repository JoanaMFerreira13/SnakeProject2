#include "Food.h"



void Food::gen_food() //criar a comida da cobra de forma aleat�ria
{
	pos.X = (rand() % (Largura - 3)) + 1; // para nao aparecer nas paredes do jogo ou nao aparecer de todo da� o numero 3 25-3=22
	pos.Y = (rand() % (Altura - 3)) + 1;
}

COORD Food::get_pos() { return pos; }
