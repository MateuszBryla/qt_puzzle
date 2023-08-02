#ifndef SLIDINGPUZZLEIMAGEIF_H
#define SLIDINGPUZZLEIMAGEIF_H

#include "slidingpuzzle.h"

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

class SlidingPuzzleImageIF : public SlidingPuzzle
{
public:
    enum imageMode
    {
        CROP,
        FIT
    };

    SlidingPuzzleImageIF(std::string image_path, unsigned size);
    SlidingPuzzleImageIF(std::string image_path, unsigned size, SlidingPuzzleImageIF::imageMode mode);

    cv::Mat getImage();

private:
    void splitIntoPuzzles();
    void stitchPuzzles();

    cv::Mat mImage;
    std::string mImagePath;
    std::vector<cv::Mat> mPuzzles;
    cv::Mat mStitchedPuzzles;
};

#endif // SLIDINGPUZZLEIMAGEIF_H