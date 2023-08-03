#include "slidingpuzzlegui.h"
#include "ui_slidingpuzzlegui.h"

SlidingPuzzleGUI::SlidingPuzzleGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SlidingPuzzleGUI)
{
    ui->setupUi(this);

}

SlidingPuzzleGUI::~SlidingPuzzleGUI()
{
    delete ui;
}

