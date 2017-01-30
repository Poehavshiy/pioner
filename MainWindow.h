#ifndef MainWindow_H
#define MainWindow_H

#include "MyQGraphicsView.h"

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();


public slots:
    void start();
    void bfs();
    void clear();
private:
    QMenuBar* menu_bar;
    QMenu* menu;
    QTimer* timer;
    MyQGraphicsView *view;
    //menus
};

#endif
