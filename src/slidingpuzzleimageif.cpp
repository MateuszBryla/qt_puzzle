#include "slidingpuzzleimageif.h"

#include <opencv2/opencv.hpp>

void cropToSquare(cv::Mat &image)
{
    // Crops the image to square - in place

    int width = image.cols;
    int height = image.rows;

    int dimension = cv::min(width, height);

    int xOffset = (width - dimension) / 2;
    int yOffset = (height - dimension) / 2;

    cv::Rect roi(xOffset, yOffset, dimension, dimension);
    image = image(roi).clone();
}

void fitToSquare(cv::Mat &image)
{
    // Fits the image to square - in place
    int dimension = cv::min(image.cols, image.rows);
    cv::resize(image, image, cv::Size(dimension, dimension));
}

SlidingPuzzleImageIF::SlidingPuzzleImageIF(std::string image_path, unsigned size) : SlidingPuzzleImageIF(image_path, size, SlidingPuzzleImageIF::CROP) {}

SlidingPuzzleImageIF::SlidingPuzzleImageIF(std::string image_path, unsigned size, SlidingPuzzleImageIF::imageMode mode) : SlidingPuzzle(size)
{
    mImage = cv::imread(image_path);

    switch (mode)
    {
    case SlidingPuzzleImageIF::CROP:
        cropToSquare(mImage);
        break;
    case SlidingPuzzleImageIF::FIT:
        fitToSquare(mImage);
        break;
    }

    splitIntoPuzzles();
}

cv::Mat SlidingPuzzleImageIF::getImage()
{
    stitchPuzzles();
    return mStitchedPuzzles.clone();
}

void SlidingPuzzleImageIF::splitIntoPuzzles()
{

    int elementWidth = mImage.cols / mPuzzleSize;
    int elementHeight = mImage.rows / mPuzzleSize;

    // Create "blank puzzle"
    cv::Mat element = cv::Mat::zeros(cv::Size(elementWidth, elementHeight), CV_8UC3);
    mPuzzles.push_back(element.clone());

    for (int i = 0; i < mPuzzleSize; i++)
    {
        for (int j = 0; j < mPuzzleSize; j++)
        {
            cv::Rect roi(j * elementWidth, i * elementHeight, elementWidth, elementHeight);
            element = mImage(roi).clone();
            mPuzzles.push_back(element);
        }
    }

}

void SlidingPuzzleImageIF::stitchPuzzles()
{
    std::vector<cv::Mat> rows;

    for (int i = 0; i < mArraySize; i = i + mPuzzleSize)
    {
        cv::Mat row;
        std::vector<cv::Mat> line;

        for (int j = i; j < i + mPuzzleSize; j++)
        {
            line.push_back(mPuzzles[mPuzzleArr[j]]);
        }

        cv::hconcat(line, row);
        rows.push_back(row);
    }

    cv::vconcat(rows, mStitchedPuzzles);
}