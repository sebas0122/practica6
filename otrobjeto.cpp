#include "otrobjeto.h"

otrobjeto::otrobjeto(float _x, float _y, float _vx, float _vy, float _rad, float _masa)
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

QRectF otrobjeto::boundingRect() const
{
    return QRect(-radio, -radio, radio*2, radio*2);
}

void otrobjeto::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
}

float otrobjeto::getX() const
{
    return x;
}
float otrobjeto::getY() const
{
    return y;
}
float otrobjeto::getVx() const
{
    return vx;
}
float otrobjeto::getVy() const
{
    return vy;
}
float otrobjeto::getAx() const
{
    return ax;
}
float otrobjeto::getAy() const
{
    return ay;
}
float otrobjeto::getRad() const
{
    return radio;
}
float otrobjeto::getMasa() const
{
    return masa;
}


void otrobjeto::setX(float value)
{
    x = value;
}
void otrobjeto::setY(float value)
{
    y = value;
}
void otrobjeto::setVx(float value)
{
    vx = value;
}
void otrobjeto::setVy(float value)
{
    vy = value;
}
void otrobjeto::setAx(float value)
{
    ax = value;
}
void otrobjeto::setAy(float value)
{
    ay = value;
}
void otrobjeto::setRad(float value)
{
    radio = value;
}
void otrobjeto::setMasa(float value)
{
    masa = value;
}

void otrobjeto::inicializadoraceleracion(){
    ax=0;
    ay=0;
}
float otrobjeto::getangulo(float x2,float y2)
{
    float angulo=atan((y2-y)/(x2-x));
    return angulo;
}
float otrobjeto::getr(float x2,float y2)
{
    float r=sqrt(pow(x2-x,2)+pow(y2-y,2));
    return r;
}
void otrobjeto::aceleracion(float masa2,float angulo,float r)
{
    ax +=((G*masa2)/pow(r,2))*cos(angulo);
    ay +=((G*masa2)/pow(r,2))*sin(angulo);
}
void otrobjeto::velocidades()
// calcula las velocidades
{
    vx = vx + (ax*DT);
    vy = vy + (ay*DT);
}
void otrobjeto::posiciones()
// calcula y Actualiza las posiciones
{
    x = x + (vx * DT) + (0.5 * ax * pow(DT,2));
    y = y + (vy * DT) + (0.5 * ay * pow(DT,2));

    // ajustando los cuadrantes
    setPos((x/EX), (-y/EY));
}
