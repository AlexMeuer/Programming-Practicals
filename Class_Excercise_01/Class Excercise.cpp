#include <iostream>

using namespace std;

int largestIndex(int *intArray, int numElements);
void print(char * str);

int main()
{
	int *pJ, j[10];		//c++ doesnt use 'new' keyword to create arrays; just declare them and they're created
	double *pG, g[10];
	int index;

	pJ = j;
	//pJ = &(j[0]);	possible altenative

	pG = g;

	for(index = 0; index < 10; index++)
	{
		cout << "pJ[" << index << "] " << &(pJ[index]) << endl;	//can also use "pJ + index" instead of "&(pJ[index])"
	}

	cout << endl;	//skip a line

	for(index = 0; index < 10; index++)
	{
		cout << "pG[" << index << "] " << pG + index << endl;	//"pG + index" add the sizeOf index (an int, so 4 bytes) to the pointer
	}

	cout << endl << "Largest Index Of J: " << largestIndex(pJ, 10) << endl;

	system("Pause");
	system("cls");

	//---------------------------------------------------------------------------------------------------//

	char str[] = "Hello";
	//char *str = "Hello"; //does the same thing
	int strIndex;

	for(strIndex = 0; str[strIndex] != '\0'; strIndex++);	//empty loop, we're just counting index

	cout << "\nString length: " << strIndex << endl;
	cout << "strlen output: " << strlen(str) << endl;

	system("Pause");
	system("cls");

	//-------------------------------------------------------------------------------------------------//

	char x = 255;
	unsigned char *y = (unsigned char *) &x;
	cout << (int)x << endl;
	cout << (int)*y << endl;

	system("Pause");
	system("cls");

	//---------------------------------------------------------------------------------------------//

	int a = 5;
	int b = 10;

	double d = static_cast<double>(a / b);	//cast happens after the integer division coz brackets
	cout << "5 / 10 = " << d << "\n" << endl;

	d = static_cast<double>(a) / b;	//now it does division with the double
	cout << "5.0 / 10 = " << d << "\n" << endl;

	a += d;						//warning C4244: '+=' : conversion from 'double' to 'int', possible loss of data
	a += static_cast<int>(d);	//no warning this time!

	system("Pause");
	cout << "\n";

	//-----------------------------------------------------------------------------------------------//

	const char * c = "sample text";	//read-only by default! CAREFUL CAREFUL
	print(const_cast<char *> (c) );
	cout << c << endl;

	system("Pause");
}

int largestIndex(int *intArray, int numElements)
{
	int largestIndex = 0;

	for(int i = 1; i < numElements; i++)
	{
		if(*(intArray + i) > intArray[largestIndex])	//*(intArray + i) and intArray[largestIndex] do the same thing!
		{
			largestIndex = i;
		}//end if
	}//end for

	return largestIndex;
}

void print(char * str)
{
	cout << str << endl;
	//str[0] = 'a';	//cannot change a const! DANGER DANGER (causes crash)
}