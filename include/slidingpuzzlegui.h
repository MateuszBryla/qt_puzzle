#pragma once

#include "slidingpuzzleimageif.h"

#include <string>

#include <QActionGroup>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
  class SlidingPuzzleGUI;
}
QT_END_NAMESPACE

class SlidingPuzzleGUI : public QMainWindow
{
  Q_OBJECT

public:
  SlidingPuzzleGUI(QWidget *parent = nullptr);
  ~SlidingPuzzleGUI();

private slots:
  void on_actionSelectImage_triggered();
  void on_actionRestart_triggered();
  void on_actionExit_triggered();
  void on_actionAbout_triggered();
  void on_actionLicenses_triggered();

  void setDifficulty(QAction *action);
  void handleLabelClicked(const QPoint &pos);

private:
  Ui::SlidingPuzzleGUI *ui;
  SlidingPuzzleImageIF *mPuzzle;
  QActionGroup *mDifficultyGroup;

  std::string mFilePath = "../assets/example_image.jpg";
  unsigned mPuzzleSize = 3;

  void setupActionGroups();
  void resetGame();
  void refreshImage();
};
