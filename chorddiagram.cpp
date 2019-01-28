#include "chorddiagram.h"

const double RADIUS = 35.0;

ChordDiagram::ChordDiagram()
{
    init();
}


void ChordDiagram::init()
{
    DataHandler *o_data = new DataHandler();
    //import node data
    SetNodes(o_data->readCsvNodes());
    //SetLinks(o_data->readCsvLinks());
    //calculate nuber of nodes
    SetNumberOfNodes(m_nodes.size());

}



//import link data



//calcualateBoundingBoxes

//ConvertPolarToCartesian
QPointF ChordDiagram::convertPolarToCartesian(double c)
{
    double x = RADIUS * cos(c);
    double y = RADIUS * sin(c);
    return QPointF(x,y);
}

//calculateCentreOfArcs
void ChordDiagram::calculateCentreOfArcs()
{
    for(auto &it : GetNodes())
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
}

void ChordDiagram::SetNodes(std::vector<Node> n)
{
    m_nodes = n;
}

void ChordDiagram::SetLinks(QMultiHash<QString, QString> l)
{
    m_links = l;
}

void ChordDiagram::SetNumberOfNodes(int n)
{
    m_numberOfNodes = n;
}

QMultiHash<QString, QString> ChordDiagram::GetLinks()
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
