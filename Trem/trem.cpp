#include "trem.h"
#include <QtCore>
#include <iostream>
#include <QMutex>
static QMutex critic0, critic1, critic2, critic3, critic4, critic5, critic6;
static QSemaphore *deadlock[3];
//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->xinicio = x;
    this->yinicio = y;
    this->velocidade = 100;
    this->isStopped = false;
    primeira = true;
    //inicializando os semaforos

    if( ID == 1){
        deadlock[0] = new QSemaphore(2);
        deadlock[1] = new QSemaphore(2);
        deadlock[2] = new QSemaphore(2);
    }
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
    primeira = true;
    //inicializando os semaforos
    if( ID == 1){
        deadlock[0] = new QSemaphore(2);
        deadlock[1] = new QSemaphore(2);
        deadlock[2] = new QSemaphore(2);
    }
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
      switch(ID){
        case 1://Trem 1
            if (y == yinicio && x <(xinicio+270)){//direita
                while (x <390) {//indo para a direita até o ponto crítico 0
                   direita();
                }
                deadlock[2]->acquire();
                critic0.lock();
                while (x<410){//entrando no ponto crítico 0
                    direita();
                }

            }
            if (x == 410 && y <150 ){//desce
                while (y<130){//enquanto estiver no ponto crítico 0 e nã
                    desce();
                }
                deadlock[0]->acquire();
                critic2.lock();
                while (y < 150){ //entrando no ponto critico 2
                    desce();
                }
            }

            if (x > xinicio && y == 150){//esquerda
                while (x > 390) {//saindo do ponto critico 0
                    esquerda();
                }
                critic0.unlock();
                while(x > 290){// enquanto estiver no ponto critico 2
                    esquerda();
                }

                critic1.lock();
                while (x > 250) {//saindo do ponto critico  2
                    esquerda();
                }
                critic2.unlock();
                if(deadlock[2]->available() <2)
                    deadlock[2]->release();
                while (x > xinicio) {//percorrendo o ponto critico 1
                    esquerda();
                }
            }
            if(x==xinicio && y > yinicio){//sobe
                while (y > 130) {//saindo do ponto critico 1
                    sobe();
                }
                critic1.unlock();
                if(deadlock[0]->available() <2)
                    deadlock[0]->release();
                while (y > yinicio) {
                    if(!isStopped){
                        y-=10;
                        msleep(velocidade);
                        emit updateGUI(ID, x,y);
                    }
                }
            }
            break;
        case 2: //Trem 2
          if (y == yinicio && x <(xinicio+270)){//direita
              while (x < 430) {//saindo do ponto crítico 0
                 direita();
              }
              critic0.unlock();
              if(deadlock[2]->available()<2)//se não for a primeira execução
                  deadlock[2]->release();

              while (x < 680){//
                  direita();
              }

          }

          if (x == 680 && y < 150 ){//desce
              while (y<130){//enquanto não chegar no ponto crítico 4
                  desce();
              }
              deadlock[1]->acquire();
              critic4.lock();
              while (y < 150){ //entrando no ponto critico 4
                  desce();
              }
          }

          if (x > xinicio && y == 150){//esquerda
              while (x > 560) {//andando no ponto critico 4
                  esquerda();
              }
              deadlock[2]->acquire();
              critic3.lock();
              while(x > 520){// entrando no ponto critico 3
                  esquerda();
              }
              critic4.unlock();
              while (x > 430) {//enquanto não entrar no ponto critico 0
                  esquerda();
              }
              critic0.lock();
              while (x > 410) {//entrando no ponto critico 0
                  esquerda();
              }
          }
          if(x==xinicio && y > yinicio){//sobe
              while (y > 130) {//saindo do ponto critico 3
                  sobe();
              }
              critic3.unlock();
              if(deadlock[1]->available() <2)
                deadlock[1]->release();
              while (y > yinicio) {//andando no ponto critico 0
                  sobe();
              }
          }
          break;
        case 3: //Trem 3
          if (y == yinicio && x <(xinicio+270)){//direita
              while (x < 120) {//indo at ponto crítico 1
                 direita();
              }
              deadlock[0]->acquire();
              critic1.lock();
              while (x < 250){//andando no ponto critico 1
                  direita();
              }
              critic5.lock();
              while (x < 270) {//entrando no ponto critico 5
                  direita();
              }
          }

          if (x == 270 && y < 270 ){//desce
              while (y < 170){//saindo do ponto crítico 1
                  desce();
              }
              critic1.unlock();
              while (y < 270){ //andando no ponto critico
                  desce();
              }
          }

          if (x > xinicio && y == 270){//esquerda
              while (x > 250) {//saindo do ponto critico 5
                  esquerda();
              }
              critic5.unlock();
              if(deadlock[0]->available() <2)
                deadlock[0]->release();
              while(x > 0){// andando
                  esquerda();
              }
          }

          if(x==xinicio && y > yinicio){//sobe
              while (y > 150) {//subindo
                  sobe();
              }
          }
          break;
        case 4: //Trem 4
          if (y == yinicio && x <(xinicio+270)){//direita
              while (x < 290) {//saindo do ponto crítico 5
                 direita();
              }
              critic5.unlock();
              while (x < 390){//entrando no ponto critico 3
                  direita();
              }
              deadlock[1]->acquire();
              critic3.lock();
              while (x < 430) {//saindo do ponto critico 2
                  direita();
              }
              critic2.unlock();
              if(deadlock[0]->available() <2)//se não for a primeira execução
                deadlock[0]->release();
              while (x < 520) {//entrando no ponto critico 6
                  direita();
              }
              critic6.lock();
              while (x < 540) {
                  direita();
              }

          }

          if (x == 540 && y < 270 ){//desce
              while (y < 170){//saindo do ponto crítico 3
                  desce();
              }
              critic3.unlock();
              if(deadlock[2]->available()<2)//se não for a primeira execução
                deadlock[2]->release();
              while (y < 270){ //andando no ponto critico 6
                  desce();
              }
          }

          if (x > xinicio && y == 270){//esquerda
              while (x > 520) {//saindo do ponto critico 6
                  esquerda();
              }
              critic6.unlock();
              if(deadlock[1]->available() <2)
                deadlock[1]->release();
              while(x > 290){
                  esquerda();
              }
              deadlock[0]->acquire();
              critic5.lock();
              while (x > 270) {//entrando no ponto critico 5
                  esquerda();
              }
          }
          if(x==xinicio && y > yinicio){//sobe
              while (y > 170) {//andando no ponto critico 5
                  sobe();
              }
              deadlock[2]->acquire();
              critic2.lock();
              while (y > yinicio) {//entrando no ponto critico 2
                  sobe();
              }
          }
          break;
        case 5: //Trem 5
          if (y == yinicio && x <(xinicio+270)){//direita
              while (x < 560) {//saindo do ponto crítico 6
                 direita();
              }
              critic6.unlock();
              while (x < 700){//saindo do ponto critico 4
                  direita();
              }
              critic4.unlock();
              if(deadlock[1]->available()<2)//se não for a primeira execução
                deadlock[1]->release();

              while (x < 810) {
                  direita();
              }

          }

          if (x == 810 && y < 270 ){//desce
              while (y < 270){
                  desce();
              }
          }

          if (x > xinicio && y == 270){//esquerda
              while (x > 560) {
                  esquerda();
              }
              deadlock[1]->acquire();
              critic6.lock();
              while(x > 540){//entrando no ponto critico 6
                  esquerda();
              }
          }
          if(x==xinicio && y > yinicio){//sobe
              while (y > 170) {//andando no ponto critico 6
                  sobe();
              }
              critic4.lock();
              while (y > yinicio) {//entrando no ponto critico 4
                  sobe();
              }
          }
        break;
        default:
            break;
        }
        primeira = false;
       // std::cout << ID << " " << x << " " << y << std::endl;

    }
}

void Trem::changeVelocity(int v){
    int newVelocity = 200-v+10;
    this->velocidade = newVelocity;
    if(newVelocity >=210 )
        changeStop(true);
    else
        changeStop(false);
   // std::cout << newVelocity << std::endl;
}

void Trem::changeStop(bool b){
    this->isStopped = b;
}

void Trem::sobe(){
    if(!isStopped){
        y-=10;
        msleep(velocidade);
        emit updateGUI(ID, x,y);
    }
}

void Trem::desce(){
    if(!isStopped){
        y+=10;
        msleep(velocidade);
        emit updateGUI(ID, x,y);
    }
}

void Trem::direita(){
    if(!isStopped){
        x+=10;
        msleep(velocidade);
        emit updateGUI(ID, x,y);
    }
}

void Trem::esquerda(){
    if(!isStopped){
        x-=10;
        msleep(velocidade);
        emit updateGUI(ID, x,y);
    }
}


