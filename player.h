//playerH

class Player{
    bool _isBot;
    int _cartasId[2];
    bool _posCartas[2];
    int _valorFichas = 1000;
    int _jaPagou = 0;
    bool _estaNaRodada = true;

    public:
    
    
    //construtor
    Player();
    bool isBot();

    //metodos
    void addCard(int x);
    int getJaPagou();
    void setJaPagou(int x);
    void removeValorFichas(int x);
    int getValorFichas();
    void setValorFichas(int x);
    void setEstaNaRodada(bool x);
};