#pragma once

#include "slidingpuzzle.h"

class SlidingPuzzleTextIF : public SlidingPuzzle
{
  using SlidingPuzzle::SlidingPuzzle;

public:
  void printGoal();
  void printPuzzle();
};