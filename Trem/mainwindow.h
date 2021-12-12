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
    void updateInterface(int, int, int);
    void updateText(int, int, int);
private slots:
    void inicio();

    void on_Slider_1_valueChanged(int value);
    void on_Slider_2_valueChanged(int value);
    void on_Slider_3_valueChanged(int value);
    void on_Slider_4_valueChanged(int value);
    void on_Slider_5_valueChanged(int value);


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
