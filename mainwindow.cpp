#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // se agrega la escena
    scene = new QGraphicsScene(-500, -250, 1000, 500);
    ui->graphicsView->setScene(scene);

    cambio='\n';
    control=0;

    connect(ui->on_lanzamiento1_btn, SIGNAL(clicked()), this, SLOT(on_lanzamiento1_btn_clicked()));
    connect(ui->on_lanzamiento2_btn, SIGNAL(clicked()), this, SLOT(on_lanzamiento2_btn_clicked()));
    connect(ui->on_finalizar_btn, SIGNAL(clicked()), this, SLOT(on_finalizar_btn_clicked()));

    // limites de la escena
    l1 = new QGraphicsLineItem(-500,-250,500,-250);
    l2 = new QGraphicsLineItem(-500,250,500,250);
    l3 = new QGraphicsLineItem(-500,-250,-500,250);
    l4 = new QGraphicsLineItem(500,-250,500,250);

    // Se agregan los limites a la escena
    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(Actualizar()));
}

void MainWindow::Actualizar()
//Actualiza las velocidades y posiciones del cuerpo
{
    for (objeto* m:sistema){
        m->xyenarchivo();
    }
    ofstream fout;
    try{
        fout.open("posiciones.txt",ios::app);
        if(!fout.is_open()){
            throw '2';
        }
    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    fout<<cambio;
    fout.close();
    float x2s=0,y2s=0,masa2s=0,angulos=0,rs=0,axs=0,ays=0;
    int l=0;
    for (objeto* objeto1: sistema){

        //for (l=0 ; l<10 ; l++)
            for (objeto* objeto2:sistema)
            {
                if (objeto1!=objeto2){
                    x2s=objeto2->getX();
                    y2s=objeto2->getY();
                    masa2s=objeto2->getMasa();
                    rs=objeto1->getr(x2s,y2s);
                    angulos=objeto1->getangulo(x2s,y2s);
                    objeto1->aceleracion(masa2s,angulos,rs);
                    axs=objeto1->getAx();
                    ays=objeto1->getAy();
                }
            }
    }
    for (objeto* k:sistema){
        k->velocidades();
        k->posiciones();
        k->inicializadoraceleracion();
        l++;
        if (control<=1000){
            k->xyenarchivo();
            ofstream fout;
            try{
                fout.open("posiciones.txt",ios::app);
                if(!fout.is_open()){
                    throw '2';
                }
            }
            catch (char c){
                cout<<"Error # "<<c<<": ";
                if(c=='2'){
                    cout<<"Error al abrir el archivo para lectura.\n";
                }
            }
            if (l==3){
                fout<<cambio;
                l=0;
            }
            fout.close();
            control++;
        }
    }
}

void MainWindow::on_lanzamiento1_btn_clicked()
{
    // sistema 1
    timer->start(1);
    if (!secuencia)
    {
        objeto* A = new objeto(0, -7000, 2, 0, 120, 70);
        objeto* B = new objeto(0, 0, 0, 0, 300, 70000);
        objeto* C = new objeto(4000, 5000, -1.6, 1.2, 100, 25);

        sistema.push_back(A);
        sistema.push_back(B);
        sistema.push_back(C);

        for (objeto* objetos:sistema){
            scene->addItem(objetos);
        }

        secuencia = true;
    }
}

void MainWindow::on_lanzamiento2_btn_clicked()
{
    // sistema 2
    timer->start(1);
    if (!secuencia)
    {
        objeto* A = new objeto(0,0,0,0,200,50000);
        objeto* B = new objeto(-5000,0,0,-2,70,70);
        objeto* C = new objeto(5000,0,0,2,70,70);
        objeto* D=  new objeto(0,-5000,2,0,70,70);
        objeto* E = new objeto(0,5000,-2,0,70,70);

        sistema.push_back(A);
        sistema.push_back(B);
        sistema.push_back(C);
        sistema.push_back(D);
        sistema.push_back(E);

        for (objeto* objetos2:sistema){
            scene->addItem(objetos2);
        }
        secuencia = true;
    }
}

void MainWindow::on_finalizar_btn_clicked()
//para finalizar la simulacion
{

    timer->stop();

    for (objeto* objetos3:sistema)
        scene->removeItem(objetos3);

    sistema.clear();

    secuencia = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

