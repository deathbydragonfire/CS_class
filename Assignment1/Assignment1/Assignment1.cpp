// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum direction {LEFT_RIGHT, RIGHT_LEFT, DOWN, UP, RIGHT_DOWN, RIGHT_UP, LEFT_DOWN,LEFT_UP};  //contains all the possible directions of the words

struct wordGame {  //structure that contains the cross word puzzle to be solved
	int version;
	int numberRows;
	int numberColumns;
	char puzzle[50][50];  //needs to be made into MAX but just assigning for now
	wordGame() {

	}
};

struct wordFind {  //structure that contains the word that must be found and if and where it is found
	string word;
	bool found;
	int row;
	int column;
	direction where;
	wordFind() {

	}
};

bool readPuzzle(string inputFile, wordGame &myGame) {
	int firstNumber = 0;
	ifstream fileReader;
	fileReader.open(inputFile);
	fileReader >> firstNumber;
	cout << firstNumber;
	if (!fileReader.is_open()) {
		cout << "fail\n";
	}
	//TESTING PURPOSES REPLACE WITH FILE READING
	cin >> myGame.numberRows;
	cin >> myGame.numberColumns;
	for (int r = 0; r < myGame.numberRows; r++) {
		for (int c = 0; c < myGame.numberColumns; c++) {
			cin >> myGame.puzzle[r][c];
		}
	}
	cout << "the puzzle is full\n";
	//END TEST
	return true;
}

//shows the puzzle to the user with cout
void displayPuzzle(wordGame &myGame) {
	for (int r = 0; r < myGame.numberRows; r++) {
		for (int c = 0; c < myGame.numberColumns; c++) {
			cout << myGame.puzzle[r][c];
		}
		cout << endl;
	}
}

int main()
{
	wordGame theGame = wordGame();
	readPuzzle("test.txt", theGame);
	displayPuzzle(theGame);
}

