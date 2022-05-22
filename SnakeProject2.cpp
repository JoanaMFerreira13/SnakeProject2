#include <iostream>
#include <cstdlib> //livraria para a funcao aleatoria - random
#include <windows.h>
#include <conio.h>
#include <ctime> //para a funcao aleatório/random 


#include "Snake.h"
#include "Food.h"

#define Largura 50
#define Altura 25

#define KB_UP 72 //para podermos usar as teclas das setas do teclado para movimentar a cobra
#define KB_DOWN 80
#define KB_RIGHT 77
#define KB_LEFT 75



using namespace std;

Snake snake({ Largura / 2, Altura / 2 }, 1);
Food food;

int score;

void board() //funcao para definir a área de jogo
{
    COORD snake_pos = snake.get_pos(); //para obtermos a posicao da cobra
    COORD food_pos = food.get_pos(); //posicao da comida

    vector<COORD> snake_body = snake.get_body();
    
    cout << "\t" << "Score: " << score << "\n\n"; //para inserir um score no início da consola
    

    for (int i = 0; i < Altura; i++) //controla o numero de linhas
    {
        cout << "\t.";
        for (int j = 0; j < Largura - 2; j++) //controla a largura, dentro deste ciclo irá imprimir o que se encontra abaixo dependendo da situação
        {
            
            if (i == 0 || i == Altura - 1) cout << '#';
            else if (i == snake_pos.Y && j + 1 == snake_pos.X) cout << "0";
            else if (i == food_pos.Y && j + 1 == food_pos.X) cout << "@";
            else
            {
                bool isBodyPart = false;
                for (int k = 0; k < snake_body.size()-1; k++)
                {
                    if (i == snake_body[k].Y && j + 1 == snake_body[k].X)
                    {
                        cout << 'o';
                        isBodyPart = true;   //caso a cobra acerte na fruta aumentar o corpo com o simbolo 'o' por cada fruta que colida/ coma
                        break;
                    }
                }
                if (!isBodyPart) cout << ' ';
            }
        }
        cout << ".\n";
    }
}

int main()
{
    system("Color 02"); //para dar a cor verde ao texto na consola
    score = 0;
      
    srand(time(NULL)); //para a comida aparecer de forma aleatória no ecrã

    food.gen_food(); //colocado depois de srand para mesmo a primeira fruta aparecer de forma aleatória
    

    char game_over = false;

    while (!game_over)
    {
        board(); 

        if (_kbhit()) //keyboard hit, as teclas que o utilizador terá de primir
        {
            switch (_getch()) //movimento da cobra com as teclas das setas direcionais do teclado
            {
                case KB_UP: snake.change_dir('u'); break;
                case KB_LEFT: snake.change_dir('l'); break;
                case KB_DOWN: snake.change_dir('d'); break;
                case KB_RIGHT: snake.change_dir('r'); break;
            }
        }
        
        if (snake.collided())
        {
            game_over = true;
            cout << "GAME OVER!" << endl;
            break;
        }
        

        if (snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow(); //ao comer a comida a cobra cresce
            score = score + 10; //por cada fruta que a cobra come acrescenta 10 pontos ao score
        }

        snake.move_snake();
        
        //x++; //imprime varias vezes o campo de jogo dando a sensacao de movimento do '0'
       // system("cls"); //limpa o ecra mantendo o mesmo campo e dando a sensacao de movimento do '0'
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 }); //coloca de novo na origem o cursor
    }
    
}
