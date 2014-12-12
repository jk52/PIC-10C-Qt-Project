#include "quitwidget.h"
#include <QHBoxLayout>
#include "mainwindow.h"

/**
 * @brief QuitWidget::QuitWidget Constructor that allows construction without parent
 * @param parent sets QWidget as parent
 */
QuitWidget::QuitWidget(QWidget *parent) :
    QWidget(parent)
{

    quit_label = new QLabel("Leaving so soon?");
    quit_label->setAlignment(Qt::AlignCenter);
    quit_cancel = new QPushButton("No");
    quit_ok = new QPushButton("Yes");

    QHBoxLayout* quit_hlayout = new QHBoxLayout;
    quit_hlayout->addWidget(quit_ok);
    quit_hlayout->addWidget(quit_cancel);

    QVBoxLayout* quit_vlayout = new QVBoxLayout;
    quit_vlayout->addWidget(quit_label);
    quit_vlayout->addLayout(quit_hlayout);

    this->setLayout(quit_vlayout);
    //quit_widget->show();

    QObject::connect(quit_cancel, SIGNAL(clicked()), this, SLOT(hide()));
    QObject::connect(quit_ok, SIGNAL(clicked()), this,SLOT(close()));

}


QuitWidget::~QuitWidget()
{ }

