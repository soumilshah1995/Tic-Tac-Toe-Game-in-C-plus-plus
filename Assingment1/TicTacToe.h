//
// Created by Soumil Shah on 2019-09-07.
//

#ifndef ASSINGMENT1_TICTACTOE_H
#define ASSINGMENT1_TICTACTOE_H

#include "TicTacToe.h"
#include <fstream>
#include <vector>
#include <string>


class TicTacToe {

public:
    /*
     * Variables Declaration
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
    bool validate(std::vector <char> Sequence);         // Perform Validations
    void print_matrix(std::vector <char> Sequence);     // Takes 2-D Vector and Prints
    char win(std::vector <std::vector <char>> Matrix);  // Check for winner

};


#endif //ASSINGMENT1_TICTACTOE_H
