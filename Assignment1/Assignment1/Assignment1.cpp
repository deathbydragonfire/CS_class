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
		found = false;
	}
};
//reads from the file given and alters the word game passed to it to contain the new puzzle
bool readPuzzle(string inputFile, wordGame &myGame) {
	ifstream fileReader;
	fileReader.open(inputFile); //opens the file specified
	if (!fileReader.is_open()) {  // if it doesn't work, return false
		return false;
	}
	//else:
	//set some stuff
	fileReader >> myGame.numberRows;
	fileReader >> myGame.numberColumns;
	myGame.version = 1;
	//populate the array, rows then columns
	for (int r = 0; r < myGame.numberRows; r++) {
		for (int c = 0; c < myGame.numberColumns; c++) {
			fileReader >> myGame.puzzle[r][c];
		}
	}
	fileReader.close();  //clean up and return true, all went well.
	return true;
}

//shows the puzzle to the user with cout
void displayPuzzle(wordGame &myGame) {
	//iterate through the array, rows then columns, and print
	for (int r = 0; r < myGame.numberRows; r++) {
		for (int c = 0; c < myGame.numberColumns; c++) {
			cout << myGame.puzzle[r][c];
		}
		cout << endl;
	}
}
//searches for a word from left to right and returns a wordFind
wordFind findLTR(wordGame &myGame, string currWord) {
	wordFind hereItIs = wordFind(); //create the wordfind;
	if (myGame.numberRows > 100) { //check if the puzzle is too big for the array and stop it from crashing
		cout << "puzzle is too big, must have less than 100 rows";
		return hereItIs;
	}
	//else:
	string rows[101]; //create an array of strings, one for each row
	for (int r = 0; r < myGame.numberRows; r++) { //iterate through rows, then columns
		for (int c = 0; c < myGame.numberColumns; r++) {
			rows[r] += myGame.puzzle[r][c];  //fill the string array with the chars
		}
	}
	
	for (int r = 0; r < myGame.numberRows; r++) { //iterate through the rows
		int c = rows[r].find(currWord); //look for the word and store its position in the string
		if (c > -1) { //if it is found set all the values
			hereItIs.row = r;
			hereItIs.column = c;
			hereItIs.found = true;
			hereItIs.where = LEFT_RIGHT;
		}
	}
	return hereItIs;
}

//runs through each possible orientation of the word and returns the wordFind
wordFind findWord(wordGame &myGame, string currWord) {
	wordFind hereItIs = wordFind();
	hereItIs = findLTR(myGame, currWord); //finds left to right
	//hereItIs = findRTL(myGame, currWord); //finds right to left
	//hereItIs = findUp(myGame, currWord); //finds up
	//hereItIs = findDown(myGame, currWord); //finds down
	//hereItIs = findLU(myGame, currWord); //finds left and up
	//hereItIs = findLD(myGame, currWord); //finds left and down
	//hereItIs = findRU(myGame, currWord); //finds right and up
	//hereItIs = findRD(myGame, currWord); //finds right and down
	return hereItIs;
}

int main()
{
	string listOfWords[50];
	int numWords = 0;
	string fileName;
	cin >> fileName;
	wordGame theGame = wordGame();
	if (!readPuzzle(fileName, theGame)) {  //read the file to a wordGame and check that it was successful
		cout << "The puzzle file " << fileName << " could not be opened or is invalid" << endl;  //if file is bad, tell the user
		return 1; //kill the program
	}
	
	//else:
	cout << fileName << " was read successfully" << endl;
	
	displayPuzzle(theGame);  //display the puzzle to user
	fileName = "";
	cin >> fileName;  //get new file name
	ifstream fileReader;
	fileReader.open(fileName);  //try to open it
	if (!fileReader.is_open()) {  //did it work?  if no tell the user and kill the program
		cout << "The word list file " << fileName << "could not be opened or is invalid" << endl;
		return 2;
	}
	//else:
	while(
	
}

