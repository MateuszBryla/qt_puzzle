#include "slidingpuzzleimageif.h"

#include <string>
#include <iostream>

int main(int argc, char *argv[])
{

    std::string path = "/home/mbryla/test_image.jpg";
    auto puzzle = SlidingPuzzleImageIF(path, 4);

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