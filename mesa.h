#include "deck.h"
#include "fichas.h"
#include "deck.h"

class Mesa{
    Fichas fichas;
    Deck deck;
    int _cartas[5];
    int _apostaAtual = 0;
    int _apostaMinima = 10;
    
public:
    //metodos
    void setApostaAtual(int x);
    void addApostaAtual(int x);
    int getApostaAtual();
    int getApostaMinima();

    
};