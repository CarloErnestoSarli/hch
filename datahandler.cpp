#include "datahandler.h"


DataHandler::DataHandler()
{

}

std::vector<Node> DataHandler::readCsvNodes()
{
    std::vector<Node> nodes;
    //needs refactoring
    QFile file("/home/carlo/Development/PhD/C++/hch/data/InternetOfEnergy.csv");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "File does not exists";
    }else
    {
        QTextStream in(&file);
        in.readLine();
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QString firstColumn = line.split(",").first();
            QString group = line.split(",").at(3);
            Node *n = new Node();
            n->SetName(firstColumn);
            n->SetHighlighted(false);
            n->SetGroup(group.toInt());
            nodes.push_back(*n);

        }
        file.close();
    }
    return nodes;
}


std::vector<Link> DataHandler::readCsvLinks()
{
    std::vector<Link> links;
    int inputsPos = 1;
    int outputsPos = 2;

    //needs refactoring
    QFile file("/home/carlo/Development/PhD/C++/hch/data/InternetOfEnergy.csv");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "File does not exists";
    }else
    {
        QTextStream in(&file);
        in.readLine();

        while(!in.atEnd())
        {
            QString line = in.readLine();
            QString node = line.split(",").first();
            QString inputs = line.split(",").at(1);
            QString outputs = line.split(",").at(2);

            //needs refactoring
            if(inputs.isEmpty())
            {

            }else
            {
                for(int i=0; i<inputs.split(";").size(); ++i)
                {
                    QString input = inputs.split(";").at(i);
                    Link *l = new Link();
                    l->SetInputName(input);
                    l->SetOutputName(node);
                    links.push_back(*l);
                }
            }
            if(outputs.isEmpty())
            {

            }else
            {
                for(int j=0; j<outputs.split(";").size(); ++j)
                {
                    QString output = outputs.split(";").at(j);
                    Link *l = new Link();
                    l->SetInputName(node);
                    l->SetOutputName(output);
                    links.push_back(*l);

                }

            }
        }

        file.close();
    }

    return links;

}

int DataHandler::calculateNodesNumber(std::vector<Node> nodes)
{
    return nodes.size();
}


