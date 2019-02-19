#include "chorddiagram.h"



const double RADIUS = 35.0;
const double CENTRE = 50.0;

ChordDiagram::ChordDiagram()
{
    init();
}


void ChordDiagram::init()
{
    DataHandler *o_data = new DataHandler();
    //import node data
    SetNodes(o_data->readCsvNodes());
    SetLinks(o_data->readCsvLinks());
    //calculate nuber of nodes
    SetNumberOfNodes(m_nodes.size());

}



//import link data



//calcualateBoundingBoxes

//ConvertPolarToCartesian
QPointF ChordDiagram::convertPolarToCartesian(double c)
{
    double x = RADIUS * cos(c) + CENTRE;
    double y = RADIUS * sin(c) + CENTRE;
    return QPointF(x,y);
}

//calculateCentreOfArcs
void ChordDiagram::CalculateCentreOfArcs()
{
    std::vector<Node> nodes = GetNodes();
    for(auto &it : nodes)
    {
        double polarStart = it.GetPolarStart();
        double polarEnd = it.GetPolarEnd();
        double polarCentre = (polarStart+polarEnd)/2;
        QPointF cartStart = convertPolarToCartesian(polarStart);
        QPointF cartEnd = convertPolarToCartesian(polarEnd);
        QPointF cartCentre = convertPolarToCartesian(polarCentre);

        it.SetCartStart(cartStart);
        it.SetCartEnd(cartEnd);
        it.SetCartCentre(cartCentre);
    }
    SetNodes(nodes);

}

void ChordDiagram::CalculateBoundingBoxes()
{
    std::vector<Node> nodes = GetNodes();
    for(auto &it : nodes)
    {
        QLineF distance(it.GetCartStart(), it.GetCartEnd());
        float sideLength = distance.length()/2;
        QPointF centre = it.GetCartCentre();
        //qDebug() << "Centre-----------" << centre;
        QPointF topLeft = QPointF(centre.x()-sideLength, centre.y()+sideLength);
        QPointF bottomRight = QPointF(centre.x()+sideLength, centre.y()-sideLength);
        QRectF boundingBox(topLeft, bottomRight);
        it.SetRectContainer(boundingBox);
    }
    SetNodes(nodes);
}

void ChordDiagram::SetNodes(std::vector<Node> n)
{
    m_nodes = n;
}

void ChordDiagram::SetLinks(std::vector<Link> l)
{
    m_links = l;
}

void ChordDiagram::SetNumberOfNodes(int n)
{
    m_numberOfNodes = n;
}

std::vector<Link> ChordDiagram::GetLinks()
{
    return m_links;
}

std::vector<Node> ChordDiagram::GetNodes()
{
    return m_nodes;
}

int ChordDiagram::GetNumberOfNodes()
{
    return m_numberOfNodes;
}
