#ifndef QUITWIDGET_H
#define QUITWIDGET_H

/**
 * @author Chung Kwan
 * @date 12/9/2014
 * @file quitwidget.h
 * @brief Shown when user wants to quit. Overrides default close event.
 */

#include <QWidget>
#include <QLabel>
#include <QPushButton>

/**
 * @brief The QuitWidget class creates it's own quit widget that confirms whether or not user wants to exit.
 * Has essentially 2 push buttons and a label that will signal to the main window whether or not the user wants
 * to exit the program.
 */

class QuitWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuitWidget(QWidget *parent = 0);
    ~QuitWidget();
    ///Exits game
    QPushButton* quit_ok;
private:
    /// Asks whether user really wants to quit.
    QLabel* quit_label;
    ///Exits quit screen.
    QPushButton* quit_cancel;

};
#endif // QUITWIDGET_H
