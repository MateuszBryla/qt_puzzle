#pragma once

#include "slidingpuzzle.h"

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

/**
 * Class which æ inherits from SlidingPuzzle class, which provides operation on
 * images.
*/

class SlidingPuzzleImageIF : public SlidingPuzzle
{
public:

  /**
   * Defines methods that are possible to make non-square images square.
  */
  enum imageMode
  {
    CROP,
    FIT
  };

  /**
   * Constructor.
   * @param image puzzle image.
   * @param size size of a puzzle.
  */
  SlidingPuzzleImageIF(cv::Mat image, unsigned size);

  /**
   * Constructor.
   * @param image puzzle image.
   * @param size size of a puzzle.
   * @param mode fit or crop.
  */
  SlidingPuzzleImageIF(cv::Mat image, unsigned size,
                       SlidingPuzzleImageIF::imageMode mode);
  /**
   * Constructor.
   * @param image_path puzzle image path.
   * @param size size of a puzzle.
  */
  SlidingPuzzleImageIF(std::string image_path, unsigned size);

  /**
   * Constructor.
   * @param image_path puzzle image path.
   * @param size size of a puzzle.
   * @param mode fit or crop.
  */
  SlidingPuzzleImageIF(std::string image_path, unsigned size,
                       SlidingPuzzleImageIF::imageMode mode);

  /**
   * Returns current state of a puzzle as an OpenCV image.
   * @return copy of the image.
  */
  cv::Mat getImage();

private:
  /**
   * Splits an image into puzzles.
   * 
  */
  void splitIntoPuzzles();

  /**
   * Stiches puzzles into image.
  */
  void stitchPuzzles();

  /**
   * Input image.
  */
  cv::Mat mImage;
  
  /**
   * Path ot the input image.
  */
  std::string mImagePath;

  /**
   * Vector with pieces of an image.
  */
  std::vector<cv::Mat> mPuzzles;

  /**
   * Stiched image.
  */
  cv::Mat mStitchedPuzzles;
};