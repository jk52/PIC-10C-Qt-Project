#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @author Chung Kwan
 * @date 12/9/2014
 * @file mainwindow.h
 * @brief Displays and controls the game board. Inherits from QMainWindow.
 */

#include <QMainWindow>
#include "quitwidget.h"
#include "gameboard.h"
#include "mGameBoard.h"
#include "hGameBoard.h"
#include "wtfGameBoard.h"

class GameBoard;
class mGameBoard;
class hGameBoard;
class wtfGameBoard;

/**
 * @brief The MainWindow class is the parent of all the GameBoard's.
 * MainWindow class will take care of the memory management of all it's child widgets. Controls which game board
 * will be displayed through push buttons.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void closeEvent(QCloseEvent *e);
    ~MainWindow();
    void setQuitWidget(QuitWidget* quit_widget);
    void setGameBoard(GameBoard* game_board);
    void setmGameBoard(mGameBoard* mgame_board);
    void sethGameBoard(hGameBoard* hgame_board);
    void setwtfGameBoard(wtfGameBoard* wtfgame_board);

    QPushButton* easy;
    QPushButton* medium;
    QPushButton* hard;
    QPushButton* wtf;

private:
    QuitWidget* quit;
    GameBoard* board;
    mGameBoard* mboard;
    hGameBoard* hboard;
    wtfGameBoard* wtfboard;
    QLabel* title;
    QLabel* difficulty;
    QVBoxLayout* diffScreen;
    QVBoxLayout* titleScreen;
    QWidget* intro;



};

#endif
