/*
 * Tic Tac Toe Game
 * Author : Soumil Nitin SHah
 * Version 0.0.1
 * Email soushah@my.bridgeport.edu
 * Student id : 1031686
 */

#include <iostream>
#include <fstream>
#include "TicTacToe.h"

using namespace std;

int main() {

    TicTacToe ttt;

    string pos;

    ifstream file;
    string FilePath = "/Users/soumilshah/CLionProjects/Assingment1/input.txt";
    file.open(FilePath);

    while (!file.eof()) {

        getline(file, pos);
        ttt.setPosition(pos);
    }
    file.close();


    return 0;
}

