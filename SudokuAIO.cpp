#include "sudokuAIO.h"

int main()
{
	// The array that will be used as the sudoku grid
	int grid[3][3][3][3];

	// Fill Box is used to produce a valid and solved grid
	fillBox(grid);

	// Create Box is used to remove numbers from the solved
	// grid to create a puzzle that has one unique solution
	createBox(grid);

	// Print Box is used to print the array/grid separated
	// in 3x3 boxes, from left to right, from up to down
	std::cout << "This is a puzzle with a unique solution: \n";
	printBox(grid);
	std::cout << std::endl << std::endl << std::endl << std::endl;

	// Solve Box is used to solve a puzzle that is valid and
	// if the puzzle is invalid it prints out: "Puzzle is invalid. Cannot be solved!"
	solveBox(grid);
	std::cout << "This is the same puzzle, but solved: \n";
	printBox(grid);
	std::cout << std::endl << std::endl;

	// State Box is used to return true/false value depending
	// if the grid is valid or not (true - valid, false - invalid)
	std::cout << "The grid is: " << stateBox(grid) << std::endl << std::endl;

	// Check Box is used to return true/flase value for each row, column & box
	// depending if the grid is valid or not (true - valid, false - invalid)
	checkBox(grid);
}