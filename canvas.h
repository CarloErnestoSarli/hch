#ifndef CANVAS_H
#define CANVAS_H

#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLFunctions>
#include <QOpenGLFramebufferObject>


#include "chorddiagram.h"
#include "node.h"

class Canvas : public QOpenGLWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = nullptr);
    ~Canvas();

    void SetBoundingBoxToggle(bool t);
    bool GetBoundingBoxToggle();
    void SetCenterOfArcsToggle(bool t);
    bool GetCenterOfArcsToggle();


protected:
    //virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    QOpenGLShaderProgram m_program;

    int m_xPointsAttr;
    int m_yPointsAttr;
    int m_colourAttr;
    int m_textureAttr;
    int m_matrixUniform;

    QOpenGLBuffer m_xPointsBuff;
    QOpenGLBuffer m_yPointsBuff;
    QOpenGLBuffer m_colourBuff;

    QOpenGLVertexArrayObject m_vertexArray;


    bool m_boundingBoxToggle = false;
    bool m_centerOfArcsToggle = false;

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
    void drawBezierLink(QPointF input, QPointF output, QColor c1, QColor c2);
    QPointF calculateBezierePoint(QPointF input, QPointF output, QPointF control, double t);
    void drawBoundingBoxes(QRectF box);
    void placeBoundingBoxes();
    void mouseMoveEvent(QMouseEvent *event);
    void checkBoundingBoxIntersect(QPointF p);

private slots:
    void boundingBoxesCheckboxToggle(bool toggled);
    void centerOfArcsCheckboxToggle(bool toggled);
};


#endif // CANVAS_H
