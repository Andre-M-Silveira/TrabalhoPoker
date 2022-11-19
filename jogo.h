#include "mesa.h"
#include "player.h"

struct Jogo{
    Mesa mesa;
    int _nPlayers;
    Player player[10];
    int _placar[10];

};