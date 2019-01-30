#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QFile>
#include <QDebug>
#include "node.h"
#include "link.h"

class DataHandler
{
public:
    DataHandler();
    std::vector<Node> readCsvNodes();
    std::vector<Link> readCsvLinks();
    int calculateNodesNumber(std::vector<Node> nodes);
};

#endif // DATAHANDLER_H
