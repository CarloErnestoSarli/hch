#include "node.h"

Node::Node()
{

}


//ACCESSORS
QString Node::GetName()
{
    return m_name;
}

int Node::GetGroup()
{
    return m_group;
}

double Node::GetPolarStart()
{
    return m_polarStart;
}

double Node::GetPolarSpan()
{
    return m_polarSpan;
}

double Node::GetPolarEnd()
{
    return m_polarEnd;
}

QPointF Node::GetCartCentre()
{
    return m_cartCentre;
}

QPointF Node:: GetCartStart()
{
    return m_cartStart;
}

QPointF Node::GetCartEnd()
{
    return m_cartEnd;
}

QRectF Node::GetRectContainer()
{
    return m_rectContainer;
}

bool Node::GetHighlighted()
{
    return m_highlighted;
}

void Node::SetName(QString n)
{
    m_name = n;
}

void Node::SetGroup(int g)
{
  m_group = g;
}

void Node::SetPolarStart(double start)
{
    m_polarStart = start;
}

void Node::SetPolarSpan(double span)
{
    m_polarSpan = span;
}

void Node::SetPolarEnd(double end)
{
    m_polarEnd = end;
}

void Node::SetCartCentre(QPointF centre)
{
    m_cartCentre = centre;
}

void Node::SetCartStart(QPointF start)
{
    m_cartStart = start;
}

void Node::SetCartEnd(QPointF end)
{
    m_cartEnd = end;
}

void Node::SetRectContainer(QRectF rc)
{
    m_rectContainer = rc;
}

void Node::SetHighlighted(bool h)
{
    m_highlighted = h;
}
