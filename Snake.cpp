#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{
	this->pos = pos; //apontadores de posicao e velocidade
	this->vel = vel;

	len = 1; //nao pode ser zero devido à cabeça da cobra
	direction = 'n'; //a cobra ao início do jogo nao se está a mover daí ser nenhuma 'n'

	body.push_back(pos);
}

void Snake::change_dir(char dir) { direction = dir; }
void Snake::grow() { len++; }
COORD Snake::get_pos() { return pos; }

vector<COORD> Snake::get_body() { return body; }

void Snake::move_snake()
{
	switch (direction)
	{
		case 'u': pos.Y -= vel; break; //cima
		case 'd': pos.Y += vel; break; //baixo
		case 'l': pos.X -= vel; break; //esquerda
		case 'r': pos.X += vel; break; //direita
	}

	if (pos.X > Largura - 2) pos.X = 1;
	else if (pos.X < 1) pos.X = Largura - 2;

	body.push_back(pos);
	if (body.size() > len) body.erase(body.begin());
}


bool Snake::eaten(COORD food_pos)
{
	if (food_pos.X == pos.X && food_pos.Y == pos.Y) return true; //estas coordenadas significam que a cobra comeu a comida
	else return false;
}


bool Snake::collided() //funcao para quando colidir com as paredes laterais voltar a aparecer a cobra
{
	if (pos.X < 1 || pos.X > Largura-2 || pos.Y < 1 || pos.Y > Altura-2) return true;
	
	return false;

} 
