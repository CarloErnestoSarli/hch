#ifndef CHORDDIAGRAM_H
#define CHORDDIAGRAM_H

#include <math.h>
#include <QLineF>

#include "node.h"
#include "datahandler.h"

class ChordDiagram
{

public:
    ChordDiagram();
    void SetNumberOfNodes(int n);
    int GetNumberOfNodes();

    void SetNodes(std::vector<Node> n);
    std::vector<Node> GetNodes();
    std::vector<Link> GetLinks();
    void SetLinks(std::vector<Link> l);
    void CalculateCentreOfArcs();
    void CalculateBoundingBoxes();

private:
    std::vector<Node> m_nodes;
    std::vector<Link> m_links;
    int m_numberOfNodes;
    void init();
    QPointF convertPolarToCartesian(double c);
};

#endif // CHORDDIAGRAM_H
