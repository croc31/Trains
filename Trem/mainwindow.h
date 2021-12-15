#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();


public slots:
    void updateInterface(int, int, int);//função que atualiza a posição dos trens
private slots:
    void inicio();

    void on_Slider_1_valueChanged(int value);//função que recebe o valor do slider 1
    void on_Slider_2_valueChanged(int value);//função que recebe o valor do slider 2
    void on_Slider_3_valueChanged(int value);//função que recebe o valor do slider 3
    void on_Slider_4_valueChanged(int value);//função que recebe o valor do slider 4
    void on_Slider_5_valueChanged(int value);//função que recebe o valor do slider 5


private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
};

#endif // MAINWINDOW_H
