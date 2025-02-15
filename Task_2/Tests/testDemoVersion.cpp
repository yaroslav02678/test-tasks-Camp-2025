#include "../src/library/GameOfLife.h"

int main(){
    GameOfLife game("Test1.txt");
    game.display();
    game.run(20);
    system("pause"); 
}