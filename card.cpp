/* File: card.cpp
 * Course: CS216-001
 * Project 2
 * Purpose: the implementation of member functions for the Card class.
 *
 */

#include "card.h"

// Default constructor marks card as invalid
Card::Card() 
{
	suit = Invalid;
	point = 0;
}

// Alternate constructor
Card::Card(cSuits s, cPoints p) 
{
	suit = s;
	point = p;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other)
{
	if (this->point < other.point){
		return -1;
	} else if (this->point > other.point){
		return 1;
	} else { 
		return 0;
	}
}

// Display a description of the Card object to standard output
// The output should look like:
//   
void Card::print() 
{

	int pointval = this->point;
	if(pointval  > 10){
		char letter;
		if(pointval == 11){
			letter = 'J';
		} else if (pointval == 12){
			letter = 'Q';
		} else if (pointval == 13){
			letter = 'K';
		} else {
			letter = 'A';
		}

		if(suit == Heart){
                        cout << HEART << " " << letter << " " << HEART << endl;
                } else if (suit == Spade) {
                        cout << SPADE << " " << letter << " " << SPADE << endl;
                } else if (suit == Diamond) {
                        cout << DIAMOND << " " << letter << " " << DIAMOND << endl;
                } else if (suit == Club){
                        cout << CLUB << " " << letter << " " << CLUB << endl;
                } else {
			cout << "Invalid card value!" << endl;
		}

	} else {
		if(suit == Heart){
			cout << HEART << " " << pointval << " " << HEART << endl;
		} else if (suit == Spade) {
			cout << SPADE << " " << pointval << " " << SPADE << endl;
		} else if (suit == Diamond) {
			cout << DIAMOND << " " << pointval << " " << DIAMOND << endl;
		} else {
			cout << CLUB << " " << pointval << " " << CLUB << endl;
		}
	}
}
