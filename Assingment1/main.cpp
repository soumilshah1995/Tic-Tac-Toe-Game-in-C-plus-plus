/*
 * Main .CPP File
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

#include <iostream>
#include <fstream>
#include "TicTacToe.h"

using namespace std;

int main() {

    TicTacToe ttt;

    string pos;
    ifstream fin ("/Users/soumilshah/CLionProjects/TicTacToeGame/input.txt");
    ofstream fout("output.txt");

    while (!fin.eof()) {
        getline(fin, pos);
        ttt.setPosition(pos);
        cout << ttt;
        fout << ttt;

    }
    fout.close();

    return 0;
}