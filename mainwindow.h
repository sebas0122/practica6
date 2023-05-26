#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>
#include <map>
#include <list>
#include <string>
#include "otrobjeto.h"

using namespace std;

#include "objeto.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Actualizar();

private slots:
    void on_lanzamiento1_btn_clicked();
    void on_lanzamiento2_btn_clicked();
    void on_finalizar_btn_clicked();

private:
    Ui::MainWindow *ui;

    // puntero de mi escena
    QGraphicsScene *scene;

    // temporizador para el pulso
    QTimer *timer;

    //limites
    QGraphicsLineItem *l1;
    QGraphicsLineItem *l2;
    QGraphicsLineItem *l3;
    QGraphicsLineItem *l4;

    list<objeto*> sistema;

    //booleano para controlar la simulación
    bool secuencia=false;
    char cambio;
    int control;
};
#endif // MAINWINDOW_H
