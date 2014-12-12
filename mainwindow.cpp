#include "mainwindow.h"
#include "gameboard.h"
#include <QCloseEvent>

/**
 * @brief MainWindow::MainWindow Constructor that has an optional input for a parent widget.
 * @param parent Optional Parent widget that would be set as MainWindow's parent.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    title=new QLabel("<h2>Tower Defence</h2>");
    title->setAlignment(Qt::AlignCenter);

    difficulty=new QLabel("<h3>Choose your difficulty</h3>");
    difficulty->setAlignment(Qt::AlignCenter);

    easy= new QPushButton("Easy");
    medium= new QPushButton("Medium");
    hard= new QPushButton("Hard");
    wtf= new QPushButton("WTF?");

    diffScreen= new QVBoxLayout;
    diffScreen->addWidget(easy);
    diffScreen->addWidget(medium);
    diffScreen->addWidget(hard);
    diffScreen->addWidget(wtf);

    titleScreen= new QVBoxLayout;
    titleScreen->addWidget(title);
    titleScreen->addWidget(difficulty);
    titleScreen->addLayout(diffScreen);

    intro=new QWidget;
    intro->setLayout(titleScreen);

    this->setCentralWidget(intro);

}

/**
 * @brief MainWindow::~MainWindow Destructor
 */
MainWindow::~MainWindow()
{

}

/**
 * @brief MainWindow::closeEvent Implement self-created close event.
 * @param e unused parameter.
 * Ignores automated close event and shows the self-created quit widget screen.
 */
void MainWindow::closeEvent(QCloseEvent *e) {

    e->ignore();
    quit->show();

}

/**
 * @brief MainWindow::setQuitWidget sets a Quit Widget as a child widget
 * @param quit_widget QuitWidget* that gets passed as value.
 */
void MainWindow::setQuitWidget(QuitWidget* quit_widget) {
    quit = quit_widget;
}

/**
 * @brief MainWindow::setGameBoard "Easy" mode selected. Sets a GameBoard* as a child.
 * @param game_board GameBoard* being passed by value.
 * Shows the "easy" mode game board if easy is clicked.
 */
void MainWindow::setGameBoard(GameBoard* game_board) {
    board = game_board;
    QObject::connect(easy, SIGNAL(clicked()), board, SLOT(show()));

}

/**
 * @brief MainWindow::setmGameBoard "Medium" mode selected. Sets a mGameBoard* as a child.
 * @param mgame_board mGameBoard* being passed by value.
 * Shows the "medium" mode game board if "medium" is clicked.
 */
void MainWindow::setmGameBoard(mGameBoard* mgame_board) {
    mboard = mgame_board;
    QObject::connect(medium, SIGNAL(clicked()), mboard, SLOT(show()));
}

/**
* @brief MainWindow::sethGameBoard "Hard" mode selected. Sets a hGameBoard* as a child.
* @param hgame_board GameBoard* being passed by value.
* Shows the "hard mode game board if "hard" is clicked.
* */
void MainWindow::sethGameBoard(hGameBoard* hgame_board) {
    hboard = hgame_board;
    QObject::connect(hard, SIGNAL(clicked()), hboard, SLOT(show()));
}

/**
* @brief MainWindow::setwtfGameBoard "Wtf" mode selected. Sets a wtfGameBoard* as a child.
* @param wtfgame_board wtfGameBoard* being passed by value.
* Shows the "Wtf" mode game board if easy is clicked.
* */
void MainWindow::setwtfGameBoard(wtfGameBoard* wtfgame_board) {
    wtfboard = wtfgame_board;
    QObject::connect(wtf, SIGNAL(clicked()), wtfboard, SLOT(show()));

}


