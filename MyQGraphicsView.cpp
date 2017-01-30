#include "MyQGraphicsView.h"

//from QT
MyQGraphicsView::MyQGraphicsView(QWidget *parent) :
        QGraphicsView(parent), graph(g_based_entites::Graph(8)) {
    scene = new QGraphicsScene();
    this->setScene(scene);
}

//
MyQGraphicsView::~MyQGraphicsView() {
    delete scene;
}

//
void MyQGraphicsView::clear() {
    scene->clear();
}
//

void MyQGraphicsView::mousePressEvent(QMouseEvent *e) {

}

//
void MyQGraphicsView::mouseDoubleClickEvent(QMouseEvent *e) {

}

//
void MyQGraphicsView::draw() {
    graph.check();
    graph.draw(scene);
}
//
void MyQGraphicsView::bfs(){
    graph.bfs(1);
    graph.bst_info(scene);
}
//
void MyQGraphicsView::ClearWindow() {
    scene->clear();
}
