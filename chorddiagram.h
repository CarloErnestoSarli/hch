#ifndef CHORDDIAGRAM_H
#define CHORDDIAGRAM_H

#include <math.h>

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
    QMultiHash<QString, QString> GetLinks();
    void SetLinks(QMultiHash<QString, QString> l);
private:
    std::vector<Node> m_nodes;
    QMultiHash<QString, QString> m_links;
    int m_numberOfNodes;
    void init();
    QPointF convertPolarToCartesian(double c);
};

#endif // CHORDDIAGRAM_H
