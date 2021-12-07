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
    void updateInterface(int,int,int);

private slots:
    void inicio();
    void slider();

    void on_Slider_1_sliderReleased();

private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem **trens;
};

#endif // MAINWINDOW_H
