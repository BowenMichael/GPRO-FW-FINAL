#include "GPRO-FW-FINAL/GPRO-Input.h"
#include <iostream>
using namespace std;


int getInput() {
	int userInput;

	cout << "Input: ";
	cin >> userInput;

	return userInput;
}

bool validInput(int num, int boardDim) {
	if (num > 0 && num < boardDim) {
		return true;
	}
	
	return false;
}