#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>

#define Width 50
#define Height 25

using namespace std;

class Snake
{
	private:
		COORD pos; //coordenadas da posicao
		int len; //comprimento da cobra
		int vel; //velocidade da cobra
		char direction; //direcao da cobra
		vector<COORD> body;

	public:
		Snake(COORD pos, int vel);
		void change_dir(char dir); //para mudar a direcao da cobra
		void move_snake(); //para movimentar a cobra numa direcao em particular
		COORD get_pos(); //para obter a currente posicao da cobra

		bool eaten(COORD food_pos);

		void grow();
		bool collided();

		vector<COORD> get_body();

	
};

#endif;



