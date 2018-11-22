#ifndef OPENGLVIEWER_H
#define OPENGLVIEWER_H

#include <QDebug>
#include<QTreeWidget>


#include "openglheader.h"

class QtOSGWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
  QtOSGWidget(qreal scaleX, qreal scaleY, QWidget* parent = 0);

  void otherModel();


  virtual ~QtOSGWidget(){}

    void setScale(qreal X, qreal Y);

protected:

    virtual void paintGL();


    virtual void resizeGL( int width, int height );
    virtual void initializeGL();
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void wheelEvent(QWheelEvent* event);
    virtual bool event(QEvent* event);

private:

    osgGA::EventQueue* getEventQueue() const;
    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> _mGraphicsWindow;
    osg::ref_ptr<osgViewer::Viewer> _mViewer;
    qreal m_scaleX;
    qreal m_scaleY;


public slots:
    void showMsg1(QTreeWidgetItem *item,int colindex);

};

#endif // OPENGLVIEWER_H
