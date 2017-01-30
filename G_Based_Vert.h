#ifndef G_BASED_VERT
#define G_BASED_VERT

//
#include <cmath>
#include <iostream>
#include <vector>
#include<map>
#include <assert.h>
#include "algorithm"
#include <fstream>
#include <queue>
#include <memory>
#include <unordered_map>
#include <random>


//concurency
#include <thread>

//
//QTшные либы
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QPointF>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMenu>
#include <QtGui>
#include <QMenuBar>
#include <QToolButton>
#include <QtWidgets>
//
using namespace std;

namespace g_based_entites {
    enum class COLOR {
        WHITE, GREY, BLACK
    };

    class Vert {
    private:
        //basik vert propertes
        double x, y;
        //
        vector<int> adjasent_list;
        //for proper work
        COLOR color;
        int distanse;
        int parent;
    public:
        friend class Graph;
        Vert();
        //
        Vert(double x, double y);
        //
        void add_conection(int new_v);

        //
        double X() const {
            return x;
        }

        //
        double Y() const {
            return y;
        }

        int dist(){
            return this->distanse;
        }

        void set_coord(double x, double y){
            this->x=x;
            this->y=y;
        }


        void draw(QGraphicsScene *scene) const;

        const vector<int> &get_adj_list() {
            return adjasent_list;
        }


    };
}
#endif