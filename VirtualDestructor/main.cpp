#include <iostream>

using namespace std;

class Base {
public:
	Base() {
		cout << "Base() called" << endl;
	}

	virtual ~Base() {
		cout << "~Base() called" << endl;
	}
};

class Derived : public Base {
private:
	int * m_pIntArray;
	int m_arraySize;
public:
	Derived(int arraySize) : m_pIntArray( new int[arraySize] ), m_arraySize( arraySize ) {
		cout << "Derived() called" << endl;
	}

	~Derived() {
		cout << "~Derived() called" << endl;
		delete [] m_pIntArray;
	}
};

class Animal {
public:
	Animal() {}
	virtual void makeSound() = 0;	//a pure virtual function
};

class Cat : public Animal {
public:
	Cat() {}
	void makeSound() {
		cout << "Miaow" << endl;
	}
};

class Dog : public Animal {
public:
	Dog() {}
	void makeSound() {
		cout << "Woof" << endl;
	}
};

class Fox : public Animal {
public:
	Fox() {}
	void makeSound() {
		cout << "Bay-budabud-dum-bam" << endl;
	}
};

int main() {
	/*Base *pBase = new Derived(10);
	delete pBase;
	cout << "pBase deleted" << endl;
	system("PAUSE");*/

	Animal *pAnimals[] = {new Dog(), new Cat(), new Fox() };
	pAnimals[0]->makeSound();
	pAnimals[1]->makeSound();
	pAnimals[2]->makeSound();
	system("timeout /t 10");
}