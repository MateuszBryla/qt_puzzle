#ifndef SLIDINGPUZZLE_H
#define SLIDINGPUZZLE_H

class SlidingPuzzle
{
public:
    SlidingPuzzle(unsigned size);
    ~SlidingPuzzle();

    // Element-based interface
    bool isElementMoveable(unsigned index);
    bool isElementMoveable(unsigned x, unsigned y);
    bool moveElement(unsigned index);
    bool moveElement(unsigned x, unsigned y);

    // Direction-based interface
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();

    // State-interface
    bool isFinished();

protected:
    unsigned mArraySize;
    unsigned mPuzzleSize;

    unsigned *mGoalArr;
    unsigned *mPuzzleArr;

private:
    bool isSolvable();
    unsigned array2id(unsigned x, unsigned y);
};

#endif // SLIDINGPUZZLE_H