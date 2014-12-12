#ifndef CUSTOMLABELWTF_H
#define CUSTOMLABELWTF_H

/**
 * @author Chung Kwan
 * @date 12/9/2014
 * @file customLabelwtf.h
 * @brief Labels to used if "wtf" mode is selected.
 */

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include "wtfGameBoard.h"
#include <QPixmap>
#include "mainwindow.h"

/**
 * @brief Look up customLabel documentation because this is just a copy of that but for "wtf" mode
 */
class customLabelwtf : public QLabel
{
    Q_OBJECT


signals:
    void clicked();

public slots:
    void slotClicked();

public:

    friend class wtfGameBoard;
    explicit customLabelwtf(QWidget* parent = 0);
    explicit customLabelwtf(wtfGameBoard* p,QWidget* parent = 0);
    ~customLabelwtf();

protected:

    QPoint label_coordinate;
    QPoint* temp;
    void mouseReleaseEvent ( QMouseEvent *event );
    QPixmap* tower_image;
    wtfGameBoard* t;

};



#endif // CUSTOMLABELWTF_H
