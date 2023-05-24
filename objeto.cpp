#include "objeto.h"

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
    return QRect(-radio, -radio, radio*2, radio*2);
}

void objeto::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
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
float objeto::getangulo(float x2,float y2)
{
    float angulo=atan((y2-y)/(x2-x));
    return angulo;
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
