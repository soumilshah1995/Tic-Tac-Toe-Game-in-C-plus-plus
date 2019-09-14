//
// Created by Soumil Shah on 2019-09-12.
//

#include "TicTacToe.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

ofstream fout("output.txt");

TicTacToe::TicTacToe() {

    /*
     * Default No Args Constructor
     * Print an Empty Grid to console 3x3
     */

    cout << "\n" << "Welcome to Tic Tac Toe Game" << "\n" <<endl;
    fout << "\n" << "Welcome to Tic Tac Toe Game" << "\n" <<endl;

    for(size_t i=0 ; i<Matrix.size(); i ++){        // Row
        for(size_t j=0 ; j<Matrix.size(); j ++){    //COL
            cout << Matrix.at(i).at(j)<<" | ";      // Display on Console
            fout << Matrix.at(i).at(j)<<" | ";      // Display on Console

        }
        cout << endl;
        fout << endl;
    }
    cout << "\n";
    fout << "\n";
}

TicTacToe::~TicTacToe() {}

void TicTacToe:: setPosition(string pos){

    /*
     * Load the Dataset from File to 2-D Vector
     */

    cout << "\n";

    for(auto x:pos)
    {
        Tem.push_back(x);
        cout << x << " ";
        fout << x << " ";
    }
    mydata.push_back(Tem);

    char value;
    value = validate(Tem);      // Call Validate Function

    if (value == 'A')
    {
        cout << "Invalid Letters ! " << endl;
        cout << "-----------------------------------------------" << endl;
        fout << "Invalid Letters ! " << endl;
        fout << "-----------------------------------------------" << endl;

    }
    else if(value == 'B')
    {
        cout << "Invalid Length " << endl;
        cout << "-----------------------------------------------" << endl;
        fout << "Invalid Length " << endl;
        fout << "-----------------------------------------------" << endl;

    }
    else if(value == 'C')
    {
        cout << "Impossible Position !" << endl;
        cout << "-----------------------------------------------" << endl;
        fout << "Impossible Position !" << endl;
        fout << "-----------------------------------------------" << endl;
    }
    else
    {

        // valid String

        cout << ":-Input String " << endl;
        cout << "\n";
        fout << ":-Input String " << endl;
        fout << "\n";
        print_matrix(Tem);


        char winner;
        winner = win(Matrix);

        if (winner == 'X')
        {
            cout << "\n";
            cout << "Winner " << "X" << endl;
            cout << "\n";
            cout << "-----------------------------------------------" << endl;

            fout << "\n";
            fout << "Winner " << "X" << endl;
            fout << "\n";
            fout << "-----------------------------------------------" << endl;

        }
        else if(winner == 'O')
        {
            cout << "\n";
            cout << "Winner " << "O" << endl;
            cout << "\n";
            cout << "-----------------------------------------------" << endl;


            fout << "\n";
            fout << "Winner " << "O" << endl;
            fout << "\n";
            fout << "-----------------------------------------------" << endl;
        }

        else if (winner == 'M')
        {
            cout << "\n";
            cout << "Match Tie" << endl;
            cout << "-----------------------------------------------" << endl;

            fout << "\n";
            fout << "Match Tie" << endl;
            fout << "-----------------------------------------------" << endl;
        }

        else if(winner == 'A')
        {
            cout << "\n";
            cout << "X Turn " << endl;
            cout << "\n";
            cout << "Suggested Move by Computer  " << endl;

            fout << "\n";
            fout << "X Turn " << endl;
            fout << "\n";
            fout << "Suggested Move by Computer  " << endl;

            vector <char> ComputedMove;
            cout << "\n";
            fout << "\n";
            ComputedMove = computer_move(Tem, 'X');
            print_matrix(ComputedMove);

            ComputedMove.clear();

            cout << "\n";
            cout << "-----------------------------------------------" << endl;
            fout << "\n";
            fout << "-----------------------------------------------" << endl;
        }


        else if(winner == 'B')
        {
            cout << "\n";
            cout << "O Turn " << endl;
            cout << "\n";
            cout << "Suggested Move by Computer  " << endl;
            fout << "\n";
            fout << "O Turn " << endl;
            fout << "\n";
            fout << "Suggested Move by Computer  " << endl;

            vector <char> ComputedMove;
            cout << "\n";
            fout << "\n";
            ComputedMove = computer_move(Tem, 'O');
            print_matrix(ComputedMove);

            ComputedMove.clear();

            cout << "-----------------------------------------------" << endl;
            fout << "-----------------------------------------------" << endl;
        }


    }

    Tem.clear();
}


char TicTacToe:: validate(vector <char> Sequence)
{
    /*
     * This Function Return Boolean Based Whether the Input is Valid or Not
     */
    int GlobalCounter = 0;
    int CountX = 0;
    int CountO = 0;
    int CountE = 0;

    for(size_t i=0; i<Sequence.size(); i++)
    {

        if(Sequence.at(i) == 'x' or Sequence.at(i) == 'o' or Sequence.at(i) == 'e')
        {
            GlobalCounter = GlobalCounter + 1;

            if(Sequence.at(i) == 'x')
            {
                CountX = CountX + 1;
            }
            else if(Sequence.at(i) == 'o')
            {
                CountO = CountO + 1;
            }
            else if(Sequence.at(i) == 'e')
            {
                CountE = CountE + 1;
            }
        }
        else
        {
            return 'A';
            break;
        }
    }

    if (GlobalCounter != 9)
    {
        return 'B';
    }
    if(GlobalCounter == 9)
    {
        if (CountO >=6 or CountX >=6)
        {
            return 'C';
        }

        if(CountX > CountO and CountE ==1)
        {
            return 'C';
        }

        if(CountO > CountX and CountE ==1)
        {
            return 'C';
        }

    }

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
            fout << Matrix.at(i).at(j) << " | ";
            counter = counter +1;

        }
        cout << endl;
        fout << endl;
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
    if(  Matrix.at(0).at(0) == 'x' && Matrix.at(0).at(1)== 'x' && Matrix.at(0).at(2) == 'x' ){return 'X';}

    // 10-11-12
    if(  Matrix.at(1).at(0) == 'x' && Matrix.at(1).at(1)== 'x' && Matrix.at(1).at(2) == 'x' ){return 'X';}

    // 20-21-22
    if(  Matrix.at(2).at(0) == 'x' && Matrix.at(2).at(1)== 'x' && Matrix.at(2).at(2) == 'x' ){return 'X';}

    // ------------------------------------------Column Check ---------------------------------------------------------------


    // 00-10-20
    if(  Matrix.at(0).at(0) == 'x' && Matrix.at(1).at(0)== 'x' && Matrix.at(2).at(0) == 'x' ){return 'X';}


    // 01-11-21
    if(  Matrix.at(0).at(1) == 'x' && Matrix.at(1).at(1)== 'x' && Matrix.at(2).at(1) == 'x' ){return 'X';}

    // 02-12-22
    if(  Matrix.at(0).at(2) == 'x' && Matrix.at(1).at(2)== 'x' && Matrix.at(2).at(2) == 'x' ){return 'X';}

    //-------------------------------------------Diagobnal Check------------------------

    // Diagobnal Check

    // 00-11-22
    if(  Matrix.at(0).at(0) == 'x' && Matrix.at(1).at(1)== 'x' && Matrix.at(2).at(2) == 'x' ){return 'X';}

    //02-11-20
    if(  Matrix.at(0).at(2) == 'x' && Matrix.at(1).at(1)== 'x' && Matrix.at(2).at(0) == 'x' ){return 'X';}


    /*
    * Player O
    */


    // ----------------------------------Row  Check --------------------------------------------
    // 00-01-02
    if(  Matrix.at(0).at(0) == 'o' && Matrix.at(0).at(1)== 'o' && Matrix.at(0).at(2) == 'o' ){return 'O';}

    // 10-11-12
    if(  Matrix.at(1).at(0) == 'o' && Matrix.at(1).at(1)== 'o' && Matrix.at(1).at(2) == 'o' ){return 'O';}

    // 20-21-22
    if(  Matrix.at(2).at(0) == 'o' && Matrix.at(2).at(1)== 'o' && Matrix.at(2).at(2) == 'o' ){return 'O';}


    // ------------------------------------------Column Check ------------------------------------

    // 00-10-20
    if(  Matrix.at(0).at(0) == 'o' && Matrix.at(1).at(0)== 'o' && Matrix.at(2).at(0) == 'o' ){return 'O';}


    // 01-11-21
    if(  Matrix.at(0).at(1) == 'o' && Matrix.at(1).at(1)== 'o' && Matrix.at(2).at(1) == 'o' ){return 'O';}

    // 02-12-22
    if(  Matrix.at(0).at(2) == 'o' && Matrix.at(1).at(2)== 'o' && Matrix.at(2).at(2) == 'o' ){return 'O';}

    //----------------------------------------------------------------------------------------------------------

    // Diagobnal Check

    // 00-11-22
    if(  Matrix.at(0).at(0) == 'o' && Matrix.at(1).at(1)== 'o' && Matrix.at(2).at(2) == 'o' ){return 'O';}

    //02-11-20
    if(  Matrix.at(0).at(2) == 'o' && Matrix.at(1).at(1)== 'o' && Matrix.at(2).at(0) == 'o' ){return 'O';}


    for(size_t i=0; i < Matrix.size(); i ++)
    {
        for(size_t j=0; j<Matrix.size(); j++){
            if(Matrix.at(i).at(j) == 'x'){
                CountX = CountX+1;
            }
            if(Matrix.at(i).at(j) == 'o'){
                CountO = CountO +1;
            }

            if(Matrix.at(i).at(j)== 'e'){
                CountE = CountE+1;
            }

        }
    }

    if (CountE == 0)
    {
        return 'M';
    }
    if(CountX ==  CountO and CountE == 1)
    {
        return 'A';
    }
    if (CountX ==1  and CountE >=1)
    {
        return 'B';
    }

    if (CountO ==1  and CountE >=1)
    {
        return 'A';
    }

    if (CountO > CountX and CountE >=1)
    {
        return 'A';
    }


    if (CountO < CountX and CountE >=1)
    {
        return 'B';
    }


}

std::vector<char> TicTacToe::computer_move(std::vector <char> Sequence, char Mark)
{

    std::vector <int> EmptyPos = {};
    for(size_t i=0; i<Tem.size(); i++)
    {
        if (Tem.at(i) == 'e')
        {
            //cout << "Empty Position " << i << " " << endl;
            EmptyPos.push_back(i);
        }
    }

    int randomIndex = {0};
    int RandomNumberPosE = {0};

    srand(time(0));
    int Size = EmptyPos.size();
    randomIndex = (rand() % Size);
    RandomNumberPosE = EmptyPos.at(randomIndex);

    if (Tem.at(randomIndex) == 'e')
    {
        Tem.at(randomIndex) = Mark;
    }else{
        Tem.at(EmptyPos.at(0)) = Mark;
    }

    return Tem;

}