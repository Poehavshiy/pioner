#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {

    setWindowTitle(tr("Something Title"));
    view = new MyQGraphicsView();//creating grafic scence inside of main window
    this->setCentralWidget(view);
    menu_bar = new QMenuBar();
    this -> setMenuBar(menu_bar);
    //
    menu = new QMenu("Menu");
    menu_bar->addMenu(menu);
    //
    QAction* draw = menu->addAction("show");
    connect(draw, SIGNAL (triggered()), this, SLOT (start()));
    //
    QAction* bfs = menu->addAction("bfs");
    connect(bfs, SIGNAL (triggered()), this, SLOT (bfs()));
    //
    QAction* clear = menu->addAction("clear");
    connect(clear, SIGNAL (triggered()), this, SLOT (clear()));
}

void MainWindow::start() {
    view->draw();
}

void MainWindow::bfs(){
    view->bfs();
}

void MainWindow::clear() {
    view->clear();
}

MainWindow::~MainWindow() {
}
