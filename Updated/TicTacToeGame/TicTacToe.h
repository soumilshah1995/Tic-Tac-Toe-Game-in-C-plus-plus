//
// Created by Soumil Shah on 2019-09-12.
//

#ifndef TICTACTOEGAME_TICTACTOE_H
#define TICTACTOEGAME_TICTACTOE_H

#include "TicTacToe.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>


class TicTacToe {

public:
    /*
     * Declaring Variables
     */
    std::vector <std::vector <char>> Matrix {
            {'e','e','e'},
            {'e','e','e'},
            {'e','e','e'}
    };
    std::vector <char> Tem;
    std::vector <std::vector <char>> mydata;

public:
    /*
     * Constructor and Destructor
     */
    TicTacToe();                                        // Constructor
    ~TicTacToe();                                       // Destructor
    void setPosition(std::string pos);                  // Main Code
    char validate(std::vector <char> Sequence);         // Perform Validations
    void print_matrix(std::vector <char> Sequence);
    char win(std::vector <std::vector <char>> Matrix);  // Check for winner
    std::vector <char> computer_move(std::vector <char> Sequence, char Mark);


};


#endif //TICTACTOEGAME_TICTACTOE_H