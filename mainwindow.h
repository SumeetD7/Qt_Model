#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSize>
#include<QString>
#include<QTreeWidget>
#include<QBrush>


#include "openglviewer.h"
#include "openglheader.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

   public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    //void defaultImg();
    void addTreeRoot1(QString name);
    void addTreeChild1(QTreeWidgetItem *parent,QString name);
    void addTreeChild2(QTreeWidgetItem *parent,QString name);
    void addTreeChild3(QTreeWidgetItem *parent,QString name);

    void addSubTreeChild1(QTreeWidgetItem *parent,QString name);
    void addSubTreeChild2(QTreeWidgetItem *parent,QString name);\

    private:
        Ui::MainWindow *ui;

        int ht,wd;


    public slots:
        void showImg1();
        void showImg2();
        void showImg3();
        void showImg4();
        void showImg5();

        void showMsg(QTreeWidgetItem *item,int colindex);





};

#endif // MAINWINDOW_H
