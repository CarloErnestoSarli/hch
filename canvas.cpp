#include "canvas.h"

const QPointF CIRCLE_CENTRE = QPointF(50,50);
static const double RADIUS = 35.0;
ChordDiagram *o_diagram = new ChordDiagram();



Canvas::Canvas(QWidget *parent) : QOpenGLWidget(parent)
{
    setMouseTracking(true);
}

void Canvas::initializeGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    //Required blending for alpha blending
    glEnable(GL_ALPHA);
    //used to add alpha values
    //renders using stencil buffer for concave polygons
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //set canvas background to white
    glClearColor(1.0,1.0,1.0,1.0);
}

void Canvas::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void Canvas::paintGL()
{
    prepareDraw();
    float numSegments = calculateNumCircleSegments(RADIUS);
    drawCircle(CIRCLE_CENTRE.x(), CIRCLE_CENTRE.y(), RADIUS, numSegments);
    placeArcs();
}


void Canvas::prepareDraw()
{
    glPointSize(1);
    setOrtho();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Canvas::setOrtho()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(0,100,0,100,-1,1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Canvas::placeArcs()
{
    qDebug() << "Placing";
    std::vector<Node> nodes = o_diagram->GetNodes();
    int numOfArcs = o_diagram->GetNumberOfNodes();
    float sizeOfArcNoGap = 2.0f * M_PI / numOfArcs;
    float gap = sizeOfArcNoGap/100*20;
    float sizeOfArc = sizeOfArcNoGap-gap;

    float startAngle = 0;
    float numSegments = calculateNumCircleSegments(RADIUS);

    for(int i=0; i<numOfArcs; ++i)
    {
        Node &node = nodes.at(i);
        startAngle = i*sizeOfArcNoGap;
        node.SetPolarStart(startAngle);
        node.SetPolarSpan(sizeOfArc);
        node.SetPolarEnd(startAngle+sizeOfArc);
        drawArc(CIRCLE_CENTRE.x(), CIRCLE_CENTRE.y(), RADIUS, startAngle, sizeOfArc, numSegments);
    }
    //pass in the array with the updated values to the object
    o_diagram->SetNodes(nodes);
}

//calculates the number of segments that will compose the circle
float Canvas::calculateNumCircleSegments(float r)
{
    return 10 * sqrtf(r); //change10 to increase/decrease precision
}

void Canvas::drawCircle(float cx, float cy, float r, int numSegments)
{
    qDebug()<<"Drawing";
    float theta = 2.0f * M_PI / float(numSegments);
        float c = cosf(theta);//precalculate the sine and cosine
        float s = sinf(theta);
        float t;

        float x = r;//we start at angle = 0
        float y = 0;

        glLineWidth(1);
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i < numSegments; i++)
        {
            glColor3d(1.0,0.0,1.0);
            glVertex2f(x + cx, y + cy);//output vertex

            //apply the rotation matrix
            t = x;
            x = c * x - s * y;
            y = s * t + c * y;
        }
        glEnd();
}


void Canvas::drawArc(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments)
{
    float theta = arc_angle / float(num_segments - 1);
    //theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

    float tangetial_factor = tanf(theta);
    float radial_factor = cosf(theta);

    float x = r * cosf(start_angle);
    //we now start at the start angle
    float y = r * sinf(start_angle);

    glLineWidth(5);
    glBegin(GL_LINE_STRIP);
    //since the arc is not a closed curve, this is a strip now
    for(int ii = 0; ii < num_segments; ii++)
    {
        glColor3d(1,0.5,0.0);

        glVertex2f(x + cx, y + cy);

        float tx = -y;
        float ty = x;

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}


QPointF Canvas::normaliseMouseCoord(QPoint p)
{
    double maxRY = this->height();
    double maxRX = this->width();
    double minRX = 0;
    double minRY = 0;
    double minTX = 0;
    double minTY = 0;
    double maxTX = 100;
    double maxTY = 100;

    double mx = ((p.x() - minRX)/(maxRX - minRX))*(maxTX-minTX)+minTX;
    double my = -(((p.y() - minRY)/(maxRY - minRY))*(maxTY-minTY)+minTY);

    return QPointF(mx,my);

}
