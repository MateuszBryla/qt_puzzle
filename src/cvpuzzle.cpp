#include "slidingpuzzleimageif.h"

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{

  // It is assummed that the program is started from build directory
  std::string path = "../assets/example_image.jpg";
  try
  {
    auto puzzle = SlidingPuzzleImageIF(path, 3);
    std::cout << "Image by wirestock on Freepik" << std::endl;

    cv::Mat image = puzzle.getImage();

    cv::namedWindow("Sliding puzzle", cv::WINDOW_NORMAL);

    while (!puzzle.isFinished())
    {
      cv::imshow("Sliding puzzle", puzzle.getImage());
      switch (cv::waitKey())
      {
      case 81:
        puzzle.moveLeft();
        break;
      case 82:
        puzzle.moveUp();
        break;
      case 83:
        puzzle.moveRight();
        break;
      case 84:
        puzzle.moveDown();
        break;
      case 27:
        cv::destroyAllWindows();
        exit(0);
        break;
      }
    }

    cv::destroyAllWindows();
    std::cout << "Congrats! You won\n";
  }
  catch (cv::Exception)
  {
    std::cout
        << "No image found - this program must be started from build directory"
        << std::endl;
  }

  return 0;
}