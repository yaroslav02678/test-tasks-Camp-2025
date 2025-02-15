#include "library/GameOfLife.h"

int main(){
    GameOfLife game;
    cout << "Initial matrix" << endl;
    game.display();
    game.run(20);
    system("pause"); 
}