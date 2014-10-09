#include "PuckManager.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {

	// Uncomment below to test...

	srand(time(0));
	PuckManager manager(6);
	
	cout << "Winning Score: " << manager.getScore() << endl;
	cout << "Winning Colour: ";
	if ( manager.getWinner() == RED ) {
		cout << "Red" << endl;
	}
	else {
		cout << "Yellow" << endl;
	}
	system("PAUSE");
}