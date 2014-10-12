#include "qxmlwriter.h"

QString QXMLwriter::writeToXML(QMap<int,QNodeWidget*> dataModel){
    QString XMLStream;

    QXmlStreamWriter stream(&XMLStream);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();

    QMap<int,QNodeWidget*>::iterator itNodes;
    for(itNodes = dataModel.begin(); itNodes != dataModel.end(); ++itNodes){
        stream.writeStartElement("QNode");
        stream.writeAttribute("ID", QString::number(itNodes.value()->mID));

            stream.writeStartElement("QNode Attributes");
            stream.writeTextElement("Name", itNodes.value()->mName);

                stream.writeStartElement("QNode Pos");
                stream.writeTextElement("PosX", QString::number(itNodes.value()->offset.x()));
                stream.writeTextElement("PosY", QString::number(itNodes.value()->offset.y()));
                stream.writeEndElement(); // QNode Pos

                stream.writeStartElement("QNode Size");
                stream.writeTextElement("Width", QString::number(itNodes.value()->size().width()));
                stream.writeTextElement("Height", QString::number(itNodes.value()->size().height()));
                stream.writeEndElement(); // QNode Size

            stream.writeEndElement(); // QNode Attributes

            QVector<qconnectorblob*> QNodesConnections = itNodes.value()->getConnectors();
            for(int i = 0; i < QNodesConnections.size(); i++){

                stream.writeStartElement("QConnection");
                stream.writeAttribute("ID", QString::number(QNodesConnections[i]->getmID()));

                if(QNodesConnections[i]->mtype)
                stream.writeAttribute("Type", "Out");
                else stream.writeAttribute("Type", "In");

                stream.writeTextElement("ID-Connection-Tuple", QNodesConnections[i]->getIDTuple());

                stream.writeEndElement(); // QConnection
            }

        stream.writeEndElement(); // QNode
    }

    stream.writeEndDocument();


    return XMLStream;
}

QXMLwriter::QXMLwriter()
{
}
