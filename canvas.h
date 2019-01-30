#ifndef CANVAS_H
#define CANVAS_H

#include <QtOpenGL>
#include <QOpenGLWidget>
//#include <QResizeEvent>

#include "chorddiagram.h"
#include "node.h"

class Canvas : public QOpenGLWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = nullptr);

protected:
    //virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    void prepareDraw();
    void setOrtho();
    float calculateNumCircleSegments(float r);
    void drawCircle(float cx, float cy, float r, int numSegments);
    void drawArc(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments, bool highlighted);
    QPointF normaliseMouseCoord(QPoint p);
    void placeArcs();
    void placeCentrePoints();
    void drawCentreOfArc(QPointF c);
    void placeLinks();
    void drawLink(QPointF input, QPointF output);
    void drawBezierLink(QPointF input, QPointF output);
    QPointF calculateBezierePoint(QPointF input, QPointF output, QPointF control, double t);
    void drawBoundingBoxes(QRectF box);
    void placeBoundingBoxes();
    void mouseMoveEvent(QMouseEvent *event);
    void checkBoundingBoxIntersect(QPointF p);
};


#endif // CANVAS_H
