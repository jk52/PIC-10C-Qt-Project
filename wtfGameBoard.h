#ifndef WTFGAMEBOARD_H
#define WTFGAMEBOARD_H

/**
 * @author Chung Kwan
 * @date 12/9/2014
 * @file wtfGameBoard.h
 * @brief game board to be set if "wtf" mode is selected.
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
#include "customLabelwtf.h"


class MainWindow;

/**
 * @brief Look up gameboard.h documentation as this is just a copy of that but for "wtf" mode.
 */
class wtfGameBoard :  public QWidget
{
    Q_OBJECT

public slots:
    void moveMonsters();
    void startTimer();
    void pauseTimer();
    void upgradeTowers();

public:
    friend class customLabelwtf;
    explicit wtfGameBoard(QWidget *parent = 0);
    ~wtfGameBoard();

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
    customLabelwtf** labels;
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

#endif // WTFGAMEBOARD_H
