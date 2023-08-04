#include "slidingpuzzlegui.h"

#include <QApplication>
#include <QSizePolicy>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  SlidingPuzzleGUI w;
  w.show();
  return app.exec();
}
