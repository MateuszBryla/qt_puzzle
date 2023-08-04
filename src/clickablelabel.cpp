#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent) {}

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent) {}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
  {
    // Emit the clicked signal with the position of the click
    emit clicked(event->pos());
  }

  // Let the base class handle other aspects of the mouse press event
  QLabel::mousePressEvent(event);
}