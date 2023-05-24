#ifndef OTROBJETO_H
#define OTROBJETO_H

#define EX 30
#define EY 60

#define G 1
#define DT 1
#include <QGraphicsItem>
#include <QPainter>
#include <cmath>

class otrobjeto: public QGraphicsItem
{

private:
    float x, y, vx, vy, ax, ay, radio, masa;

public:
    otrobjeto();
    otrobjeto(float _x, float _y, float _vx, float _vy, float _radio, float _masa);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // get
    float getX() const;
    float getY() const;
    float getVx() const;
    float getVy() const;
    float getAx() const;
    float getAy() const;
    float getRad() const;
    float getMasa() const;

    // set
    void setX(float value);
    void setY(float value);
    void setVx(float value);
    void setVy(float value);
    void setAx(float value);
    void setAy(float value);
    void setRad(float value);
    void setMasa(float value);

    // Funciones mvto
    void inicializadoraceleracion();
    float getangulo(float x2,float y2);
    float getr(float x2,float y2);
    void aceleracion(float masa2,float angulo,float r);
    void velocidades();
    void posiciones();

};

#endif // OTROBJETO_H
