#include "slidingpuzzlegui.h"
#include "ui_slidingpuzzlegui.h"

#include "clickablelabel.h"

#include <QFileDialog>
#include <QImage>
#include <QMessageBox>
#include <QPixmap>

#include <opencv2/opencv.hpp>

static QPixmap cvMat2QPixmap(cv::Mat cvImage) {
  cv::Mat rgb_image;
  cv::cvtColor(cvImage, rgb_image, cv::COLOR_BGR2RGB);
  return QPixmap::fromImage(QImage(rgb_image.data, rgb_image.cols,
                                   rgb_image.rows, rgb_image.step,
                                   QImage::Format_RGB888));
}

SlidingPuzzleGUI::SlidingPuzzleGUI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SlidingPuzzleGUI) {
  ui->setupUi(this);
  setFixedSize(800, 800);

  // Set-up the menu with the difficulty selection
  setupActionGroups();

  // Connect the clicked signal of ClickableLabel to your slot for handling
  // clicks
  connect(ui->image, &ClickableLabel::clicked, this,
          &SlidingPuzzleGUI::handleLabelClicked);

  // Load up initial parameters
  mPuzzle = new SlidingPuzzleImageIF(mFilePath, 3);
  refreshImage();
}

void SlidingPuzzleGUI::setupActionGroups() {
  mDifficultyGroup = new QActionGroup(this);

  mDifficultyGroup->setExclusive(true);
  mDifficultyGroup->addAction(ui->action3x3);
  mDifficultyGroup->addAction(ui->action4x4);
  mDifficultyGroup->addAction(ui->action5x5);
  mDifficultyGroup->addAction(ui->action6x6);
  mDifficultyGroup->addAction(ui->action7x7);
  mDifficultyGroup->addAction(ui->action8x8);
  mDifficultyGroup->addAction(ui->action9x9);

  connect(mDifficultyGroup, SIGNAL(triggered(QAction *)), this,
          SLOT(setDifficulty(QAction *)));
}

void SlidingPuzzleGUI::on_actionSelectImage_triggered() {
  QString filename = QFileDialog::getOpenFileName(
      this, tr("Open Image"), ".", tr("Image Files (*.png *.jpg)"));

  if (filename != "") {
    mFilePath = filename.toStdString();
    resetGame();
  }
}

void SlidingPuzzleGUI::on_actionRestart_triggered() { resetGame(); }

void SlidingPuzzleGUI::on_actionExit_triggered() {
  int confirmationOutput = QMessageBox::question(
      this, "Sliding puzzle", "Are you sure you want to quit?",
      QMessageBox::Yes | QMessageBox::No);

  if (confirmationOutput == QMessageBox::Yes) {
    qApp->quit();
  }
}

void SlidingPuzzleGUI::on_actionAbout_triggered() {
  int confirmationOutput = QMessageBox::information(
      this, "Sliding puzzle", "Sliding puzzle game\nMateusz Bryła, 2023",
      QMessageBox::Ok);
}

void SlidingPuzzleGUI::on_actionLicenses_triggered() {
  int confirmationOutput = QMessageBox::information(
      this, "Sliding puzzle", "Initial image by wirestock on Freepik",
      QMessageBox::Ok);
}

void SlidingPuzzleGUI::setDifficulty(QAction *action) {
  QString actionText = action->text();
  unsigned puzzle_size = actionText.mid(0, actionText.indexOf("x")).toUInt();

  if (puzzle_size != mPuzzleSize) {
    mPuzzleSize = puzzle_size;
    resetGame();
  }
}

void SlidingPuzzleGUI::handleLabelClicked(const QPoint &pos) {
  unsigned partSize = ui->image->width() / mPuzzleSize;
  unsigned y = pos.y() / partSize;
  unsigned x = pos.x() / partSize;

  if (mPuzzle->isFinished()) {
    return;
  }

  if (mPuzzle->moveElement(x, y)) {
    refreshImage();

    if (mPuzzle->isFinished()) {
      QMessageBox::information(this, "Sliding puzzle",
                               "Congratulations! You've won", QMessageBox::Ok);
    }
  }
}

void SlidingPuzzleGUI::resetGame() {
  delete mPuzzle;
  mPuzzle = new SlidingPuzzleImageIF(mFilePath, mPuzzleSize);
  refreshImage();
}

void SlidingPuzzleGUI::refreshImage() {
  auto pixmap = cvMat2QPixmap(mPuzzle->getImage());
  ui->image->setPixmap(pixmap.scaled(ui->image->width(), ui->image->height(),
                                     Qt::KeepAspectRatio));
}

SlidingPuzzleGUI::~SlidingPuzzleGUI() {
  delete ui;
  delete mDifficultyGroup;
  delete mPuzzle;
}
