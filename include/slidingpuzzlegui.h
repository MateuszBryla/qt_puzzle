#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SlidingPuzzleGUI; }
QT_END_NAMESPACE

class SlidingPuzzleGUI : public QMainWindow
{
    Q_OBJECT

public:
    SlidingPuzzleGUI(QWidget *parent = nullptr);
    ~SlidingPuzzleGUI();

private:
    Ui::SlidingPuzzleGUI *ui;
};
