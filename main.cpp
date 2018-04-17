//Paul Barrett
//CS216 Section 1
//Project 2
//Simple Texas Holdem

#include <iostream>
#include "deck.h"
#include "pokerhand.h"	//include necessary libraries
#include "card.h"

using namespace std;
// avoid magic numbers
const int SEVEN = 7;
const int FIVE = 5;
const int TWO = 2;
//find best five card combo from original 7
PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards);

int main(){
	
	char choice;			//collect user input to quit program or not
	Deck pokerDeck;			//define initial deck
	pokerDeck.createDeck();	//create deck

	do{									//loop menu
		pokerDeck.shuffleDeck();		//shuffle deck
		PokerHand playerhand;			//player's hand
		PokerHand computerhand;			//computer's hand
		Card playercards[2];			//player's first 2 cards
		Card computercards[2];			//computer's first 2 cards
		Card windowcards[FIVE];			//shared window cards
		vector<Card>player7(SEVEN);		//vector of player's 7 possible cards
		vector<Card>computer7(SEVEN);	//vector of computers's 7 possible cards
		
		for(int i=0; i<4; i++){
			playercards[i]=pokerDeck.deal_a_card();		//deal 2 cards to player and computer
			computercards[i]=pokerDeck.deal_a_card();
		}
		for(int i=0; i<FIVE; i++){						//deal 5 shared window cards
			windowcards[i]=pokerDeck.deal_a_card();
		}
		for(int i=0; i<FIVE; i++){
			player7[i]=windowcards[i];					//add 5 window cards to vector 
			computer7[i]=windowcards[i];				//of 7 possible cards for each
		}
		player7[5]=playercards[0];						//add remaining 2 personal cards
		player7[6]=playercards[1];						//to each vector for total of 7
		computer7[5]=computercards[0];
		computer7[6]=computercards[1];		

		cout << "The cards in your hand are:" << endl;	//print player's cards
		playercards[0].print();
		playercards[1].print();

		cout << "\nThe FIVE cards on the deck to share are:" << endl;	//print shared cards
		for(int i=0; i<5; i++){
			windowcards[i].print();
		}

		cout << "\nThe cards in the computer's hand are:" << endl;		//print computer's cards
		computercards[0].print();
		computercards[1].print();

		cout << "\nPlayer 1:" << endl;		
		playerhand = best_FIVE_out_of_SEVEN(player7);				//print player's best hand and rank
		cout << "Computer:" << endl;
		computerhand = best_FIVE_out_of_SEVEN(computer7);			//print computer's best hand and rank

		int winorlose = playerhand.compareHand(computerhand);		//use comparehand to determine who won
		if(winorlose>0){											//and print outcome
			cout << "Congratulations, you win the game!" << endl;
		} else if (winorlose<0){
			cout << "Sorry, the computer wins the game!" << endl;
		} else {
			cout << "It's a tie!" << endl;
		}

		cout << "\nDo you want to play again? Press 'Q' or 'q' to quit" << endl;	//prompt user to play again or quit
		cin >> choice;
	}while(choice!='q' && choice!='Q');		//end if user enters Q or q

	return 0;
}

PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards)		//definition for best five out of 7 function
{    

    PokerHand bestH;
    PokerHand cardsH;

    // check if the parameter is valid
    if (cards.size() != SEVEN)
    {
        cout << "Invalid Cards, we need SEVEN cards!" << endl;
        return cardsH; // return a PokerHand object by default constructor
    }

    // Consider all possible ways of dropping two cards
    // from all seven cards 
    // i is the index of the first card dropped
    // and j is the index of the second card dropped.
    // There are 21 different ways to pick 5 cards out of 7
    for (int i=0; i < SEVEN; i++) 
    {
        for (int j=i+1; j < SEVEN; j++) 
        {
            Card pick[FIVE];
            int index = 0;

            // Iterate over all seven cards and assign them to the pick[] array
            // exclude cards with index numbers of #i and #j.
            for (int k=0 ; k < SEVEN ; k++) 
            {
                if (k == i || k == j) 
                    continue;
                pick[index] = cards[k];
                index++;
            }
            
            // create a PokerHand with pick[]
            cardsH.setPokerHand(pick, FIVE);

            // Check to see if current pick is better than
            // the best you have seen so far
            if (bestH.compareHand(cardsH) < 0)
            {
                bestH = cardsH ;
            }
        }
    }

    // Now bestH holds the best poker hand among all 21 poker hands
    cout << "*** Best five-card hand ***" << endl;
    bestH.print();
    cout << endl << endl;
    return bestH;
}
