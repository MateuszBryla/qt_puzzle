#include <iostream>
#include <iomanip>

#include "slidingpuzzletextif.h"

template <typename T>
void printArray(T *array, unsigned dim)
{
    // Check the number of digits of a biggest number - for formatting purposes
    unsigned numDigits = 1;
    unsigned lastElementID = dim * dim;

    while (lastElementID /= 10)
    {
        numDigits++;
    }
    
    // Print out the given array as a dim x dim representation
    for (int i = 0; i < dim; ++i)
    {
        std::cout << "[ ";
        for (int j = 0; j < dim; ++j)
        {
            std::cout << std::setw(numDigits) << array[i * dim + j];
            if (j < dim - 1)
            {
                std::cout << " ";
            }
        }
        std::cout << " ]" << std::endl;
    }
}

void SlidingPuzzleTextIF::printGoal()
{
    printArray(mGoalArr, mPuzzleSize);
}

void SlidingPuzzleTextIF::printPuzzle()
{
    printArray(mPuzzleArr, mPuzzleSize);
}