#include "trem.h"
#include <QtCore>
#include <iostream>
#include <QMutex>
QMutex mut; //ou mut.unlock()

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->xinicio = x;
    this->yinicio = y;
    this->velocidade = 100;
    this->isStopped = false;
}

Trem::Trem(){

}

Trem::Trem(int ID, int x, int y, int v){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->xinicio = x;
    this->yinicio = y;
    this->velocidade = v;
    this->isStopped = false;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
//        switch(ID){
//        case 1:     //Trem 1
//            if (y == 30 && x <330)//direita
//                x+=10;
//            else if (x == 330 && y < 150)//sobe
//                y+=10;
//            else if (x > 60 && y == 150)//esquerda
//                x-=10;
//            else//desce
//                y-=10;
//            emit updateGUI(ID, x,y);    //Emite um sinal
//            break;
//        case 2: //Trem 2
//            if (y == 30 && x <600)//direita
//                x+=10;
//            else if (x == 600 && y < 150)//sobe
//                y+=10;
//            else if (x > 330 && y == 150)//esquerda
//                x-=10;
//            else//desce
//                y-=10;
//            emit updateGUI(ID, x,y);    //Emite um sinal
//            break;
//        default:
//            break;
//        }
        switch(ID){
        case 1:     //Trem 1

            if (y == yinicio && x <(xinicio+270)){//direita
                while (x <(xinicio+270)) {
                    x+=10;

                    msleep(velocidade);
                    emit updateGUI(ID, x,y);
                }
            }
            else if (x == (xinicio+270) && y < (yinicio + 120))//sobe
                while (y < (yinicio + 120)) {
                    y+=10;

                    msleep(velocidade);
                    emit updateGUI(ID, x,y);
                }
            else if (x > xinicio && y == (yinicio + 120))//esquerda 2 e 1
                while (x > xinicio) {
                    x-=10;

                    msleep(velocidade);
                    emit updateGUI(ID, x,y);
                }
            else//desce 0
                while (y > yinicio) {
                    y-=10;

                    msleep(velocidade);
                    emit updateGUI(ID, x,y);
                }
            emit updateGUI(ID, x,y);
            break;
        case 2: //Trem 2
            if (y == yinicio && x <(xinicio+270))//direita
                x+=10;
            else if (x == (xinicio+270) && y < (yinicio + 120))//sobe 0
                y+=10;
            else if (x > xinicio && y == (yinicio + 120))//esquerda 4 e 3
                x-=10;
            else//desce
                y-=10;
            emit updateGUI(ID, x,y);
            break;
        case 3: //Trem 3
            if (y == yinicio && x <(xinicio+270))//direita nada e 1
                x+=10;
            else if (x == (xinicio+270) && y < (yinicio + 120))//sobe
                y+=10;
            else if (x > xinicio && y == (yinicio + 120))//esquerda
                x-=10;
            else//desce 5
                y-=10;
            emit updateGUI(ID, x,y);
            break;
        case 4: //Trem 4
            if (y == yinicio && x <(xinicio+270))//direita 2 e 3
                x+=10;
            else if (x == (xinicio+270) && y < (yinicio + 120))//sobe 5
                y+=10;
            else if (x > xinicio && y == (yinicio + 120))//esquerda
                x-=10;
            else//desce 6
                y-=10;
            emit updateGUI(ID, x,y);
            break;
        case 5: //Trem 5
            if (y == yinicio && x <(xinicio+270))//direita 4 e nada
                x+=10;
            else if (x == (xinicio+270) && y < (yinicio + 120))//sobe 6
                y+=10;
            else if (x > xinicio && y == (yinicio + 120))//esquerda
                x-=10;
            else//desce
                y-=10;
            emit updateGUI(ID, x,y);
            break;
        default:
            break;
        }
       // std::cout << ID << " " << x << " " << y << std::endl;

        msleep(velocidade);
    }
}

void Trem::changeVelocity(int v){
    int newVelocity = 200-v;
    this->velocidade = newVelocity;
    if(newVelocity >=200 )
        changeStop(true);
    else if(newVelocity <=0 )
        changeStop(false);
}

void Trem::changeStop(bool b){
    this->isStopped = b;
}



