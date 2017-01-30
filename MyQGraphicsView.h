#ifndef MyQGraphicsView_H
#define MyQGraphicsView_H

#include "Graph.h"

class MyQGraphicsView : public QGraphicsView {
Q_OBJECT
public:
    explicit MyQGraphicsView(QWidget *parent = 0);

    ~MyQGraphicsView();

signals:

public slots:

    //drawing
    void mousePressEvent(QMouseEvent *e);

    void ClearWindow();

    void mouseDoubleClickEvent(QMouseEvent *e);

private:
    QGraphicsScene *scene;
    //
    g_based_entites::Graph graph;

public:
    void draw();

    void clear();

    void bfs();

};

#endif
