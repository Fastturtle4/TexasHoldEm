/* File: rank.cpp
 * Course: CS216-001
 * Project: Programming Project 2
 */

#include <iostream>
#include "rank.h"	//include header file

using namespace std;

// Default constructor.
Rank::Rank(){
	point = 0;
	kind = NoRank;		
} 

// Alternate constructor.
Rank::Rank(hRanks r, rPoints p){
	point = p;
	kind = r;
}
 
// Display a description of the hand-ranking category to standard output.
void Rank::print(){
	string name;			//placeholder for point value/name
	if(point==11){
		name = "J";
	} else if (point==12){		//determine which value to use according to point value
		name = "Q";
	} else if (point==13){
		name = "K";
	} else if (point==14){
		name = "A";
	} else if (point==10){
		name = "10";
	} else if (point==9){
		name = "9";
	} else if (point==8){
		name = "8";
	} else if (point==7){
		name = "7";
	} else if (point==6){
		name = "6";
	} else if (point==5){
		name = "5";
	} else if (point==4){
		name = "4";
	} else if (point==3){
		name = "3";
	} else if (point==2){
		name = "2";
	}


	if(kind==HighCard){
		cout << "HighCard"  << "(" << name << ")" << endl;	//print rank and value
	} else if (kind==Pair){
		cout << "Pair" << "(" << name << ")" << endl;
	} else if (kind==ThreeOfAKind){
		cout << "ThreeOfAKind" << "(" << name << ")" << endl;
	} else if (kind==Straight){
		cout << "Straight" << "(" << name << ")" << endl;
	} else if (kind==Flush){
		cout << "Flush" << "(" << name << ")" << endl;
	} else if (kind==FullHouse){
		cout << "FullHouse" << "(" << name << ")" << endl;
	} else if (kind==FourOfAKind){
		cout << "FourOfAKind" << "(" << name << ")" << endl;
	} else if (kind==StraightFlush){
		cout << "StraightFlush" << "(" << name << ")" << endl;
	} else if (kind==NoRank){
		cout << "NoRank" << "(" << name << ")" << endl;
	}
}
