#include "gameboard.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QGridLayout>
#include <QString>
#include <QCoreApplication>
#include <QDebug>


/**
 * @brief GameBoard::GameBoard constructor that takes in a QWidget pointer or constructs object without parent
 * @param parent QWidget Pointer that acts as GameBoard's parent
 */
GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent), board_size(10)
{

    current_level=1;
    multiplier=1.0;

    level_screen=new QLabel("<h2>Level:</h2>");
    level=new QLabel(QString::number(current_level));

    gold_amount=800;
    gold_screen=new QLabel("<h2>Gold: </h2>");
    gold=new QLabel(QString::number(gold_amount));

    QHBoxLayout* levels=new QHBoxLayout;
    levels->addWidget(level_screen);
    levels->addWidget(level);

    QHBoxLayout* gold_info=new QHBoxLayout;
    gold_info->addWidget(gold_screen);
    gold_info->addWidget(gold);

    lose_screen=new QLabel("<h2>Sorry, you lost.</h2>");
    lose_screen->setFixedSize(200,200);

    Top=new QWidget;
    Top->setStyleSheet("QLabel { background-color : black; color : white; }");
    QVBoxLayout *top_bar = new QVBoxLayout(Top);
    top_bar->addLayout(levels);
    top_bar->addLayout(gold_info);

    game_board=new QWidget(this);

    QGridLayout* board_layout = new QGridLayout(game_board);
    board_layout->setGeometry(QRect());
    board_layout->setSpacing(0);


    labels = new customLabel*[board_size*board_size];


    //i=y coordinate from (0,9), j=x coordinate from (0,9)
    for(int i=0;i<board_size;i++) {
         for(int j=0;j<board_size;j++) {
            labels[i*board_size+j] = new customLabel(this);
            labels[i*board_size+j]->setMinimumSize(60,60);
            labels[i*board_size+j]->setMaximumSize(60,60);
            labels[i*board_size+j]->label_coordinate.setX(j);
            labels[i*board_size+j]->label_coordinate.setY(i);
            labels[i*board_size+j]->setStyleSheet("customLabel { background-color : white; color : black; border-style: outset; border-color : gray; border-width : 4px; }");
            labels[i*board_size+j]->setAlignment(Qt::AlignCenter);


            board_layout -> addWidget(labels[i*board_size+j] ,i,j);
          }
    }
    //waves start here
    labels[0]->setText("Start");

    // game ends if monsters reach goal
    labels[99]->setText("Goal");

    //indicate which labels can be built on
    labels[12]->setText("Build here");
    labels[15]->setText("Build here");
    labels[17]->setText("Build here");
    labels[37]->setText("Build here");
    labels[51]->setText("Build here");
    labels[49]->setText("Build here");
    labels[69]->setText("Build here");
    labels[64]->setText("Build here");
    labels[81]->setText("Build here");
    labels[88]->setText("Build here");

    //file directory for monster image
    QString monsterFileName("/Qt/Tools/QtCreator/bin/TowerDefence/creature.jpg");
    monster_image = new QPixmap(monsterFileName);

    QString creatureFileName("/Qt/Tools/QtCreator/bin/TowerDefence/creature2.jpg");
    creature_image = new QPixmap(creatureFileName);

    QString treeFileName("/Qt/Tools/QtCreator/bin/TowerDefence/tree.jpg");
    tree = new QPixmap(treeFileName);

    QString terrainFileName("/Qt/Tools/QtCreator/bin/TowerDefence/terrain.jpg");
    terrain = new QPixmap(terrainFileName);

    QString bossFileName("/Qt/Tools/QtCreator/bin/TowerDefence/boss.jpg");
    boss_image = new QPixmap(bossFileName);

    //insert terrain (can't be built on)
    labels[9]->setPixmap(*terrain);
    labels[9]->setScaledContents(true);
    labels[19]->setPixmap(*terrain);
    labels[19]->setScaledContents(true);
    labels[29]->setPixmap(*terrain);
    labels[29]->setScaledContents(true);
    labels[39]->setPixmap(*terrain);
    labels[39]->setScaledContents(true);
    labels[59]->setPixmap(*terrain);
    labels[59]->setScaledContents(true);
    labels[79]->setPixmap(*terrain);
    labels[79]->setScaledContents(true);
    labels[89]->setPixmap(*terrain);
    labels[89]->setScaledContents(true);
    labels[10]->setPixmap(*terrain);
    labels[10]->setScaledContents(true);
    labels[20]->setPixmap(*terrain);
    labels[20]->setScaledContents(true);
    labels[30]->setPixmap(*terrain);
    labels[30]->setScaledContents(true);
    labels[40]->setPixmap(*terrain);
    labels[40]->setScaledContents(true);
    labels[50]->setPixmap(*terrain);
    labels[50]->setScaledContents(true);
    labels[60]->setPixmap(*terrain);
    labels[60]->setScaledContents(true);
    labels[70]->setPixmap(*terrain);
    labels[70]->setScaledContents(true);
    labels[80]->setPixmap(*terrain);
    labels[80]->setScaledContents(true);
    labels[90]->setPixmap(*terrain);
    labels[90]->setScaledContents(true);
    labels[91]->setPixmap(*terrain);
    labels[91]->setScaledContents(true);
    labels[92]->setPixmap(*terrain);
    labels[92]->setScaledContents(true);


    //insert trees (can't be build on)
    labels[11]->setPixmap(*tree);
    labels[11]->setScaledContents(true);
    labels[13]->setPixmap(*tree);
    labels[13]->setScaledContents(true);
    labels[14]->setPixmap(*tree);
    labels[14]->setScaledContents(true);
    labels[16]->setPixmap(*tree);
    labels[16]->setScaledContents(true);
    labels[21]->setPixmap(*tree);
    labels[21]->setScaledContents(true);
    labels[22]->setPixmap(*tree);
    labels[22]->setScaledContents(true);
    labels[31]->setPixmap(*tree);
    labels[31]->setScaledContents(true);
    labels[32]->setPixmap(*tree);
    labels[32]->setScaledContents(true);
    labels[34]->setPixmap(*tree);
    labels[34]->setScaledContents(true);
    labels[35]->setPixmap(*tree);
    labels[35]->setScaledContents(true);
    labels[36]->setPixmap(*tree);
    labels[36]->setScaledContents(true);
    labels[38]->setPixmap(*tree);
    labels[38]->setScaledContents(true);
    labels[52]->setPixmap(*tree);
    labels[52]->setScaledContents(true);
    labels[58]->setPixmap(*tree);
    labels[58]->setScaledContents(true);
    labels[61]->setPixmap(*tree);
    labels[61]->setScaledContents(true);
    labels[62]->setPixmap(*tree);
    labels[62]->setScaledContents(true);
    labels[63]->setPixmap(*tree);
    labels[63]->setScaledContents(true);
    labels[65]->setPixmap(*tree);
    labels[65]->setScaledContents(true);
    labels[66]->setPixmap(*tree);
    labels[66]->setScaledContents(true);
    labels[68]->setPixmap(*tree);
    labels[68]->setScaledContents(true);
    labels[71]->setPixmap(*tree);
    labels[71]->setScaledContents(true);
    labels[72]->setPixmap(*tree);
    labels[72]->setScaledContents(true);
    labels[78]->setPixmap(*tree);
    labels[78]->setScaledContents(true);
    labels[82]->setPixmap(*tree);
    labels[82]->setScaledContents(true);
    labels[84]->setPixmap(*tree);
    labels[84]->setScaledContents(true);
    labels[85]->setPixmap(*tree);
    labels[85]->setScaledContents(true);
    labels[86]->setPixmap(*tree);
    labels[86]->setScaledContents(true);
    labels[87]->setPixmap(*tree);
    labels[87]->setScaledContents(true);
    labels[41]->setPixmap(*tree);
    labels[41]->setScaledContents(true);
    labels[42]->setPixmap(*tree);
    labels[42]->setScaledContents(true);
    labels[44]->setPixmap(*tree);
    labels[44]->setScaledContents(true);
    labels[45]->setPixmap(*tree);
    labels[45]->setScaledContents(true);
    labels[46]->setPixmap(*tree);
    labels[46]->setScaledContents(true);
    labels[47]->setPixmap(*tree);
    labels[47]->setScaledContents(true);
    labels[48]->setPixmap(*tree);
    labels[48]->setScaledContents(true);

    //create initial monsters off the board at first, one after another
    //also creating parallel QVector with monster hit points


    num_monsters=13;
    monster_hp=20;


    monster_positions = new QPoint[num_monsters];
    monster_positions[0].setX(-1);
    monster_positions[0].setY(0);
    monster_positions[1].setX(-3);
    monster_positions[1].setY(0);
    monster_positions[2].setX(-5);
    monster_positions[2].setY(0);
    monster_positions[3].setX(-7);
    monster_positions[3].setY(0);
    monster_positions[4].setX(-9);
    monster_positions[4].setY(0);
    monster_positions[5].setX(-11);
    monster_positions[5].setY(0);
    monster_positions[6].setX(-13);
    monster_positions[6].setY(0);
    monster_positions[7].setX(-15);
    monster_positions[7].setY(0);
    monster_positions[8].setX(-17);
    monster_positions[8].setY(0);
    monster_positions[9].setX(-19);
    monster_positions[9].setY(0);
    monster_positions[10].setX(-21);
    monster_positions[10].setY(0);
    monster_positions[11].setX(-23);
    monster_positions[11].setY(0);
    monster_positions[12].setX(-25);
    monster_positions[12].setY(0);


    for(int i=0; i<num_monsters; i++)
        monster_holder.push_back(monster_positions[i]);

    for(int i=0; i<num_monsters; ++i)
        hp_holder.push_back(monster_hp);



    num_monsters2=15;
    monster_hp2=25;


    monster_positions = new QPoint[num_monsters2];
    monster_positions[0].setX(-1);
    monster_positions[0].setY(0);
    monster_positions[1].setX(-3);
    monster_positions[1].setY(0);
    monster_positions[2].setX(-5);
    monster_positions[2].setY(0);
    monster_positions[3].setX(-7);
    monster_positions[3].setY(0);
    monster_positions[4].setX(-9);
    monster_positions[4].setY(0);
    monster_positions[5].setX(-11);
    monster_positions[5].setY(0);
    monster_positions[6].setX(-13);
    monster_positions[6].setY(0);
    monster_positions[7].setX(-15);
    monster_positions[7].setY(0);
    monster_positions[8].setX(-17);
    monster_positions[8].setY(0);
    monster_positions[9].setX(-19);
    monster_positions[9].setY(0);
    monster_positions[10].setX(-21);
    monster_positions[10].setY(0);
    monster_positions[11].setX(-23);
    monster_positions[11].setY(0);
    monster_positions[12].setX(-25);
    monster_positions[12].setY(0);
    monster_positions[13].setX(-27);
    monster_positions[13].setY(0);
    monster_positions[14].setX(-29);
    monster_positions[14].setY(0);



    for(int i=0; i<num_monsters2; i++)
        monsterx_holder.push_back(monster_positions[i]);

    for(int i=0; i<num_monsters2; ++i)
        hpx_holder.push_back(monster_hp2);


    num_boss=1;
    boss_hp=100;

    monster_positions = new QPoint[num_boss];
    monster_positions[0].setX(-1);
    monster_positions[0].setY(0);

    for(int i=0; i<num_boss; i++)
        boss_holder.push_back(monster_positions[i]);

    for(int i=0; i<num_boss; ++i)
        b_holder.push_back(boss_hp);







    //start button
    start=new QPushButton("Start");

    start->setCheckable(true);
    start->setStyleSheet("QPushButton:checked {color: black; background-color: gray;}");

    internal_timer=new QTimer(this);
    QObject::connect(start, SIGNAL(clicked()), this, SLOT(startTimer()));

    //help screen
    instruction=new QPushButton("Instructions");
    QString help_text="Push start to begin the game. \n You can build towers on labels that have 'Build Here' on them. \n Each Tower costs 100 gold and you gain gold passively as the game progresses \n and also when a monster is defeated. Upgrades costs 200 gold \n and increases damage of all towers by 20%. \n Damage dealt is given by 'number of towers*multipler(starts at 1, increases by 20% per upgrade)'. \n Towers do damage to monster closest to 'Goal' first. \n There are 3 levels, good luck." ;
    QLabel* help_screen= new QLabel(help_text);
    help_screen->setMinimumSize(500,250);
    help_screen->setMaximumSize(500,250);
    help_screen->setAlignment(Qt::AlignTop);
    help_screen->setWindowTitle("Help Screen");
    QObject::connect(instruction, SIGNAL(clicked()), help_screen, SLOT(show()));
    QHBoxLayout* bottom=new QHBoxLayout;
    bottom->addWidget(instruction);
    bottom->addWidget(start);


    QHBoxLayout* realBottom=new QHBoxLayout;
    upgrade=new QPushButton("Upgrade");
    pause =new QPushButton("Pause");
    QObject::connect(upgrade, SIGNAL(clicked()), this, SLOT(upgradeTowers()));
    QObject::connect(pause, SIGNAL(clicked()), this, SLOT(pauseTimer()));
    realBottom->addWidget(upgrade);
    realBottom->addWidget(pause);


    //Piecing things together
    QVBoxLayout* rightSide = new QVBoxLayout;
    rightSide->addWidget(game_board);
    rightSide->addWidget(Top);
    rightSide->addLayout(bottom);
    rightSide->addLayout(realBottom);

    QHBoxLayout* finalScreen= new QHBoxLayout;
    finalScreen->addLayout(rightSide);



    //do not allow resize
    this->setFixedSize(600,600);

    //to show board after clicking on menu
    this->setLayout(finalScreen);

}

/**
 * @brief GameBoard::~GameBoard destructor that deletes the customLabel* and monster_position* and temp* in tower_holder
 */
GameBoard::~GameBoard(){
    delete [] labels;
    delete [] monster_positions;
    for(auto x: tower_holder) delete x;

}

/**
 * @brief GameBoard::closeEvent Event to be called when exiting game.
 * @param e ignore default quit screen and implement quit widget quit screen.
 */
void GameBoard::closeEvent(QCloseEvent *e) {

    e->ignore();
    quit->show();

}

/**
 * @brief GameBoard::setQuitWidget sets a quit widget as GameBoard's child.
 * @param quitWidget quit widget * that is being passed through by value.
 */
void GameBoard::setQuitWidget(QuitWidget* quitWidget) {

    quit = quitWidget;

}

/**
 * @brief GameBoard::setMainWindow sets a MainWindow as GameBoard's parent.
 * @param mainWindow MainWindow* passed through by value.
 */
void GameBoard::setMainWindow(MainWindow* mainWindow) {
    gameScreen = mainWindow;

}

/**
 * @brief GameBoard::paintEvent redraws the game board and labels at each iteration of movement and increment
 * @param e unused parameter
 */
void GameBoard::paintEvent(QPaintEvent *e){
    if(current_level==1){
    for(size_t i=0;i<monster_holder.size();i++) {
        int x = monster_holder[i].rx();
        int y = monster_holder[i].ry();
        int z = hp_holder[i];


            if(x>=0 && y >= 0 && x<board_size && y<board_size && z>0 ) {
                labels[y*board_size+x]->setPixmap(*monster_image);
                labels[y*board_size+x]->setScaledContents(true);
              }
        }
    }

    if(current_level==2){
    for(size_t i=0;i<monsterx_holder.size();i++) {
        int x = monsterx_holder[i].rx();
        int y = monsterx_holder[i].ry();
        int z = hpx_holder[i];


            if(x>=0 && y >= 0 && x<board_size && y<board_size && z>0 ) {
                labels[y*board_size+x]->setPixmap(*creature_image);
                labels[y*board_size+x]->setScaledContents(true);
              }
        }
    }

    if(current_level==3){
    for(size_t i=0;i<boss_holder.size();i++) {
        int x = boss_holder[i].rx();
        int y = boss_holder[i].ry();
        int z = b_holder[i];


            if(x>=0 && y >= 0 && x<board_size && y<board_size && z>0 ) {
                labels[y*board_size+x]->setPixmap(*boss_image);
                labels[y*board_size+x]->setScaledContents(true);
              }
        }
    }
    return;
}

/**
 * @brief GameBoard::moveMonsters Called when timer times out. Moves monster and increments gold.
 * Each level will be different and when a monster hits the "goal" label, timer is stopped and game ends.
 * The monsters follow a pre-defined path that is defined in this function.
 */
void GameBoard::moveMonsters(){

    //increment gold by timer as well
    gold->clear();
    gold_amount++;
    gold->setNum(gold_amount);

    if(current_level==1){
    for(size_t i=0;i<monster_holder.size();i++) {

        if(hp_holder[i]>0){
        int x = monster_holder[i].rx();
        int y = monster_holder[i].ry();
        int nx, ny;


        if(x>=0 && y >= 0 && x<board_size && y<board_size){
                    labels[y*board_size+x]->clear();

        }

        if(x<8 && y==0){
             nx=x;
             ny=y;
             nx++;
        }

        if(x==8 && y<=2){
            nx=x;
            ny=y;
            ny++;
        }

        if(y==2 && x>3){
            nx=x;
            ny=y;
            nx--;
        }

        if(x==3 && y==2){
            nx=x;
            ny=y;
            ny++;
        }

        if(x==3 && y==3){
            nx=x;
            ny=y;
            ny++;
        }

        if(x==3 && y==4){
            nx=x;
            ny=y;
            ny++;
        }

        if(y==5 && x<7){
            nx=x;
            ny=y;
            nx++;
        }

        if(x==7 && y==5){
            nx=x;
            ny=y;
            ny++;
        }

        if(x==7 && y==5){
            nx=x;
            ny=y;
            ny++;
        }

        if(x==7 && y==6){
            nx=x;
            ny=y;
            ny++;
        }

        if(x==7 && y==7){
            nx=x;
            ny=y;
            nx--;
        }


        if(x==6 && y==7){
            nx=x;
            ny=y;
            nx--;
        }


        if(x==5 && y==7){
            nx=x;
            ny=y;
            nx--;
        }


        if(x==4 && y==7){
            nx=x;
            ny=y;
            nx--;
        }

        if(x==3 && y==7){
            nx=x;
            ny=y;
            ny++;
        }

        if(x==3 && y==8){
            nx=x;
            ny=y;
            ny++;
        }

        if(x==3 && y==9){
            nx=x;
            ny=y;
            nx++;
        }

        if(x==4 && y==9){
            nx=x;
            ny=y;
            nx++;
        }

        if(x==5 && y==9){
            nx=x;
            ny=y;
            nx++;
        }

        if(x==6 && y==9){
            nx=x;
            ny=y;
            nx++;
        }

        if(x==7 && y==9){
            nx=x;
            ny=y;
            nx++;
        }

        if(x==8 && y==9){
            nx=x;
            ny=y;
            nx++;
        }

        if(x==9 && y==9){
            internal_timer->stop();
            lose_screen->show();
        }


        monster_holder[i].setX(nx);
        monster_holder[i].setY(ny);

        }
    }

        hp_holder[0]-=(tower_holder.size()*multiplier);
        if( hp_holder.size()>0 && monster_holder.size() >0 && hp_holder[0]<=0){
             monster_holder.pop_front();
             hp_holder.pop_front();
             gold->clear();
             gold_amount+=10;
             gold->setNum(gold_amount);
             }
    }


     if(monster_holder.size()<=0 && current_level==1){
        level->clear();
        current_level=2;
        level->setNum(current_level);

     }

     if(current_level==2){
     for(size_t i=0;i<monsterx_holder.size();i++) {

         if(hpx_holder[i]>0){
         int x = monsterx_holder[i].rx();
         int y = monsterx_holder[i].ry();
         int nx, ny;


         if(x>=0 && y >= 0 && x<board_size && y<board_size){
                     labels[y*board_size+x]->clear();

         }

         if(x<8 && y==0){
              nx=x;
              ny=y;
              nx++;
         }

         if(x==8 && y<=2){
             nx=x;
             ny=y;
             ny++;
         }

         if(y==2 && x>3){
             nx=x;
             ny=y;
             nx--;
         }

         if(x==3 && y==2){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==3 && y==3){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==3 && y==4){
             nx=x;
             ny=y;
             ny++;
         }

         if(y==5 && x<7){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==7 && y==5){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==7 && y==5){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==7 && y==6){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==7 && y==7){
             nx=x;
             ny=y;
             nx--;
         }


         if(x==6 && y==7){
             nx=x;
             ny=y;
             nx--;
         }


         if(x==5 && y==7){
             nx=x;
             ny=y;
             nx--;
         }


         if(x==4 && y==7){
             nx=x;
             ny=y;
             nx--;
         }

         if(x==3 && y==7){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==3 && y==8){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==3 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==4 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==5 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==6 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==7 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==8 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==9 && y==9){
             internal_timer->stop();
             lose_screen->show();
         }


         monsterx_holder[i].setX(nx);
         monsterx_holder[i].setY(ny);

         }
     }

         hpx_holder[0]-=(tower_holder.size()*multiplier);

         if( hpx_holder.size()>0 && monsterx_holder.size() >0 && hpx_holder[0]<=0){
              monsterx_holder.pop_front();
              hpx_holder.pop_front();
              gold->clear();
              gold_amount+=15;
              gold->setNum(gold_amount);

              }
         if(monsterx_holder.size()<=0 && current_level==2){
            level->clear();
            current_level=3;
            level->setText("Boss");

         }
     }

     if(current_level==3){
     for(size_t i=0;i<boss_holder.size();i++) {

         if(b_holder[i]>0){
         int x = boss_holder[i].rx();
         int y = boss_holder[i].ry();
         int nx, ny;


         if(x>=0 && y >= 0 && x<board_size && y<board_size){
                     labels[y*board_size+x]->clear();

         }

         if(x<8 && y==0){
              nx=x;
              ny=y;
              nx++;
         }

         if(x==8 && y<=2){
             nx=x;
             ny=y;
             ny++;
         }

         if(y==2 && x>3){
             nx=x;
             ny=y;
             nx--;
         }

         if(x==3 && y==2){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==3 && y==3){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==3 && y==4){
             nx=x;
             ny=y;
             ny++;
         }

         if(y==5 && x<7){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==7 && y==5){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==7 && y==5){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==7 && y==6){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==7 && y==7){
             nx=x;
             ny=y;
             nx--;
         }


         if(x==6 && y==7){
             nx=x;
             ny=y;
             nx--;
         }


         if(x==5 && y==7){
             nx=x;
             ny=y;
             nx--;
         }


         if(x==4 && y==7){
             nx=x;
             ny=y;
             nx--;
         }

         if(x==3 && y==7){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==3 && y==8){
             nx=x;
             ny=y;
             ny++;
         }

         if(x==3 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==4 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==5 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==6 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==7 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==8 && y==9){
             nx=x;
             ny=y;
             nx++;
         }

         if(x==9 && y==9){
             internal_timer->stop();
             lose_screen->show();
         }


         boss_holder[i].setX(nx);
         boss_holder[i].setY(ny);

         }
     }


      b_holder[0]-=(tower_holder.size()*multiplier);

      if(b_holder[0]<=0){
         b_holder.pop_front();
         boss_holder.pop_front();
         internal_timer->stop();
         QLabel* victory=new QLabel("<h2> You Won. </h2> \n  <h2>Try a harder difficulty </h2>");
         victory->show();
         }





    QCoreApplication::processEvents();

    repaint();


    }
}

/**
 * @brief GameBoard::startTimer This gets called when "start" is pressed. The timer is on a loop that restarts itself each time it is timed out.
 */
void GameBoard::startTimer(){
    connect(internal_timer, SIGNAL(timeout()), this, SLOT(moveMonsters()));
    internal_timer->start(1500);

}

/**
 * @brief GameBoard::pauseTimer Pauses timer/ Restarts timer depending on the state of the timer.
 */
void GameBoard::pauseTimer(){
    if(internal_timer->isActive())
        internal_timer->stop();
    else{
        internal_timer->start(1500);
    }

}

/**
 * @brief GameBoard::upgradeTowers This function is called when the "upgrade" button is pressed.
 * All towers on the board and all future towers built will have their damage increased by 20% for each upgrade. Each upgrade costs 200 gold.
 */
void GameBoard::upgradeTowers(){

    if(tower_holder.size()>0 && gold_amount>200){
        multiplier*=1.2;
        gold->clear();
        gold_amount-=200;
        gold->setNum(gold_amount);
    }

}
