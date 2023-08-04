#pragma once

#include <QLabel>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
  Q_OBJECT

signals:
  void clicked(const QPoint &pos);

public:
  ClickableLabel(QWidget *parent = nullptr);
  ClickableLabel(const QString &text, QWidget *parent = nullptr);

protected:
  void mousePressEvent(QMouseEvent *event) override;
};