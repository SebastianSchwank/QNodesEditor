#include "qxmlwriter.h"

QString QXMLwriter::writeToXML(QVector<QNodeWidget>* dataModel){
    QString XMLStream;

    QXmlStreamWriter stream(&XMLStream);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();

    stream.writeStartElement("bookmark");
    stream.writeAttribute("href", "http://qt.nokia.com/");
    stream.writeTextElement("title", "Qt Home");
    stream.writeEndElement(); // bookmark

    stream.writeEndDocument();


    return XMLStream;
}

QXMLwriter::QXMLwriter()
{
}
