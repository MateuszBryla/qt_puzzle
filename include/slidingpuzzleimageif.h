#pragma once

#include "slidingpuzzle.h"

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

class SlidingPuzzleImageIF : public SlidingPuzzle
{
public:
  enum imageMode
  {
    CROP,
    FIT
  };

  SlidingPuzzleImageIF(cv::Mat image, unsigned size);
  SlidingPuzzleImageIF(cv::Mat image, unsigned size,
                       SlidingPuzzleImageIF::imageMode mode);
  SlidingPuzzleImageIF(std::string image_path, unsigned size);
  SlidingPuzzleImageIF(std::string image_path, unsigned size,
                       SlidingPuzzleImageIF::imageMode mode);

  cv::Mat getImage();

private:
  void splitIntoPuzzles();
  void stitchPuzzles();

  cv::Mat mImage;
  std::string mImagePath;
  std::vector<cv::Mat> mPuzzles;
  cv::Mat mStitchedPuzzles;
};