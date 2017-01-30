#include "G_Based_Vert.h"


g_based_entites::
Vert::Vert() : x(0), y(0), adjasent_list(0), color(COLOR::WHITE),
               distanse(0), parent(-1) {

}

g_based_entites::
Vert::Vert(double x, double y):Vert(){
    this->x = x;
    this->y = y;
}
//
void g_based_entites::
Vert::add_conection(int new_v) {
    adjasent_list.push_back(new_v);
}

void g_based_entites::
Vert::draw(QGraphicsScene *scene)const {
    double rad = 2;
    QColor *color_draw;

    if (color == COLOR::BLACK) {
        color_draw = new QColor(Qt::black);
    } else if (color == COLOR::GREY) {
        color_draw = new QColor(Qt::red);
    } else {
        color_draw = new QColor(Qt::green);
    }
    scene->addEllipse(this->X() - rad, this->Y() - rad, rad * 2.0, rad * 2.0, QPen(*color_draw),
                      QBrush(Qt::SolidPattern));
}
