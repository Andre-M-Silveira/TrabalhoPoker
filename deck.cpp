#include <iostream>
#include "deck.h"
#include "player.h"
#include "mesa.h"

Deck::Deck(){
    for(int i = 0; i < 52; i++){
        _vetorInDeck[i] = true; 
    }
    _cartasNoDeck = 52;
    _cartasForaDoDeck = 0;

}

int Deck::sortCard(){
    int idCard = rand()%52;
    while(_vetorInDeck[idCard] == false){
        idCard = rand()%52;
    }
    _vetorInDeck[idCard] = false;
    return idCard;
}

void getBackCard(Player &x);
    int getBackCard(Mesa &x);
    int getNipe();
    int getValue();