#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QPoint>
#include <QRect>



class Node
{
public:
    Node();
    QString GetName();
    int GetGroup();
    double GetPolarStart();
    double GetPolarSpan();
    double GetPolarEnd();
    QPointF GetCartCentre();
    QPointF GetCartStart();
    QPointF GetCartEnd();
    QRectF GetRectContainer();
    bool GetHighlighted();
    void SetName(QString n);
    void SetGroup(int g);
    void SetPolarStart(double start);
    void SetPolarSpan(double span);
    void SetPolarEnd(double end);
    void SetCartCentre(QPointF centre);
    void SetCartStart(QPointF start);
    void SetCartEnd(QPointF end);
    void SetRectContainer(QRectF rc);
    void SetHighlighted(bool h);

private:
    QString m_name;
    int m_group;
    double m_polarStart;
    double m_polarSpan;
    double m_polarEnd;
    QPointF m_cartCentre;
    QPointF m_cartStart;
    QPointF m_cartEnd;
    QRectF m_rectContainer;
    bool m_highlighted;
};

#endif // NODE_H
