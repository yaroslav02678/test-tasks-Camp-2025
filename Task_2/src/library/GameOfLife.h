#ifndef TASK2_H
#define TASK2_H

#include <iostream>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

const unsigned short int SIZE = 20;

class GameOfLife{   
    vector<vector<bool>> matrix;
    vector<vector<bool>> nextMatrix;
public:
    GameOfLife(); 
    GameOfLife(const string& filename);
    int countNeighbours(int x, int y) const; // підрахунок сусідів
    void update(); // оновлення матриці
    void display() const; // виведення матриці
    void run(int generations); // запуск гри
    vector<vector<bool>> getMatrix() const; 
};  

#endif