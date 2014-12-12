#ifndef CUSTOMLABELH_H
#define CUSTOMLABELH_H

/**
 * @author Chung Kwan
 * @date 12/9/2014
 * @file customLabelh.h
 * @brief Labels to used if "Hard" mode is selected.
 */

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include "mGameBoard.h"
#include <QPixmap>
#include "mainwindow.h"

/**
 *@brief Look up customLabel documentation because this is just a copy of that but for "Hard" mode.
 * */
class customLabelh : public QLabel
{
    Q_OBJECT


signals:
    void clicked();

public slots:
    void slotClicked();

public:

    friend class hGameBoard;
    explicit customLabelh(QWidget* parent = 0);
    explicit customLabelh(hGameBoard* p,QWidget* parent = 0);
    ~customLabelh();

protected:

    QPoint label_coordinate;
    QPoint* temp;
    void mouseReleaseEvent ( QMouseEvent *event );
    QPixmap* tower_image;
    hGameBoard* t;

};


#endif // CUSTOMLABELH_H
