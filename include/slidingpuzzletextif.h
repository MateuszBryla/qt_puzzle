#pragma once

#include "slidingpuzzle.h"

/**
 * Class which æ inherits from SlidingPuzzle class, which provides interface for
 * terminal version.
*/
class SlidingPuzzleTextIF : public SlidingPuzzle
{
  using SlidingPuzzle::SlidingPuzzle;

public:

  /**
   * Prints final puzzle.
  */
  void printGoal();

  /**
   * Prints current state of the puzzles.
  */
  void printPuzzle();
};