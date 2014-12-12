#include "mainwindow.h"
#include <QApplication>
#include "gameboard.h"
#include "quitwidget.h"
#include "mGameBoard.h"
#include "hGameBoard.h"
#include "wtfGameBoard.h"

/**
 * \mainpage This is a tower defence game created using QObjects. It has 4 different settings and each game lasts 3 rounds. As the difficulty gets harder, you start with less gold and monsters have more hit points.
 * */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* w=new MainWindow;
    QuitWidget* q= new QuitWidget;
    GameBoard* b = new GameBoard;
    mGameBoard* m= new mGameBoard;
    hGameBoard* h= new hGameBoard;
    wtfGameBoard* wtf=new wtfGameBoard;


    b->setQuitWidget(q);
    m->setQuitWidget(q);
    w->setQuitWidget(q);
    h->setQuitWidget(q);
    wtf->setQuitWidget(q);

    w->setGameBoard(b);
    w->setmGameBoard(m);
    w->sethGameBoard(h);
    w->setwtfGameBoard(wtf);

    b->setMainWindow(w);
    m->setMainWindow(w);
    h->setMainWindow(w);
    wtf->setMainWindow(w);

    w->show();

    //connects the quit screen buttons
    QObject::connect(q->quit_ok, SIGNAL(clicked()), &a, SLOT(quit()));

    //hides title screen when difficulty is selected
    QObject::connect(w->easy, SIGNAL(clicked()), w, SLOT(hide()));
    QObject::connect(w->medium, SIGNAL(clicked()), w, SLOT(hide()));
    QObject::connect(w->hard, SIGNAL(clicked()), w, SLOT(hide()));
    QObject::connect(w->wtf, SIGNAL(clicked()), w, SLOT(hide()));


    return a.exec();
}
