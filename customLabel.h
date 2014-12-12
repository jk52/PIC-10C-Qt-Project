#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H
/**
 * @author Chung Kwan
 * @date 12/9/2014
 * @file customLabel.h
 * @brief Labels to used if "easy" mode is selected.
 */



#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include "gameboard.h"
#include <QPixmap>
#include "mainwindow.h"

/**
 *@brief The customLabel class This is a class that derives from QLabel with the sole purpose of making a clickable QLabel.
 * This class allows a user to click on a label on the board and it will save those coordinates and perform
 * other functions as necessary. This class utilizes the Qt mouseReleasesEvent to perform actions such as changing a
 * labels picture when clicked on and such. The "easy" mode game board utilizes this label class.
 */

class customLabel : public QLabel
{
    Q_OBJECT   

signals:
    ///default signal to be sent when a customLabel has been clicked
    void clicked();

public slots:
    ///default function called when a customLabel has been clicked
    void slotClicked();

public:

    friend class GameBoard;

    explicit customLabel(QWidget* parent = 0);
    explicit customLabel(GameBoard* p,QWidget* parent = 0);
    ~customLabel();

protected:
    ///gives labels coordinate such as (0,1) when intializing in GameBoard
    QPoint label_coordinate;
     ///stores given point clicked in a temp QPoint *
    QPoint* temp;
    void mouseReleaseEvent ( QMouseEvent *event );
    /// tower images to be used
    QPixmap* tower_image;
    ///gives GameBoard access to customLabel coordinates
    GameBoard* z;

};
#endif // CUSTOMLABEL_H
