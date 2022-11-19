/*
Criação do arquivo 17/10/22 - André Silveira

Inicio do projeto 21/10/22 - André Silveira{
    Primeiro problema, o ideal seria criar uma função que cuida das cartas de todos e do próprio baralho, logo essa
    função deveria gerenciar os dois ao mesmo tempo, tanto as cartas do "Deck" quanto dos "Players" quanto da "Mesa"
    porém essa função ficaria dentro do da classe Deck, porém essa classe teria que acessar a mão de diferentes
    classes, Mesa e Players
    Soluções possíveis
    1 criar duas funções uma pra mexer na "mao" da mesa e outra pra mexer nas dos jogadores{
        vantagens iniciais{
            segue mais perto da proposta da criação de classes e variaveis criadas na apresentação do projeto
        }
    }
    2 jogar a mao da mesa assim como as maos dos jogadores pra dentro da classe{
        vantagens iniciais{
            Fazer uma função só
            Não ficar referenciando um monte de objetos fora da classe
        }
    }
    acabei optando por fazer da primeira forma, depois penso em mudar
    porém decidi iniciar o deck (na vdd todas as variáveis da classe jogo)aqui no main mesmo,
    acho que fica mais simples do que iniciar a partir de outra classe
}

*/

#include <iostream>
#include "deck.h"
//#include "jogo.h" retirado do projeto
#include "player.h"
#include "mesa.h"

using namespace std;

//variaveis controladorasMesa mesa;
//variaveis que eram incialemnte da classe Jogo{
int _nPlayers;
int _nBots;
int _placar[10];
Player player[10];
//}
int fechar = 0; //fecha o programa, vai ser util quando passarmos o jogo pra alguma biblioteca de jogos que tem intereação com o teclado
int quemJogaPrimeiro = 0;
int quemJoga = 0;
bool menuInicial = true;
bool inicioDoJogo = false;

//inciação das classes
Deck deck;
Mesa mesa;


//inciação de variáveis necessárias para o jogo
int turno = 0;
const int tempoDasEscolhas = 10;//vai ser util quando tiver um timer

//funções
int decideQuemJogaPrimeiro(){
    return (rand()%_nPlayers);
}

bool isValid(int x){
    if(x == 1 | x == 3){
        return true;
    }
}


void rodadaDeOpc(){
    //inicialização dos counters necessários
    int contSemAlteracoes = 0;//serve pra ver se a mesa inteira já terminou os seus movimentos
    int resposta = 0;
    int valorPorPessoaDaRodada = mesa.getApostaMinima();
    while (contSemAlteracoes < _nPlayers)
    {
        //todo player tem 3 opções, aumentar, pagar, sair então a ideia é apresentar pro player uma função que faz essas perguntas pra ele ou pro bot
        if(player[quemJoga].isBot()){

        }
        else{ 
            if(player[quemJoga].getValorFichas() < mesa.getApostaAtual()){
                while (resposta != 1 | resposta != 3){
                    cout << "O que você deseja fazer?" << endl 
                    << "Para pagar digite '1'" << endl
                    << "Para fugir digite '3'" << endl;
                    cin >> resposta;
                }
            }
            else{
                while (resposta != 1 | resposta != 2 | resposta != 3){
                    cout << "O que você deseja fazer?" << endl 
                    << "Para pagar digite '1'" << endl
                    << "Para aumentar digite '2'" << endl
                    << "Para fugir digite '3" << endl;
                    cin >> resposta;
                } 
            }
            if(resposta == 1){
                //conferir quanto ele já pagou . valia 10, jogador anterior aumentou em cinco, agora ele tem que pagar o que ele já tinha pagado mais 5
                if(valorPorPessoaDaRodada <= player[quemJoga].getValorFichas() + player[quemJoga].getJaPagou()){
                    mesa.addApostaAtual(valorPorPessoaDaRodada - player[quemJoga].getJaPagou()); //altera valor da rodada
                    player[quemJoga].removeValorFichas(valorPorPessoaDaRodada - player[quemJoga].getJaPagou());
                    player[quemJoga].setJaPagou(valorPorPessoaDaRodada);   
                }
                else{
                    mesa.addApostaAtual(player[quemJoga].getValorFichas());
                    player[quemJoga].setJaPagou(player[quemJoga].getJaPagou() + player[quemJoga].getValorFichas()); 
                    player[quemJoga].removeValorFichas(player[quemJoga].getValorFichas());
                    
                }
                

            }
            else if(resposta == 2){
                int aumento;
                while(true){
                    cout << "Você possui " << player[quemJoga].getValorFichas() << endl;
                    cout << "Quanto você deseja aumentar? ";
                    cin >> aumento;
                    if(valorPorPessoaDaRodada + aumento <= player[quemJoga].getValorFichas()){
                        break;
                    }
                    cout << "Valor invalido!!! Você nao possui esse valor." << endl;
                    cout << "Favor colocar valor menor ou igual ao que você possui.";
                }
                mesa.addApostaAtual(valorPorPessoaDaRodada - player[quemJoga].getJaPagou()); //altera valor da rodada
                player[quemJoga].removeValorFichas(valorPorPessoaDaRodada - player[quemJoga].getJaPagou());
                player[quemJoga].setJaPagou(valorPorPessoaDaRodada);
            }
            else if(resposta == 3){
                player[quemJoga].setEstaNaRodada(false);
            }
        }
    }   
}

void destribuirCartas(){
    for(int i = 0; i < _nPlayers; i++){
        for(int h = 0; h < 2; h++){
            player[i].addCard(deck.sortCard());
        }

    }

}


int main(){
    while(fechar == 0){
        if(menuInicial){
            /*
            Ações do menu principal, escolher algumas informações essenciais para o incio correto das variáveis do jogo
            */
            cout << "Bem vindo!\nEsse programa é um jogo de Poker desenvolvido por André Silveira e Gabriel Moreira\nO número de jogadores máximos são 10, contando jogadores reais e bots.\nquantos jogadores totais (jogadores e bots) você quer no seu jogo?" << endl;
            cin >> _nPlayers;
            cout << "Quantos bots deseja adicionar?" << endl;
            cin >> _nBots;
            /*
            cout << "Quanto tempo por escolha" << endl; //achamos melhor criar uma constante que não será permitido ao jogador alterar
            cin >> tempoDasEscolhas;
            */

            inicioDoJogo = true;
        }
        if(inicioDoJogo){
            quemJogaPrimeiro = decideQuemJogaPrimeiro();
            
        }
        if(turno == 0){
            quemJoga = quemJogaPrimeiro;
            destribuirCartas();
            rodadaDeOpc();
        }
    }
}