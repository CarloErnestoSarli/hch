#include "link.h"

Link::Link()
{

}

QString Link::GetInputName()
{
    return m_inputName;
}

QString Link::GetOutputName()
{
    return m_outputName;
}

void Link::SetInputName(QString n)
{
    m_inputName = n;
}

void Link::SetOutputName(QString n)
{
    m_outputName = n;
}
