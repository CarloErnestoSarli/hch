#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QFile>
#include <QDebug>
#include "node.h"

class DataHandler
{
public:
    DataHandler();
    std::vector<Node> readCsvNodes();
    QMultiHash<QString, QString> readCsvLinks();
    int calculateNodesNumber(std::vector<Node> nodes);
};

#endif // DATAHANDLER_H
