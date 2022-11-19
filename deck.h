

/*id das cartas
x/13 = 0 nipe de copas
x/13 = 1 nipe de ouros
x/13 = 2 nipe de espada
x/13 = 3 nipe de paus
pos 0 carta 2
pos 1 carta 3
...
pos 10 j, q, k, As

*/


class Deck{
    bool _vetorInDeck[52];
    int _cartasNoDeck;
    int _cartasForaDoDeck;
public:
    //construtor
    Deck();

    //methods 
    int getNipe(int id);
    int getValue(int id);
    int sortCard();
    void getBackCard(Player &x);
    int getBackCard(Mesa &x);
    int getNipe();
    int getValue();
};

