#include "slidingpuzzle.h"

#include <ctime>
#include <algorithm>
#include <stdexcept>

template <typename T>
unsigned findZeroIndex(T *array, unsigned length)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == 0)
            return i;
    }

    return length;
}

SlidingPuzzle::SlidingPuzzle(unsigned size)
{
    // Puzzle doesn't make much sense when smaller than 3x3
    if (size < 3)
    {
        throw std::invalid_argument("Minimal supported size of the puzzle is 3x3");
    }

    mPuzzleSize = size;
    mArraySize = size * size;

    // Initialize reference and puzzle array
    mGoalArr = new unsigned[mArraySize];
    mPuzzleArr = new unsigned[mArraySize];

    for (int i = 0; i < mArraySize; i++)
    {
        mGoalArr[i] = i + 1;
        mPuzzleArr[i] = i + 1;
    }
    mGoalArr[mArraySize - 1] = 0;
    mPuzzleArr[mArraySize - 1] = 0;

    // Shuffle the puzzle
    std::srand(std::time(0));

    do
    {
        std::random_shuffle(mPuzzleArr, mPuzzleArr + mArraySize);
    } while (!isSolvable());
};

SlidingPuzzle::~SlidingPuzzle()
{
    delete[] mGoalArr;
    delete[] mPuzzleArr;
}

bool SlidingPuzzle::isElementMoveable(unsigned index)
{
    unsigned x = index % mPuzzleSize;
    unsigned y = index / mPuzzleSize;

    return isElementMoveable(x, y);
}

bool SlidingPuzzle::isElementMoveable(unsigned x, unsigned y)
{
    // You cannot move the element which is outside of the puzzle
    if (x >= mPuzzleSize || y >= mPuzzleSize)
    {
        return false;
    }

    // You cannot move the empty spot
    if (mPuzzleArr[array2id(x, y)] == 0)
        return false;

    // Check left neighbour
    if (x > 0)
    {
        if (mPuzzleArr[array2id(x - 1, y)] == 0)
            return true;
    }

    // Check right neighbour
    if (x < (mPuzzleSize - 1))
    {
        if (mPuzzleArr[array2id(x + 1, y)] == 0)
            return true;
    }

    // Check upper neighbour
    if (y > 0)
    {
        if (mPuzzleArr[array2id(x, y - 1)] == 0)
            return true;
    }

    // Check lower neighbour
    if (y < (mPuzzleSize - 1))
    {
        if (mPuzzleArr[array2id(x, y + 1)] == 0)
            return true;
    }

    return false;
}

bool SlidingPuzzle::moveElement(unsigned index)
{
    unsigned x = index % mPuzzleSize;
    unsigned y = index / mPuzzleSize;

    return moveElement(x, y);
}

bool SlidingPuzzle::moveElement(unsigned x, unsigned y)
{
    // Check if element is moveable at all
    if (!isElementMoveable(x, y))
        return false;

    // Find the direction of the movement and do it
    // Check left neighbour
    if (x > 0)
    {
        if (mPuzzleArr[array2id(x - 1, y)] == 0)
            return moveLeft();
    }

    // Check right neighbour
    if (x < (mPuzzleSize - 1))
    {
        if (mPuzzleArr[array2id(x + 1, y)] == 0)
            return moveRight();
    }

    // Check upper neighbour
    if (y > 0)
    {
        if (mPuzzleArr[array2id(x, y - 1)] == 0)
            return moveUp();
    }

    // Check lower neighbour
    if (y < (mPuzzleSize - 1))
    {
        if (mPuzzleArr[array2id(x, y + 1)] == 0)
            return moveDown();
    }

    return false;
}

bool SlidingPuzzle::moveUp()
{
    unsigned index = findZeroIndex(mPuzzleArr, mArraySize);
    unsigned x = index % mPuzzleSize;
    unsigned y = index / mPuzzleSize;

    if (isElementMoveable(x, y + 1))
    {
        mPuzzleArr[array2id(x, y)] = mPuzzleArr[array2id(x, y + 1)];
        mPuzzleArr[array2id(x, y + 1)] = 0;
        return true;
    }

    return false;
}

bool SlidingPuzzle::moveDown()
{
    unsigned index = findZeroIndex(mPuzzleArr, mArraySize);
    unsigned x = index % mPuzzleSize;
    unsigned y = index / mPuzzleSize;

    if (isElementMoveable(x, y - 1))
    {
        mPuzzleArr[array2id(x, y)] = mPuzzleArr[array2id(x, y - 1)];
        mPuzzleArr[array2id(x, y - 1)] = 0;
        return true;
    }

    return false;
}

bool SlidingPuzzle::moveLeft()
{
    unsigned index = findZeroIndex(mPuzzleArr, mArraySize);
    unsigned x = index % mPuzzleSize;
    unsigned y = index / mPuzzleSize;

    if (isElementMoveable(x + 1, y))
    {
        mPuzzleArr[array2id(x, y)] = mPuzzleArr[array2id(x + 1, y)];
        mPuzzleArr[array2id(x + 1, y)] = 0;
        return true;
    }

    return false;
}

bool SlidingPuzzle::moveRight()
{
    unsigned index = findZeroIndex(mPuzzleArr, mArraySize);
    unsigned x = index % mPuzzleSize;
    unsigned y = index / mPuzzleSize;

    if (isElementMoveable(x - 1, y))
    {
        mPuzzleArr[array2id(x, y)] = mPuzzleArr[array2id(x - 1, y)];
        mPuzzleArr[array2id(x - 1, y)] = 0;
        return true;
    }

    return false;
}

bool SlidingPuzzle::isFinished()
{
    // Check if the game is won - state of the puzzle is the same as goal

    for (int i = 0; i < mArraySize; i++)
    {
        if (mGoalArr[i] != mPuzzleArr[i])
            return false;
    }

    return true;
}

bool SlidingPuzzle::isSolvable()
{
    // First step - counts inversions:
    // Inversion: when a higher-numbered tile precedes a lower-numbered tile in the puzzle

    unsigned inversions = 0;
    for (int i = 0; i < mArraySize; i++)
    {
        for (int j = i + 1; j < mArraySize; j++)
        {
            if (mPuzzleArr[i] && mPuzzleArr[j] && mPuzzleArr[j] > mPuzzleArr[i])
            {
                inversions++;
                break;
            }
        }
    }

    // For odd-sized puzzles (e.g., 3x3), the puzzle is solvable if the number of inversions is even.
    if (mPuzzleSize % 2)
    {
        if (inversions % 2)
            return false;
        return true;
    }

    // For even-sized puzzles (e.g., 4x4), the puzzle is solvable if:
    // 1. The number of inversions is even, and the row of the blank tile (starting from the bottom) is even.
    unsigned index = findZeroIndex(mPuzzleArr, mArraySize);
    unsigned row = mPuzzleSize - (index / mPuzzleSize) - 1;

    if (inversions % 2)
    {
        if (row % 2)
            return true;
        return false;
    }
    // 2. The number of inversions is odd, and the row of the blank tile (starting from the bottom) is odd.
    else
    {
        if (row % 2)
            return false;
        return true;
    }
}

unsigned SlidingPuzzle::array2id(unsigned x, unsigned y)
{
    return x + y * mPuzzleSize;
}