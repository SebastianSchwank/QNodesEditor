#ifndef QXMLWRITER_H
#define QXMLWRITER_H

#include "qnodewidget.h"

#include <QVector>
#include <QXmlStreamWriter>
#include <QString>

class QXMLwriter
{
public:
    QXMLwriter();

    static QString writeToXML(QMap<int, QNodeWidget *> dataModel);
};

#endif // QXMLWRITER_H
