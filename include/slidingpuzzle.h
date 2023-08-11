#pragma once

/** 
 * Class which provides basic operations of the game.  
*/

class SlidingPuzzle
{
public:
  /**
   * A constructor.
   * @param size a number of puzzles in the row, greater than 3. If it is less
   * exception is raised.
  */
  SlidingPuzzle(unsigned size);

  /**
   * A destructor.
  */
  ~SlidingPuzzle();

 /**
  * Check if it is possible to move a puzzle of an given index.
  * @param index an index of the puzzle in an array.
  * @return true if it is possible to move a puzzle, false it is not possible
  * to move a puzzle.
 */
  bool isElementMoveable(unsigned index);

  /**
   * Check if it is possible to move a puzzle of a given coordinates.
  * @param x a column number of an array.
  * @param y a row number of an array.
  * @return true if it is possible to move a puzzle, false it is not possible
  * to move a puzzle.
  */
  bool isElementMoveable(unsigned x, unsigned y);

  /**
   * Move a puzzle of an given index to an empty spot if it is possible.
   * @param index an index of the puzzle in an array.
   * @return true if a puzzle was moved, false if it is not possible to move a
   * puzzle.
  */
  bool moveElement(unsigned index);

    /**
   * Move a puzzle of an given index to an empty spot if it is possible.
   * @param x a column number of an array.
   * @param y a row number of an array.
   * @return true if a puzzle was moved, false if it is not possible to move a
   * puzzle.
  */
  bool moveElement(unsigned x, unsigned y);

  /**
   * 
  */
  bool moveUp();
  bool moveDown();
  bool moveLeft();
  bool moveRight();

  // State-interface
  bool isFinished();

protected:
  bool setEqual(unsigned index_1, unsigned index_2);

  unsigned mArraySize;
  unsigned mPuzzleSize;

  unsigned *mGoalArr;
  unsigned *mPuzzleArr;

private:
  bool isSolvable();
  unsigned array2id(unsigned x, unsigned y);
};