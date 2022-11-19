#include <iostream>
#include "player.h"
using namespace std;

Player::Player(){
    _isBot = false;
    _cartasId[2];
    _posCartas[0] = false;
    _posCartas[1] = false;
}

bool Player::isBot(){
    if (_isBot == true){
        return true;
    }
    else{
        return false;
    }
}

void Player::addCard(int x){
    if(_posCartas[0] == false){
        _cartasId[0] = x;
        _posCartas[0] = true;
    }
    else if(_posCartas[1] == false){
        _cartasId[1] = x;
        _posCartas[1] == true;
    }
}

int Player::getJaPagou(){
    return _jaPagou;
}

void Player::setValorFichas(int x){
    _valorFichas = x;
    return;
}

void Player::removeValorFichas(int x){
    _valorFichas -= x;
    return;
}

void Player::setJaPagou(int x){
    _jaPagou = x;
}

int Player::getValorFichas(){
    return _valorFichas;
}

void Player::setEstaNaRodada(bool x){
    if(x){
        _estaNaRodada = true;
    }
    else{
        _estaNaRodada = false;
    }
    return;
}