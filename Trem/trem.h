#ifndef TREM_H
#define TREM_H

#include <QThread>


/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int,int,int);  //construtor
    Trem(int,int,int, int);  //construtor
    Trem();
    void run();         //função a ser executada pela thread
    void changeVelocity(int);
    void changeStop(bool);

//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int xinicio;           //posição X inicial do trem na tela
   int yinicio;           //posição Y inicial do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
   bool isStopped; //identifica se o trem está parado
};

#endif // TREM_H