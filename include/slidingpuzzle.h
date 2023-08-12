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
  * Checks if it is possible to move a puzzle of an given index.
  * @param index an index of the puzzle in an array.
  * @return true if it is possible to move a puzzle, false it is not possible
  * to move a puzzle.
 */
  bool isElementMoveable(unsigned index);

  /**
   * Checks if it is possible to move a puzzle of a given coordinates.
  * @param x a column number of an array.
  * @param y a row number of an array.
  * @return true if it is possible to move a puzzle, false it is not possible
  * to move a puzzle.
  */
  bool isElementMoveable(unsigned x, unsigned y);

  /**
   * Moves a puzzle of an given index to an empty spot if it is possible.
   * @param index an index of the puzzle in an array.
   * @return true if a puzzle was moved, false if it is not possible to move a
   * puzzle.
  */
  bool moveElement(unsigned index);

    /**
   * Moves a puzzle of an given index to an empty spot if it is possible.
   * @param x a column number of an array.
   * @param y a row number of an array.
   * @return true if a puzzle was moved, false if it is not possible to move a
   * puzzle.
  */
  bool moveElement(unsigned x, unsigned y);

  /**
   * Moves a puzzle to an upper row if it is possible.
   * @return true if puzzle was moved, false if is not possible.
  */
  bool moveUp();

  /**
   * Moves a puzzle to a lower row if it is possible.
   * @return true if puzzle was moved, false if is not possible.
  */
  bool moveDown();

  /**
   * Moves a puzzle to the left if it is possible.
   * @return true if puzzle was moved, false if is not possible.
  */
  bool moveLeft();

  /**
   * Moves a puzzle to the right if it is possible.
   * @return true if puzzle was moved, false if is not possible.
  */
  bool moveRight();

  /**
   * Checks if the game is won.
   * @return true if the game is won, false if the game is not won yet.
  */
  bool isFinished();

protected:
  /**
   * Set two puzzles as equal if are the same.
   * @param index_1 index of first puzzle.
   * @param index_2 index of second puzzle.
   * @return true if puzzles are set equal, false if it was not possible to set
   * them equal.
  */
  bool setEqual(unsigned index_1, unsigned index_2);

  /**
   * Size of an array with puzzles.
  */
  unsigned mArraySize;

  /**
   * A number of puzzles in the row.
  */
  unsigned mPuzzleSize;

  /**
   * Array with puzzles on they target position.
  */
  unsigned *mGoalArr;

  /**
   * Array with the current state of puzzles.
  */
  unsigned *mPuzzleArr;

private:
  /**
   * Checks if puzzle is solvable.
   * @return true if puzzle is solvable, false if puzzle is not solvable.
  */
  bool isSolvable();

  /**
   * Changes coordinates of a puzzle to an array index.
   * @param x a column number of an array.
   * @param y a row number of an array.
   * @return a puzzle index in an array 
  */
  unsigned array2id(unsigned x, unsigned y);
};