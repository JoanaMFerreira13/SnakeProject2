#ifndef FOOD_H
#define FOOD_H
#include <Windows.h>
#include <cstdlib> //para aparecer de forma aleatória a comida

#define Largura 50
#define Altura 25

class Food
{
	private:
		COORD pos; //posicao da comida
	
	public:
      
		void gen_food();
		COORD get_pos();

};

#endif;


