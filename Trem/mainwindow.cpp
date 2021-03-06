#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#define N 5

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)

    trem1 = new Trem(1, 140, 30);
    trem2 = new Trem(2, 410, 30, 680, 30);
    trem3 = new Trem(3, 0, 150, 0, 180);
    trem4 = new Trem(4, 270, 150, 400, 270);
    trem5 = new Trem(5, 540, 150, 710, 270);


    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    inicio();

}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
 * Inicia a execução
 */
void MainWindow::inicio()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

void MainWindow::on_Slider_1_valueChanged(int value)
{
    //mudando a velocidade do trem 1
    trem1->mudaVelocidade(value);
}

void MainWindow::on_Slider_2_valueChanged(int value)
{
    //mudando a velocidade do trem 2
    trem2->mudaVelocidade(value);
}

void MainWindow::on_Slider_3_valueChanged(int value)
{
    //mudando a velocidade do trem 3
    trem3->mudaVelocidade(value);
}

void MainWindow::on_Slider_4_valueChanged(int value)
{
    //mudando a velocidade do trem 4
    trem4->mudaVelocidade(value);
}

void MainWindow::on_Slider_5_valueChanged(int value)
{
    //mudando a velocidade do trem 5
    trem5->mudaVelocidade(value);
}
