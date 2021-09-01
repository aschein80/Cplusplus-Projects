#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Card.h"
#include "Deck.h"
#include "Deck.cpp"
/**
*Alexandre Schein
*CECS 282
*Solitaire Prime- Prog 1
*2/13/19
**/

using namespace std; 


bool isPrime(int x){
	
	if (x<2){	//less than 2 is not prime
		return false;
	}
	else if (x==2){	//2 is a prime number
		return true;
	}
	else if(x%2==0){	//divides by 2 evenly-not prime
		return false;
	}
	else{
		for(int y=3; y<x; y++){	//beginning at 3 until the number
			if (x%y==0){
				return false;
			}
			else{
				return true;
			}
		}
	}	
}

int main()
{
	string user_selection;		//taking in user selection
	
	Deck mydeck= Deck();
	
	cout<<"Welcome to Solitaire Prime!" <<endl;		//greeting/option display
	cout<< "1) New Deck "<<endl;	
	cout<< "2) Display Deck "<<endl;
	cout<< "3) Shuffle Deck "<<endl;
	cout<< "4) Play Solitaire Prime"<<endl;
	cout<< "5) Exit"<<endl;

	cout<<"What would you like to do";
	cout<<endl;
	cin>>user_selection;
	
	while (user_selection != "5"){
		
		if (user_selection == "1")	//new deck
		{
			cout<<"You chose: New Deck"<<endl;
			mydeck.refreshDeck();
			//Deck();
			//refreshDeck();
		}
		
		else if(user_selection == "2") //display deck
		{
			cout<<"You chose: Display Deck."<<endl;
			mydeck.showDeck();
			//showDeck();
						
		}
		
		else if (user_selection == "3")	//shuffle deck
		{
			cout<<"You chose: Shuffle Deck"<<endl;
			mydeck.shuffle();
			
		}
		
		else if (user_selection == "4")	//playing solitaire prime
		{
			cout<<"Playing Solitaire Prime"<<endl;
			
			Card card;	
			//Card card1;	
			int piles=0;
			int sum=0;
				
			while(mydeck.cardsLeft()!=0)
			{
				card = mydeck.deal(); //taking top card 
				card.showCard();	//face up
				sum += card.getValue();	//adding the value of the cards
				
				if (isPrime(sum) == true){
					piles++; //discard pile
					cout<<"Prime:"<<sum<<endl; //print prime sum
					sum=0; //instruction 1
					
				}
//				else if(isPrime(sum)==false){
//					pile++;
//				}
			}
				
				if (sum==0){ //if most recent sum reset to 0 (indicates was true)
					cout<<"Winner in "<<piles<<" piles\n";
					cout<<endl;
				}
				else{	//did not reset
					cout<<"Loser\n";
					cout<<endl;
				}
		}
		
	cout<<"Please select what you would like to do now...\n";
	//cout<<"Welcome to Solitaire Prime!" <<endl;
	cout<< "1) New Deck "<<endl;
	cout<< "2) Display Deck "<<endl;
	cout<< "3) Shuffle Deck "<<endl;
	cout<< "4) Play Solitaire Prime"<<endl;
	cout<< "5) Exit"<<endl;
	
	cin>>user_selection;
	if(user_selection == "5"){			
		cout<<"You chose: Exit"<<endl;
		cout<<"Terminating, goodbye!\n";
		break;
	}
	}

	return 0;
	
}
