#ifndef LINK_H
#define LINK_H

#include <QString>



class Link
{
public:
    Link();

    QString GetInputName();
    QString GetOutputName();
    void SetInputName(QString n);
    void SetOutputName(QString n);

private:
    QString m_inputName;
    QString m_outputName;
};

#endif // LINK_H
