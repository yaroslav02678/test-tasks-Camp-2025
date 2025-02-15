#ifndef TASK2_CPP
#define TASK2_CPP

#include "GameOfLife.h"

int i, j;

// Ініціалізація матриці випадковими значеннями
GameOfLife::GameOfLife() : matrix(SIZE, vector<bool>(SIZE)), nextMatrix(SIZE, vector<bool>(SIZE)) {
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            matrix[i][j] = rand() % 2;
        }
    }
}

// Ініціалізація матриці з файлу
GameOfLife::GameOfLife(const string& filename) : matrix(SIZE, vector<bool>(SIZE)), nextMatrix(SIZE, vector<bool>(SIZE)) {
    ifstream file(filename);
    if(file.is_open()){
        for(i = 0; i < SIZE; i++){
            for(j = 0; j < SIZE; j++){
                char cell;
                file >> cell;
                matrix[i][j] = (cell == '1') ? true : false;
            }
        }
    }
    else cout << "File not found" << endl;
    file.close();
}

int GameOfLife::countNeighbours(int x, int y) const {
    unsigned short int count = 0;
    for(i = x - 1; i <= x + 1; i++){
        for(j = y - 1; j <= y + 1; j++){
            if(i >= 0 && i < SIZE && j >= 0 && j < SIZE && !(i == x && j == y)){
                if(matrix[i][j] == true) count++;
            }
        }
    }
    return count;
}

void GameOfLife::update() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbours = countNeighbours(i, j);
            if (matrix[i][j] == true) { // Якщо клітина жива
                if (neighbours < 2 || neighbours > 3) {  // Якщо менше 2 або більше 3 сусідів
                    nextMatrix[i][j] = false; // Вона помирає
                } 
                else {
                    nextMatrix[i][j] = true; // В іншому випадку вона залишається живою
                }
            } 
            else if (matrix[i][j] == false) { // Якщо клітина мертва
                if (neighbours == 3) { // Якщо у неї 3 сусіди
                    nextMatrix[i][j] = true; // Вона оживає
                }
                else {
                    nextMatrix[i][j] = false;  // В іншому випадку вона залишається мертвою
                }
            }
        }
    }
}

void  GameOfLife::display() const {
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            cout << (matrix[i][j] ? "1" : "0"); // Виведення матриці
            cout << " ";
        }
        cout << endl;
    }
}

void GameOfLife::run(int generations){
    for(int i = 0; i < generations; i++){
        cout << "Step " << i + 1 << endl;  
        update();
        matrix = nextMatrix;
        display();
        cout << endl;
    }
}

vector<vector<bool>> GameOfLife::getMatrix() const {
    return matrix;
}

#endif // TASK2