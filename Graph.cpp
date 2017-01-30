//
// Created by nikita on 27.01.17.
//

#include "Graph.h"

//addLine(const QLineF & line, const QPen & pen = QPen())
g_based_entites::
Graph::Graph() {

}

g_based_entites::
Graph::Graph(unsigned long v_num) : vertices(v_num) {
    //int size = qrand()%100 + 5;
    generate_connections(0, v_num);
    generate_positions(0, v_num);

}


void g_based_entites::
Graph::set_text(QGraphicsScene *scene, QString& text_string,QPointF point ){
    QFont font;
    font.setPixelSize(10);
    font.setBold(false);
    font.setFamily("Calibri");
    QGraphicsTextItem *text = scene->addText(text_string, font);
    int x = qrand() % 20;
    int y = qrand() % 20;
    text->setPos(QPointF(point.x() + x, point.y() + y));
}

void g_based_entites::
Graph::generate_connections(int begin, int end) {
    for (int i = begin; i < end; ++i) {
        //create random amount of connections
        int con_num = qrand() % (vertices.size() / 2) + 1;
        std::unordered_map<int, int> alredy_connected;
        alredy_connected.insert({i, i});
        //generate con_num of random connections from ith vert
        for (int j = 0; j < con_num; ++j) {
            int connect_to = qrand() % (vertices.size());
            int connection_tries = 0;
            while (alredy_connected.find(connect_to) != alredy_connected.end()) {
                connect_to = qrand() % (vertices.size());
                ++connection_tries;
                if (connection_tries == 10)
                    break;
            }
            if (connection_tries != 10) {
                alredy_connected.insert({connect_to, connect_to});
                vertices[i].add_conection(connect_to);
            }
            connection_tries = 0;
        }
    }
}

void g_based_entites::
Graph::generate_positions(int begin, int end) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution_x(0, 1400);
    std::uniform_int_distribution<int> distribution_y(0, 700);
    for (int i = begin; i < end; ++i) {
        int x = distribution_x(generator);
        int y = distribution_y(generator);
        vertices[i].set_coord(x, y);

    }
}

void g_based_entites::
Graph::check() {
    std::for_each(vertices.begin(), vertices.end(), [](Vert &vert) {
        for (int i = 0; i < vert.get_adj_list().size(); i++) {

            for (int k = vert.get_adj_list().size() - 1; k > i; --k) {

                if (vert.get_adj_list()[i] == vert.get_adj_list()[k]) {
                    throw;
                }
            }
        }
    });
}

//
void g_based_entites::
Graph::draw_arrow(int first, int second, const QPointF &p1, const QPointF &p2, QGraphicsScene *scene) {
    scene->addLine(p1.x(), p1.y(), p2.x(), p2.y(), QPen(Qt::black));
    QString text_string = "from " + QString::number(first) + " to " + QString::number(second);
    set_text(scene, text_string, QPointF((p2.x() + p1.x()) / 2, (p2.y() + p1.y()) / 2 ));
}

//
void g_based_entites::
Graph::draw(QGraphicsScene *scene) {

    for (int i = 0; i < vertices.size(); ++i) {
        Vert &vert = vertices[i];
        vert.draw(scene);
        QFont font;
        font.setPixelSize(10);
        font.setBold(false);
        font.setFamily("Calibri");

        QGraphicsTextItem *text = scene->addText(QString::number(i), font);
        text->setPos(QPointF(vert.X(), vert.Y()));
        const vector<int> &adj_list = vert.get_adj_list();
        for (auto j = 0; j < adj_list.size(); ++j) {
            Vert &second = vertices[adj_list[j]];
            QPointF p1(vert.X(), vert.Y());
            QPointF p2(second.X(), second.Y());
            draw_arrow(i, adj_list[j], p1, p2, scene);
        }
    }
}

void g_based_entites::
Graph::bfs(int vert_id) {
    queue<int> grey_queue;
    grey_queue.push(vert_id);
    while (!grey_queue.empty()) {
        int grey_vert = grey_queue.front();
        for (auto &&i : vertices[grey_vert].adjasent_list) {
            if (vertices[i].color == COLOR::WHITE) {
                vertices[i].color = COLOR::GREY;
                vertices[i].distanse = vertices[grey_vert].distanse + 1;
                vertices[i].parent = grey_vert;
                grey_queue.push(i);
            }
        }
        vertices[grey_vert].color = COLOR::BLACK;
        grey_queue.pop();
    }
}

void g_based_entites::
Graph::bst_info(QGraphicsScene *scene){
    std::for_each(vertices.begin(), vertices.end(), [scene, this](Vert& vert){
        QString text_string = "dst= " + QString::number(vert.dist());
        this->set_text(scene, text_string, QPointF(vert.X(), vert.Y()));
    });
}
