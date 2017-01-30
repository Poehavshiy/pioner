//
// Created by nikita on 27.01.17.
//

#ifndef PIONER_GRAPH_H
#define PIONER_GRAPH_H

#include "G_Based_Vert.h"

namespace g_based_entites {
    class Graph {
    private:
        vector<Vert> vertices;

        void draw_arrow(int i ,int j,const QPointF &p1, const QPointF &p2, QGraphicsScene *scene);

        void generate_connections(int begin, int end);

        void generate_positions(int begin, int end);

        void set_text(QGraphicsScene *scene, QString& text_string,QPointF point);

    public:
        Graph();

        Graph(unsigned long v_num);//randon constructor

        void draw(QGraphicsScene *scene);

        void bst_info(QGraphicsScene *scene);

        void bfs(int vert_id);


        void add_vert(double x, double y) {
            Vert vert(x, y);
            vertices.push_back(vert);
        }

        void add_edge(int first, int second) {
            vertices[first].add_conection(second);
        }

        void check();
    };
}


#endif //PIONER_GRAPH_H
