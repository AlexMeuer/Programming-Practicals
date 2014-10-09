#include "PuckManager.h"


PuckManager::PuckManager(int pucks) : m_pucks( pucks ), m_puckArray( new Puck[pucks] ) {

	int sizeOfArray = sizeof(m_puckArray);

	//set half the pucks to yellow
	for(int i = 0; i < sizeOfArray / 2; i++)
	{
		m_puckArray[i].setTeam(YELLOW);
	}
}

int PuckManager::getScore() {
	//
	//we'll be working backwards through the array because high Z values win, and their at the end after we sort
	//
	sortByZValue();	// This sorts the array so that Pucks are ordered by their z values (smallest first).

	int i = m_pucks - 1;	//-1 because first puck is at index 0

	//get the winning teams colour
	PuckType winningTeam = m_puckArray[i].getTeam();

	while(i >= 0 && m_puckArray[i].getTeam() == winningTeam) {	//while i is non-negative and the current puck is a winning colour
		i--;
		//this while loop will finish where m_puckArray[i].m_colour == the losing colour
	}

	//we add 1 to i because the while loop end on the losing colour
	int winningPucks = m_pucks - i+1;	//find the number of winning pucks

	return winningPucks;
}

PuckType PuckManager::getWinner() {
	sortByZValue();	//sort the array so that Pucks are ordered by their z values (smallest first)

	int i = m_pucks - 1;	//-1 because first puck is at index 0 in array

	return m_puckArray[i].getTeam();
}



void PuckManager::sortByZValue() {
	std::sort( m_puckArray, m_puckArray + m_pucks );
}