//mesa.cpp
#include "mesa.h"

void Mesa::setApostaAtual(int x){
    _apostaAtual = x;
    return;
}

void Mesa::addApostaAtual(int x){
    _apostaAtual += x;
}

int Mesa::getApostaAtual(){
    return _apostaAtual;
}

int Mesa::getApostaMinima(){
    return _apostaMinima;
}