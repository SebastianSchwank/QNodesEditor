#include "qnodeview.h"

QNodeView::QNodeView(QWidget* parent) : QGraphicsView(parent)
{

}

void QNodeView::handleDndMessage(const qDnDMessage &message){

    //Update the Pointer to the Data Model once ToCheck: "What if all Objects are deletet will it
    // cause a "shitPointer" when then creating new Objects ?
    if(dataModel == nullptr) dataModel = message.dataModel;
}


void QNodeView::mouseMoveEvent(QMouseEvent *event){
    //Draw all current Connections again
    if(event->button() == Qt::MouseButton::RightButton){

    }
}

void QNodeView::wheelEvent(QWheelEvent* event) {

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // Scale the view / do the zoom
    double scaleFactor = 1.15;
    if(event->delta() > 0) {
        // Zoom in
        scale(scaleFactor, scaleFactor);
    } else {
        // Zooming out
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }

    // Don't call superclass handler here
    // as wheel is normally used for moving scrollbars
}
