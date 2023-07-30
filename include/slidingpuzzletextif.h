#ifndef SLIDINGPUZZLETEXTIF_H
#define SLIDINGPUZZLECTEXTIF_H

#include "slidingpuzzle.h"

class SlidingPuzzleTextIF : public SlidingPuzzle {
    using SlidingPuzzle::SlidingPuzzle;

    public:
        void printGoal();
        void printPuzzle();
};


#endif // SLIDINGPUZZLETEXTIF_H