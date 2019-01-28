#ifndef CANVAS_H
#define CANVAS_H

#include <QtOpenGL>
#include <QOpenGLWidget>

#include "chorddiagram.h"
#include "node.h"

class Canvas : public QOpenGLWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = nullptr);

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    void prepareDraw();
    void setOrtho();
    float calculateNumCircleSegments(float r);
    void drawCircle(float cx, float cy, float r, int numSegments);
    void drawArc(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments);
    QPointF normaliseMouseCoord(QPoint p);
    void placeArcs();
};


#endif // CANVAS_H
