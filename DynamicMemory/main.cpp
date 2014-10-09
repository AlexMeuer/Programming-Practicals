#include <iostream>

using namespace std;

class Player {
private:
	int * m_lives;	//is a pointer
public:
	Player(int lives = 0) : m_lives(new int(lives)) {
	}

	//special member function to assign new heap space for this object
	/*void assign( Player const & p ) {
		//Step 1: Delete the existing heap space
		delete m_lives;
		//Step 2: Allocate new space and copy data (lives) from p
		m_lives = new int( p.getLives() );
	}*/
	//better solution
	//Overload the assignment operator
	Player& operator=( Player const & rhs ) {	//rhs stands for right-hand-side (because it sits on right hand side of operator)
		//check the LHS object is not the same object that is on the RHS
		if( this != &rhs ) {	//checks if objects are at same address, if they are, skips everything
			//Step 1: Delete the existing heap space
			delete m_lives;
			//Step 2: Allocate new space and copy data (lives) from rhs
			m_lives = new int( rhs.getLives() );

			return *this;	//"this" is a pointer, "*this" refers to the object
		}
	}

	~Player() { delete m_lives; }

	int getLives() const { return *m_lives; }
};

//class Player2 {
//private:
//	int m_lives;	//not a pointer
//public:
//	Player2(int lives= 0) : m_lives(lives) {}
//	int getLives() const {return m_lives;}
//};

//global function
void printPlayer(Player const & p) {
	//create a local player
	Player local;
	Player local2;

	//assign p to local
	local = p;	// NB object p is on the RHS

	local = local2 = p;	//requires operator to return object on left hand side

	cout << "local has: " << local.getLives() << " lives" << endl;
};

int main() {
	//create a local player in main
	Player main(3);
	printPlayer( main );
	cout << main.getLives() << endl;
}