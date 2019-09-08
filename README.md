# Tic-Tac-Toe-Game-in-C-Console

## Problem Statement: 
Design a Game Tic Tac Toe in c ++, Read the Input from A file 

### Approach 
#### Step 1:  Read the Input from File
* Convert the input to Character and store in Vector 
* Store the character of inputs in 2-D Vector

#### Step 2:
* Every Character that is Vector validate the inputs 
* check is input is X O or E and length is 9 anything else its not valid

#### Step 3: make Function winner 
* winner check for x wins or O wins
* winner function also check if no body wins is it a tie ?
* function check is game going on if yes it should suggest a Move 


 
/Users/soumilshah/CLionProjects/Assingment1/cmake-build-debug/Assingment1

Welcome to Tic Tac Toe Game

e | e | e | 
e | e | e | 
e | e | e | 


A B X X X E E E S Invalid

X X X X X O O O E Invalid

X e O X X O e e O Valid Sequence 

X | e | O | 
X | X | O | 
e | e | O | 
Winner O



X O X e X O X e O Valid Sequence 

X | O | X | 
e | X | O | 
X | e | O | 
Winner X



X O O O X X X X O Valid Sequence 

X | O | O | 
O | X | X | 
X | X | O | 
Match Tie


e O O O X X X X O Valid Sequence 

e | O | O | 
O | X | X | 
X | X | O | 

Player X Turn

Suggested Move by Coputer  
x | O | O | 
O | X | X | 
X | X | O | 


e X O O X X X O O Valid Sequence 

e | X | O | 
O | X | X | 
X | O | O | 

Player O Turn 

Suggested Move by Computer  
o | X | O | 
O | X | X | 
X | O | O | 

Process finished with exit code 0

