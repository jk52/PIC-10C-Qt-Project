#ifndef CUSTOMLABELM_H
#define CUSTOMLABELM_H

/**
 * @author Chung Kwan
 * @date 12/9/2014
 * @file customLabelm.h
 * @brief Labels to used if "Medium" mode is selected.
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
 *@brief Look up customLabel documentation because this is just a copy of that but for "Medium" mode
 * */
class customLabelm : public QLabel
{
    Q_OBJECT


signals:
    void clicked();

public slots:
    void slotClicked();

public:

    friend class mGameBoard;
    explicit customLabelm(QWidget* parent = 0);
    explicit customLabelm(mGameBoard* p,QWidget* parent = 0);
    ~customLabelm();

protected:

    QPoint label_coordinate;
    QPoint* temp;
    void mouseReleaseEvent ( QMouseEvent *event );
    QPixmap* tower_image;
    mGameBoard* t;

};

#endif // CUSTOMLABELM_H
