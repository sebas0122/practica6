#include "objeto.h"
#include <fstream>

objeto::objeto(float _x, float _y, float _vx, float _vy, float _rad, float _masa)
{
    x = _x;
    y = _y;
    vx = _vx;
    vy = _vy;
    ax = 0;
    ay = 0;
    radio = _rad;
    masa = _masa;

    // ajustando los cuadrates
    setPos((x/EX), (-y/EY));
}

QRectF objeto::boundingRect() const
{
    return QRect((-radio)/EX, (-radio)/EY, (radio*2)/EX, (radio*2)/EY);
}

void objeto::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
}

void objeto::xyenarchivo()
{
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
    xstring=to_string(x);
    ystring=to_string(y);
    fout<<xstring;
    fout<<espacios;
    fout<<ystring;
    fout<<espacios;
    fout.close();
}

float objeto::getX() const
{
    return x;
}
float objeto::getY() const
{
    return y;
}
float objeto::getVx() const
{
    return vx;
}
float objeto::getVy() const
{
    return vy;
}
float objeto::getAx() const
{
    return ax;
}
float objeto::getAy() const
{
    return ay;
}
float objeto::getRad() const
{
    return radio;
}
float objeto::getMasa() const
{
    return masa;
}


void objeto::setX(float value)
{
    x = value;
}
void objeto::setY(float value)
{
    y = value;
}
void objeto::setVx(float value)
{
    vx = value;
}
void objeto::setVy(float value)
{
    vy = value;
}
void objeto::setAx(float value)
{
    ax = value;
}
void objeto::setAy(float value)
{
    ay = value;
}
void objeto::setRad(float value)
{
    radio = value;
}
void objeto::setMasa(float value)
{
    masa = value;
}

void objeto::inicializadoraceleracion(){
    ax=0;
    ay=0;
}
float objeto::getangulo(float x2, float y2)
{
    if (x2 == x) {
        if (y2 >= y) {
            return M_PI / 2.0;
        } else {
            return -M_PI / 2.0;
        }
    } else {
        return atan2(y2 - y, x2 - x);
    }
}
float objeto::getr(float x2,float y2)
{
    float r=sqrt(pow((x2-x),2)+pow((y2-y),2));
    return r;
}
void objeto::aceleracion(float masa2,float angulo,float r)
{
    ax +=((G*masa2)/pow(r,2))*cos(angulo);
    ay +=((G*masa2)/pow(r,2))*sin(angulo);
    const float threshold = 0.0000000001; // Umbral de tolerancia
    if (abs(ax) < threshold) {
      ax = 0.0; // Considerar como 0 si es menor que el umbral
    }
    if (abs(ay) < threshold) {
      ay = 0.0; // Considerar como 0 si es menor que el umbral
    }
}
void objeto::velocidades()
// calcula las velocidades
{
    vx = vx + (ax*DT);
    vy = vy + (ay*DT);
}
void objeto::posiciones()
// calcula y Actualiza las posiciones
{
    x = x + (vx * DT) + (0.5 * ax * pow(DT,2));
    y = y + (vy * DT) + (0.5 * ay * pow(DT,2));

    // ajustando los cuadrantes
    setPos((x/EX), (-y/EY));
}
