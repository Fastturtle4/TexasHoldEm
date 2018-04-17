/* File: pokerhand.cpp
 * Course: CS216-001
 * Project: Programming Project 2
 **** YOU MAY ADD MEMBER FUNCTIONS OR HELPER FUNCIONS ***
 */

#include "pokerhand.h"		//include necessary libraries
#include "deck.h"
#include "SortedLinkedList.h"
using namespace std;

//Default constructor.
PokerHand::PokerHand(){
	hand_rank = Rank(Rank::NoRank,0);
}

// It should store the FIVE cards
void PokerHand::setPokerHand(Card in_hand[], int size){
	if(size!=5){
		cout << "Invalid number of cards!" << endl;	//if size isn't 5, let user know there is an error
	}
	for (int i=0; i< 5; i++) {				//populate cards private function with input
			cards[i]=in_hand[i];
       	}
	sort();			//sort newly created hand
	if(isStraightFlush())	//determine rank using is-bool functions, and exit function once rank is found
		return;
	if (isFourOfAKind())
		return;
	if (isFullHouse())
		return;
	if (isFlush())
		return;
	if (isStraight())
		return;
	if (isThreeOfAKind())
		return;
	if (isPair())
		return;
	if (isHighCard())
		return;      
}

// Compare this hand versus otherHand
int PokerHand::compareHand(const PokerHand &otherHand){				//-1 = lose, 1 = win, 0 = tie
	if (this->hand_rank.kind < otherHand.hand_rank.kind){			//compare kind
		 return -1;
	} else if (this->hand_rank.kind > otherHand.hand_rank.kind){
		 return 1;
	} else if (this->hand_rank.kind == otherHand.hand_rank.kind){		//if kind is the same, compare point values
		 if (this->hand_rank.point < otherHand.hand_rank.point){
		 	return -1;
		} else if (this->hand_rank.point > otherHand.hand_rank.point){
		 	return 1;
		} else {
			return 0;						//if kind and points are the same, it is a tie
		}
	} else {
		return 0;
	}
}

// Prints out the five cards and its rank to standard output.
void PokerHand::print(){
	for(int i =0; i<5;i++){
		cards[i].print();		//print each card in hand
	}
	cout << "Its rank is: ";
	getRank().print();			//print the rank using rank print function
	
}
        
// Return the rank of this hand
Rank PokerHand::getRank() const{
	return hand_rank;
}

// Returns true if the hand is a StraightFlush otherwise returns false
bool PokerHand::isStraightFlush(){
	if(isAllOneSuit() & isSequence()){
		hand_rank.kind = Rank::StraightFlush;	//if it is all same suit and in sequence, set rank as straight flush
		hand_rank.point = cards[0].point;
		return true;
	} else {
		return false;
	}
}

// Returns true if the hand is a Four of a Kind
bool PokerHand::isFourOfAKind(){
	if((cards[0].point==cards[3].point)||(cards[1].point==cards[4].point)){	//if the first card is the same as the fourth
		hand_rank.kind=Rank::FourOfAKind;				//or the second card is the same as the last
		hand_rank.point=cards[1].point;					//then set as four of a kind
		return true;
	} else {
		return false;
	}
}

// Returns true if the hand is a Full House
bool PokerHand::isFullHouse(){
	if((cards[0].point==cards[2].point)&(cards[3].point==cards[4].point)){	//if the first card is the same as the third and the fourth=fifth
		hand_rank.kind=Rank::FullHouse;					//or if the first=second and third=last
		hand_rank.point=cards[0].point;					//set as full house
		return true;
	} else if ((cards[2].point==cards[4].point)&(cards[0].point==cards[1].point)){
		hand_rank.kind=Rank::FullHouse;
		hand_rank.point=cards[2].point;
		return true;
	} else {
		return false;
	}
}

// Returns true if the hand is a Flush
bool PokerHand::isFlush(){
	if(isAllOneSuit() & !isSequence()){		//if hand is all of the same suit but not in order, set as flush
		hand_rank.kind=Rank::Flush;
		hand_rank.point=cards[0].point;
		return true;
	} else {
		return false;
	}
}

//Returns true if the hand is a Straight
bool PokerHand::isStraight(){
	if(isSequence()){
		hand_rank.kind=Rank::Straight;		//if hand is in sequence, set as straight
		hand_rank.point=cards[0].point;
		return true;
	} else {
		return false;
	}
}

// Returns true if the hand is a Three of a Kind
bool PokerHand::isThreeOfAKind(){
	if((cards[0].point==cards[2].point)&(cards[0].point!=cards[3].point)){	//if first=third and first!=fourth to exclude fourofkind 
		hand_rank.kind=Rank::ThreeOfAKind;				//or if three middle cards are equal, make sure edges arent
		hand_rank.point=cards[0].point;					//or if last three, make sure second!=third, set threeofakind
        return true;
	} else if ((cards[1].point==cards[3].point)&(cards[0].point!=cards[3].point)&(cards[1].point!=cards[4].point)) {
		hand_rank.kind=Rank::ThreeOfAKind;
		hand_rank.point=cards[1].point;
        return true;
	} else if ((cards[2].point==cards[4].point)&(cards[1].point!=cards[2].point)) {
		hand_rank.kind=Rank::ThreeOfAKind;
		hand_rank.point=cards[2].point;
        return true;
	} else {
		return false;
	}
}

// Returns true if the hand is a Pair (we consider either one pair or two pairs is a Pair)
bool PokerHand::isPair(){
	if((cards[0].point==cards[1].point)&(cards[3].point==cards[4].point)&(cards[2].point!=cards[3].point)){	//determines various cases of pairs,
	hand_rank.kind=Rank::Pair;										//making sure to exclude other cases
	hand_rank.point=cards[0].point;
	return true;
	} else if((cards[1].point==cards[2].point)&(cards[0].point!=cards[1].point)&(cards[2].point!=cards[3].point)) {
	hand_rank.kind=Rank::Pair;
	hand_rank.point=cards[1].point;
	return true;
	} else if((cards[2].point==cards[3].point)&(cards[1].point!=cards[2].point)&(cards[3].point!=cards[4].point)) {
	hand_rank.kind=Rank::Pair;
	hand_rank.point=cards[2].point;
	return true;
	} else if((cards[3].point==cards[4].point)&(cards[2].point!=cards[3].point)) {
	hand_rank.kind=Rank::Pair;
	hand_rank.point=cards[3].point;
	return true;
	} else if((cards[0].point==cards[1].point)&(cards[1].point!=cards[2].point)) {
	hand_rank.kind=Rank::Pair;
	hand_rank.point=cards[0].point;
	return true;
	} else {
	return false;
	}
}

// Returns true if the hand is a High Card
bool PokerHand::isHighCard(){
	if(!(isPair() | isStraight() | isFlush() | isFullHouse() | isFourOfAKind() | isStraightFlush())){	//if no other case is met, set highcard
		hand_rank.kind = Rank::HighCard;
		hand_rank.point = cards[0].point;
		return true;
	} else {
		return false;
	}
}

// to help sort the FIVE cards in decreasing order by card points                                       
void PokerHand::sort(){
	SortedLinkedList sort;		//create sort object, use sort function to sort cards in hand
	for (int i = 0; i < 5; i++){
		sort.insert(cards[i]);
	}
	vector<Card>sortvector = sort.access();	//convert sorted cards into a vector for ease of use and
	for (int i = 0; i < FIVE; i++){		//update cards[] with new sorted hand
                cards[i]=sortvector[i];
        }
}                                    
                                                       
// to help decide if FIVE cards are all of one suit
bool PokerHand::isAllOneSuit(){
	if((cards[0].suit==cards[1].suit)&(cards[1].suit==cards[2].suit)&(cards[2].suit==cards[3].suit)&(cards[3].suit==cards[4].suit)){
		return true;				//check if all card suits are the same
	} else {
		return false;
	}
}
        
// to help decide if FIVE cards are in a continuous sequence
bool PokerHand::isSequence(){
	if((cards[0].point==cards[1].point+1)&(cards[1].point==cards[2].point+1)&(cards[2].point==cards[3].point+1)&(cards[3].point==cards[4].point+1)){
		return true;	//check if each card is one greater than the next
	} else {
		return false;
	}	
}
