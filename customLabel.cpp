#include "customLabel.h"

/**
 * @brief customLabel::customLabel default constructor that allows for construction without parent
 * @param parent takes in a QWidget parent
 */
customLabel::customLabel(QWidget * parent) : QLabel(parent)
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );

}

/**
 * @brief customLabel::customLabel
 * @param p takes in GameBoard pointer as a parent
 * @param parent takes in a QWidget as a parent
 */
customLabel::customLabel(GameBoard* p, QWidget * parent) : QLabel(parent), z(p)
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );

}

/**
 * @brief customLabel::slotClicked Slot function to be called when a customLabel is clicked
 */
void customLabel::slotClicked()
{

}

/**
 * @brief customLabel::mouseReleaseEvent When the conditions are met, clicking on a label will place a tower QPixmap over it and saves the coordinates in a vector<QPoint*>
 * @param event Necessary input parameter that will not be used. Can be used to locate global coordinates of QLabel. pos();
 */
void customLabel::mouseReleaseEvent ( QMouseEvent * event )
{
    QString towerFileName("/Qt/Tools/QtCreator/bin/TowerDefence/tower.png");
    tower_image= new QPixmap(towerFileName);

    if(z->gold_amount>=100){
      if(this->label_coordinate==QPoint(7,1) || this->label_coordinate==QPoint(4,6) || this->label_coordinate==QPoint(5,1) || this->label_coordinate==QPoint(6,4) || this->label_coordinate==QPoint(2,1) || this->label_coordinate==QPoint(7,3) || this->label_coordinate==QPoint(1,5) || this->label_coordinate==QPoint(1,8) || this->label_coordinate==QPoint(8,8)|| this->label_coordinate==QPoint(9,4) || this->label_coordinate==QPoint(9,6) )
    {
        this->setPixmap(*tower_image);
        this->setScaledContents(true);
        temp=new QPoint;
        temp->setX(this->label_coordinate.rx());
        temp->setY(this->label_coordinate.ry());
        bool copy=false;

        if(z->tower_holder.size()==0)
            copy=false;

            else {
                for(int i=0; i<z->tower_holder.size(); ++i){
                    QPoint e=*z->tower_holder[i];
                        if(e==*temp)
                            copy=true;
             }

        }
    if(!copy){
        z->tower_holder.push_back(temp);
        z->gold->clear();
        z->gold_amount=z->gold_amount-100;
        z->gold->setNum(z->gold_amount);
        }
    }
    }
    emit clicked();

}

/**
 * @brief customLabel::~customLabel Destructor
 */
customLabel::~customLabel()
{

}
