#include <iostream>
#include <string>

#include "slidingpuzzletextif.h"

static int getSize(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cout << "[ERROR] Puzzle size wasn't specified, pass it as a single "
                 "number, as a first argument\n";
    exit(0);
  }

  int size = atoi(argv[1]);
  if (size < 3)
  {
    std::cout << "[ERROR] Puzzle size can't be smaller than 3\n";
    exit(0);
  }

  return size;
}

static void clearTerminal()
{
  // Clear the terminal on Linux
  std::cout << "\033[2J\033[1;1H";
}

int main(int argc, char *argv[])
{
  int size = getSize(argc, argv);
  auto puzzle = SlidingPuzzleTextIF(size);

  std::string input;
  while (not puzzle.isFinished())
  {
    clearTerminal();
    std::cout << "Press W/S/A/D & Enter to move Up/Down/Left/Right, press Q "
                 "and Enter to Exit"
              << std::endl;
    puzzle.printPuzzle();
    std::cin >> input;
    std::cout << input;

    if (input == "w" || input == "W")
    {
      puzzle.moveUp();
    }
    else if (input == "s" || input == "S")
    {
      puzzle.moveDown();
    }
    else if (input == "a" || input == "A")
    {
      puzzle.moveLeft();
    }
    else if (input == "d" || input == "D")
    {
      puzzle.moveRight();
    }
    else if (input == "q" || input == "Q")
    {
      exit(0);
    }
  }

  clearTerminal();
  std::cout << "Congratulations! You won!" << std::endl;

  return 0;
}