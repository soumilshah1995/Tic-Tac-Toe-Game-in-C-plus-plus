/*
 * TicTacToe.h File
 * Tic Tac Toe Game
 * Author : Soumil Nitin SHah
 * Version 0.0.1
 * Email soushah@my.bridgeport.edu
 * Student id : 1031686
 * Github:
 * Last Modified : 14 Sepetember 2019
 *
 * Operating System: MAC os
 * Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include/c++/4.2.
 * Apple LLVM version 10.0.1 (clang-1001.0.46.3)
 * Target: x86_64-apple-darwin18.7.0
 * InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
 */

#ifndef TICTACTOEGAME_TICTACTOE_H
#define TICTACTOEGAME_TICTACTOE_H

#include "TicTacToe.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ostream>


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

public:
    /*
     * Constructor and Destructor
     */
    TicTacToe();                                                                // Constructor
    ~TicTacToe();                                                               // Destructor

    std::vector <char> setPosition(std::string pos);                            // Main Code
    friend std::ostream &operator<<(std::ostream &os, const TicTacToe rhs);
    void print_matrix(std::vector <char> Sequence);
    char validate(std::vector <char> Sequence) const ;                                 // Perform Validations
    char win(std::vector <std::vector <char>> Matrix);  // Check for winner
    std::vector <char> computer_move(std::vector <char> Sequence, char Mark);


};


#endif //TICTACTOEGAME_TICTACTOE_H