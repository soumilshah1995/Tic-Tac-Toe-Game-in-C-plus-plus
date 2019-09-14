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
    ifstream fin ("/Users/soumilshah/CLionProjects/TicTacToeGame/input.txt");
    ofstream fout("output.txt.txt");

    while (!fin.eof()) {
        getline(fin, pos);
        ttt.setPosition(pos);

    }
    fout.close();

    return 0;
}