#include "customLabelm.h"

customLabelh::customLabelh(QWidget * parent) : QLabel(parent)
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );

}

customLabelh::customLabelh(hGameBoard* p, QWidget * parent) : QLabel(parent), t(p)
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );

}

void customLabelh::slotClicked()
{

}

void customLabelh::mouseReleaseEvent ( QMouseEvent * event )
{
    QString towerFileName("/Qt/Tools/QtCreator/bin/TowerDefence/tower.png");
    tower_image= new QPixmap(towerFileName);

    if(t->gold_amount>100){
         if(this->label_coordinate==QPoint(7,1) ||this->label_coordinate==QPoint(4,6) || this->label_coordinate==QPoint(5,1) || this->label_coordinate==QPoint(6,4) || this->label_coordinate==QPoint(2,1) || this->label_coordinate==QPoint(7,3) || this->label_coordinate==QPoint(1,5) || this->label_coordinate==QPoint(1,8) || this->label_coordinate==QPoint(8,8)|| this->label_coordinate==QPoint(9,4) || this->label_coordinate==QPoint(9,6) )
    {
        this->setPixmap(*tower_image);
        this->setScaledContents(true);
        temp=new QPoint;
        temp->setX(this->label_coordinate.rx());
        temp->setY(this->label_coordinate.ry());
        bool copy=false;

        if(t->tower_holder.size()==0)
            copy=false;

            else {
                for(int i=0; i<t->tower_holder.size(); ++i){
                    QPoint e=*t->tower_holder[i];
                        if(e==*temp)
                            copy=true;
             }

        }
    if(!copy){
        t->tower_holder.push_back(temp);
        t->gold->clear();
        t->gold_amount=t->gold_amount-100;
        t->gold->setNum(t->gold_amount);
        }
    }
    }
    emit clicked();

}

customLabelh::~customLabelh()
{

}

