//
// Created by Soumil Shah on 2019-09-07.
//

#include "TicTacToe.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void TicTacToe:: setPosition(string pos){

    /*
     * Load the Dataset from File to 2-D Vector
     */

    cout << "\n";
    for(auto x:pos){            // Each XOXeXoXeO
        Tem.push_back(x);       // Upload to Vector all Character
        cout << x << " ";}      // Display the Input from File to Console

    mydata.push_back(Tem);

    bool value;     // Checks for Validations
    char winner;

    value = validate(Tem);

    if(value)
    {
        /*
         * if the string is Validated
         * print matrix
         * check winner
         */
        cout << "Valid Sequence " << endl;
        cout << "\n";
        print_matrix(Tem);

        char winner;
        winner = win(Matrix);

        if(winner == 'X')
        {
            /*
             * check if Winner X
             */
            cout << "Winner " << "X" << endl;
            cout << "\n";

        }

        if(winner == 'O')
        {
            /*
             * Check if winner O
             */
            cout << "Winner " << "O" << endl;
            cout << "\n";
        }

        if (winner == 'M')
        {
            /*
             * Check if Match is Tie
             */
            cout << "Match Tie" << endl;
        }

        if(winner == 'A')
        {
            /*
             *  If player X Turn Suggest a Index
             *  Scan the Matrix for Empty Index
             */
            cout << "\n";
            cout << "Player X Turn" << endl;
            cout << "\n";
            cout << "Suggested Move by Coputer  " << endl;

            // Scanning matrix
            for(size_t i=0; i<Matrix.size();i++){
                for (size_t j=0; j<Matrix.size();j++){
                    if(Matrix.at(i).at(j) == 'e'){
                        Matrix.at(i).at(j) = 'x';
                        break;
                    }
                }
            }
            // print 2-d Matrix


            for (size_t i = 0; i < Matrix.size(); i++) {

                for (size_t j = 0; j < Matrix.size(); j++) {
                    cout << Matrix.at(i).at(j) << " | ";


                }
                cout << endl;
            }


        }

        if(winner == 'B')
        {
            /*
             * If Player O Turn Suggest Index
             */
            cout<< "\n";
            cout <<  "Player O Turn " << endl;
            cout << "\n";
            cout << "Suggested Move by Computer  " << endl;

            // Scanning matrix
            for(size_t i=0; i<Matrix.size();i++){
                for (size_t j=0; j<Matrix.size();j++){
                    if(Matrix.at(i).at(j) == 'e'){
                        Matrix.at(i).at(j) = 'o';
                        break;
                    }
                }
            }
            // print 2-d Matrix

            for (size_t i = 0; i < Matrix.size(); i++) {

                for (size_t j = 0; j < Matrix.size(); j++) {
                    cout << Matrix.at(i).at(j) << " | ";


                }
                cout << endl;
            }



        }
        else
            {
            std::cout<< "" << endl;
            }
    }
    else
        {
        cout << "Invalid" << endl;
        }

    Tem.clear();

    }


bool TicTacToe:: validate(vector <char> Sequence){
    /*
     *   Condition to Checks
     *   1. Size of Vector is 9
     *   2. Check if its  O
     *   3. check if its  X
     *   check if e
     *   anything else return false
     */
        int counter = 0;

        for (size_t i = 0; i < Sequence.size(); i++)
        {

            if (Sequence[i] == 'X' or Sequence[i] == 'O' or Sequence[i] == 'e') {
                counter = counter + 1;}
            else{
                return false;
                counter = 0;
                break;}

        }

        if (counter == 9 and Sequence.size() == 9)
        {
            return true;
            counter = 0;
        }
        counter = 0;
}


void TicTacToe:: print_matrix(vector <char> Sequence){
    /*
     * Takes a Vector type char Based on that it Print the Matrix
     */

    int counter = 0 ;
    for (size_t i = 0; i < Matrix.size(); i++) {

        for (size_t j = 0; j < Matrix.size(); j++) {

            Matrix.at(i).at(j) = Sequence[counter];
            cout << Matrix.at(i).at(j) << " | ";
            counter = counter +1;

        }
        cout << endl;
    }
    counter = 0;
}


char TicTacToe::win(vector <vector <char>> Matrix){

    /*
     * Check if the Matrix Size if 3 so check for 3 Rows
     * Based on That check Condition for Winner
     */

    int CountX = 0;
    int CountO = 0;
    int CountE = 0;
    char FirstSeq;



        //---------------------------------- Row  Check -----------------------------
        // 00-01-02
        if(  Matrix.at(0).at(0) == 'X' && Matrix.at(0).at(1)== 'X' && Matrix.at(0).at(2) == 'X' ){return 'X';}

        // 10-11-12
        if(  Matrix.at(1).at(0) == 'X' && Matrix.at(1).at(1)== 'X' && Matrix.at(1).at(2) == 'X' ){return 'X';}

        // 20-21-22
        if(  Matrix.at(2).at(0) == 'X' && Matrix.at(2).at(1)== 'X' && Matrix.at(2).at(2) == 'X' ){return 'X';}

        // ------------------------------------------Column Check ---------------------------------------------------------------


        // 00-10-20
        if(  Matrix.at(0).at(0) == 'X' && Matrix.at(1).at(0)== 'X' && Matrix.at(2).at(0) == 'X' ){return 'X';}


        // 01-11-21
        if(  Matrix.at(0).at(1) == 'X' && Matrix.at(1).at(1)== 'X' && Matrix.at(2).at(1) == 'X' ){return 'X';}

        // 02-12-22
        if(  Matrix.at(0).at(2) == 'X' && Matrix.at(1).at(2)== 'X' && Matrix.at(2).at(2) == 'X' ){return 'X';}

        //-------------------------------------------Diagobnal Check------------------------

        // Diagobnal Check

        // 00-11-22
        if(  Matrix.at(0).at(0) == 'X' && Matrix.at(1).at(1)== 'X' && Matrix.at(2).at(2) == 'X' ){return 'X';}

        //02-11-20
        if(  Matrix.at(0).at(2) == 'X' && Matrix.at(1).at(1)== 'X' && Matrix.at(2).at(0) == 'X' ){return 'X';}


        /*
        * Player O
        */


        // ----------------------------------Row  Check --------------------------------------------
        // 00-01-02
        if(  Matrix.at(0).at(0) == 'O' && Matrix.at(0).at(1)== 'O' && Matrix.at(0).at(2) == 'O' ){return 'O';}

        // 10-11-12
        if(  Matrix.at(1).at(0) == 'O' && Matrix.at(1).at(1)== 'O' && Matrix.at(1).at(2) == 'O' ){return 'O';}

        // 20-21-22
        if(  Matrix.at(2).at(0) == 'O' && Matrix.at(2).at(1)== 'O' && Matrix.at(2).at(2) == 'O' ){return 'O';}


        // ------------------------------------------Column Check ------------------------------------

        // 00-10-20
        if(  Matrix.at(0).at(0) == 'O' && Matrix.at(1).at(0)== 'O' && Matrix.at(2).at(0) == 'O' ){return 'O';}


        // 01-11-21
        if(  Matrix.at(0).at(1) == 'O' && Matrix.at(1).at(1)== 'O' && Matrix.at(2).at(1) == 'O' ){return 'O';}

        // 02-12-22
        if(  Matrix.at(0).at(2) == 'O' && Matrix.at(1).at(2)== 'O' && Matrix.at(2).at(2) == 'O' ){return 'O';}

        //----------------------------------------------------------------------------------------------------------

        // Diagobnal Check

        // 00-11-22
        if(  Matrix.at(0).at(0) == 'O' && Matrix.at(1).at(1)== 'O' && Matrix.at(2).at(2) == 'O' ){return 'O';}

        //02-11-20
        if(  Matrix.at(0).at(2) == 'O' && Matrix.at(1).at(1)== 'O' && Matrix.at(2).at(0) == 'O' ){return 'O';}


        /*
         * Winner is not X and Not O
         * Then Iterate over the Matrix
         * Count Number X
         * Count Number of O
         * Count Number of e
         * if CountX > CountO >- O turns
         * if CountX < CountO >- X Turn
         * if Empty = 0 Then its Tie
         * First Seq O-> X turn Return A
         * First Seq X-> O turn Return B
         * B->O
         * A->X
         * M - TIe
         */

        for(size_t i=0; i < Matrix.size(); i ++)
        {
            for(size_t j=0; j<Matrix.size(); j++){
                if(Matrix.at(i).at(j) == 'X'){
                    CountX = CountX+1;
                }
                if(Matrix.at(i).at(j) == 'O'){
                    CountO = CountO +1;
                }

                if(Matrix.at(i).at(j)== 'e'){
                    CountE = CountE+1;
                }

            }
        }

        if (  ((CountX >= CountO) and (CountE > 0)) or ((CountX <= CountO) and (CountE > 0)))
        {

            for(size_t i=0; i < Matrix.size(); i ++)
            {
                for(size_t j=0; j<Matrix.size(); j++){
                    if(Matrix.at(i).at(j) == 'X'){
                        FirstSeq = 'X';
                        return 'B';
                        break;
                    }
                    if(Matrix.at(i).at(j) == 'O'){
                        FirstSeq = 'O';
                        return 'A';
                        break;
                    } else{

                    }

                }
            }
        }

        if (CountE == 0){
            return 'M';}


}



TicTacToe::TicTacToe() {

    /*
     * Default No Args Constructor
     * Print an Empty Grid to console 3x3
     */

    cout << "\n" << "Welcome to Tic Tac Toe Game" << "\n" <<endl;

    for(size_t i=0 ; i<Matrix.size(); i ++){        // Row
        for(size_t j=0 ; j<Matrix.size(); j ++){    //COL
            cout << Matrix.at(i).at(j)<<" | ";      // Display on Console

        }
        cout << endl;
    }
    cout << "\n";

}

TicTacToe::~TicTacToe() {}


