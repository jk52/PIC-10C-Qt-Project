#ifndef GAMEBOARD_H
#define GAMEBOARD_H

/**
 * @author Chung Kwan
 * @date 12/9/2014
 * @file gameboard.h
 * @brief game board to be set if "easy" mode is selected.
 */

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "mainwindow.h"
#include <QMainWindow>
#include "quitwidget.h"
#include <QPixmap>
#include <QTimer>
#include <QPaintEvent>
#include <QVector>
#include "customLabel.h"


class MainWindow;

/**
 * @brief The GameBoard class Constructs the game board of labels, push buttons and ect..
 * The GameBoard class inherits from QWidget and essentially builds the game board from labels and push buttons. This class
 * is friends with the customLabel class so it can access the tower coordinates on the board. Also, this is the board for "easy"
 * mode. This class holds all the variables for monsters, their hp, the number of monsters, and ect...
 */
class GameBoard :  public QWidget
{
    Q_OBJECT

public slots:
    /// moves monsters in the pre-assigned path
    void moveMonsters();
    ///starts the game(timer) when start push button ispressed
    void startTimer();
    ///pauses timer
    void pauseTimer();
    ///upgrades all towers and future towers
    void upgradeTowers();

public:
    friend class customLabel;
    explicit GameBoard(QWidget *parent = 0);
    ~GameBoard();

    void closeEvent(QCloseEvent *e);
    void setQuitWidget(QuitWidget* quitWidget);
    void setMainWindow(MainWindow* mainWindow);
    void paintEvent(QPaintEvent* e);

private:
    QLabel* level_screen;
    QLabel* lose_screen;
    int gold_amount;
    int current_level;
    QLabel* level;
    QLabel* gold;
    QLabel* gold_screen;
    QWidget* Top;

    QWidget* game_board;
    int board_size;
    customLabel** labels;
    QPixmap* monster_image;
    QPixmap* creature_image;
    QPixmap* boss_image;
    QPixmap* terrain;
    QPixmap* tree;
    int num_monsters;
    int num_monsters2;
    int num_boss;
    QPoint* monster_positions;

    int monster_hp;
    int monster_hp2;
    int boss_hp;
    QVector<int> hp_holder;
    QVector<int> hpx_holder;
    QVector<int> b_holder;

    QVector<QPoint*> tower_holder;
    QVector<QPoint> monster_holder;
    QVector<QPoint> monsterx_holder;
    QVector<QPoint> boss_holder;

    QTimer* internal_timer;
    double multiplier;

    QPushButton* start;
    QPushButton* instruction;
    QPushButton* upgrade;
    QPushButton* pause;

    QuitWidget* quit;
    MainWindow* gameScreen;

};


#endif
