#include <iostream>
#include <string>
using namespace std;

void sort(string *pNames[]);

const int maxNames = 10;

void main()
{
	string names[maxNames];
	string *pNames[maxNames];
	cout << "Name slots: " << maxNames << endl;
	
	for(int i = 0; i < maxNames; i++)
	{
		cout << "Input name: ";
		cin >> names[i];
		pNames[i] = &names[i];
		cout << endl;
	}

	sort(pNames);

	cout << "Unsorted names: " << endl;
	for(int i = 0; i < maxNames; i++)
	{
		cout << names[i] << endl;
	}

	cout << "\nSorted names: " << endl;
	for(int i = 0; i < maxNames; i++)
	{
		cout << *pNames[i] << endl;
	}

	system("Pause");
}

void sort(string *pNames[])
{
	string *swapHolder = 0;	//placeholder for address while we're swapping

	for(int indexA = 0; indexA < maxNames; indexA++)
	{
		for(int indexB = 0; indexB < maxNames; indexB++)
		{
			if((*pNames[indexA]) < (*pNames[indexB]))
			{
				//cout << *pNames[indexA];	//for debug
				//cout << *pNames[indexB];
				//system("Pause");
				swapHolder = pNames[indexA];
				pNames[indexA] = pNames[indexB];
				pNames[indexB] = swapHolder;
				swapHolder = 0;
				//cout << *pNames[indexA];	//for debug
				//cout << *pNames[indexB];
				//system("Pause");
			}//end if
		}//end for i2
	}//end for i1
}