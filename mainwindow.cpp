#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openglheader.h"
#include "openglviewer.h"
#include <QDebug>
#include <QLabel>
#include <QtGui>
#include <QLabel>
#include <QTreeWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //this->setCentralWidget(_mainWidget);


    QRect rec= QApplication::desktop()->screenGeometry();
    ht=rec.height();
    wd=rec.width();
    qDebug() << "ht:" << ht << "wd:" << wd;

    QtOSGWidget* widget1 = new QtOSGWidget(1, 1, ui->label);
    widget1->setMinimumSize(wd-500,ht);

    //tree widget


    ui->treeWidget->setMinimumSize(wd,ht);


    ui->treeWidget->setColumnCount(1);

    ui->treeWidget->setHeaderLabels(QStringList()<<"Project");

    addTreeRoot1("Shapes");


    QObject::connect(ui->treeWidget, SIGNAL ( itemClicked(QTreeWidgetItem *,int) ),widget1, SLOT(showMsg1(QTreeWidgetItem *,int ) ));

}


MainWindow::~MainWindow()
{

}


void MainWindow::showMsg(QTreeWidgetItem *item,int colindex)
{

    qDebug() << "Item clciked " << " int val = " << colindex;
    qDebug() << " item : " <<item->text(colindex);
    if ( item->text(colindex) ==  "Circle" )
    {
        showImg1();
    }
    else if ( item->text(colindex) ==  "Ellipse" )
    {
        showImg2();
    }
    else if ( item->text(colindex) ==  "Triangle" )
    {
        showImg3();
    } else if ( item->text(colindex) ==  "Square" )
    {
        showImg4();
    } else if ( item->text(colindex) ==  "Rectangle" )
    {
        showImg5();
    }
}


//void  MainWindow::defaultImg()
//{
//    QRect r(0,0, 100, 100);
//    QPixmap pm(r.size());
//    pm.fill();
//    QPainter p(&pm);
//    p.setRenderHint(QPainter::Antialiasing,true);
//    QPen pen(Qt::red, 2);
//    p.setPen(pen);
//    QBrush brush(Qt::blue);
//    p.setBrush(brush);
//    QRect ri = r.adjusted(10,10,-10,-10);
//    p.drawEllipse(ri);
//    ui->label->setPixmap(pm);
//}

//root

void MainWindow::addTreeRoot1(QString name)
{
    QTreeWidgetItem *item = new  QTreeWidgetItem(ui->treeWidget);
    item->setText(0,name);
    addTreeChild1(item,"Circular");
    addTreeChild2(item,"Triangle");
    addTreeChild3(item,"Square");

    item->setExpanded(true);
}

//child

void MainWindow::addTreeChild1(QTreeWidgetItem *parent ,QString name)
{
    QTreeWidgetItem *item1 = new  QTreeWidgetItem();
    item1->setText(0,name);
    parent->addChild(item1);
    addSubTreeChild1(item1,"Circle");
    addSubTreeChild2(item1,"Ellipse");
}

void MainWindow::addTreeChild2(QTreeWidgetItem *parent ,QString name)
{
    QTreeWidgetItem *item1 = new  QTreeWidgetItem();
    item1->setText(0,name);
    parent->addChild(item1);
    addSubTreeChild1(item1,"Triangle");

}


void MainWindow::addTreeChild3(QTreeWidgetItem *parent ,QString name)
{
    QTreeWidgetItem *item1 = new  QTreeWidgetItem();
    item1->setText(0,name);
    parent->addChild(item1);
    addSubTreeChild1(item1,"Square");
    addSubTreeChild2(item1,"Rectangle");
}

//sub child

void MainWindow::addSubTreeChild1(QTreeWidgetItem *parent ,QString name)
{
    QTreeWidgetItem *item1 = new  QTreeWidgetItem();
    item1->setText(0,name);
    parent->addChild(item1);
}
void MainWindow::addSubTreeChild2(QTreeWidgetItem *parent ,QString name)
{
    QTreeWidgetItem *item1 = new  QTreeWidgetItem();
    item1->setText(0,name);
    parent->addChild(item1);
}


void MainWindow::showImg1()
{

    QRect r(0,0, 100, 100);
    QPixmap pm(r.size());
    pm.fill();
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing,true);
    QPen pen(Qt::black, 2);
    p.setPen(pen);
    QBrush brush(Qt::green);
    p.setBrush(brush);
    QRect ri = r.adjusted(10,10,-10,-10);
    p.drawEllipse(ri);

    ui->label->setPixmap(pm);



}

void MainWindow::showImg2()
{

    QRect r(0,0, 100, 100);
    QPixmap pm(r.size());
    pm.fill();
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing,true);
    QPen pen(Qt::yellow, 2);
    p.setPen(pen);
    QBrush brush(Qt::black);
    p.setBrush(brush);
    QRect ri = r.adjusted(10,10,-10,-10);
    p.drawEllipse(ri);
    ui->label->setPixmap(pm);

}

void MainWindow::showImg3()
{
    QPolygon polygon;
    QRect r(0,0, 100, 100);
    QPixmap pm(r.size());
    pm.fill();
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing,true);
    QPen pen(Qt::red, 2);
    p.setPen(pen);
    QBrush brush(Qt::black);
    p.setBrush(brush);
    polygon << QPoint(20,20) << QPoint(60,60) << QPoint(25,90);
//    QRect ri = r.adjusted(10,10,-10,-10);

    p.drawPolygon(polygon);
    ui->label->setPixmap(pm);

}

void MainWindow::showImg4()
{


    QRect r(0,0, 100, 100);
    QPixmap pm(r.size());
    pm.fill();
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing,true);
    QPen pen(Qt::yellow, 2);
    p.setPen(pen);
    QBrush brush(Qt::blue);
    p.setBrush(brush);
    QRect ri = r.adjusted(10,10,-10,-10);

    p.drawRect(ri);
    ui->label->setPixmap(pm);

}

void MainWindow::showImg5()
{

    QRect r(0,0, 100, 100);
    QPixmap pm(r.size());
    pm.fill();
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing,true);
    QPen pen(Qt::cyan, 2);
    p.setPen(pen);
    QBrush brush(Qt::black);
    p.setBrush(brush);
    QRect ri = r.adjusted(10,10,-10,-10);
    p.drawRect(ri);
    ui->label->setPixmap(pm);

}


