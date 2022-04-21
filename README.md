# SudokuAIO
Sudoku All in One tool

File: sudokuAIO.h
 
Created By: Blerton Ismaili
Date: 11, April 2022
 
Description: This program uses an empty sudoku grid in the form of an 
			 array (arr[3][3][3][3]), to fill an empty sudoku grid,
			 to create a solvable sudoku puzzle & to check if the
			 solution is valid.
			
startUp() Runs srand function only once for random numbers

checkBox(arr[3][3][3][3]) Prints each rows, boxs & columns state (if there are repeating numbers from 1 - 9)

stateBox(arr[3][3][3][3]) Returns true/false depending if the numbers fill the grid without breaking sudoku rules, true - grid is valid & false - grid is invalid

printBox(arr[3][3][3][3]) Prints the entire array (grid) in the console

flushBox(arr[3][3][3][3]) Fills the entire array (grid) with 0

fillBox(arr[3][3][3][3]) Fills the entire array (grid) with numbers from 1 - 9, in each box, row & column

selectPair() Returns a random value from 1 - 41

uniquePair() Returns a random value from 1 - 41, each number only appears once

removePair(arr[3][3][3][3], pairIndex) pairIndex -> number of the pair to remove (from 1 - 41). Removes a symmetrical pair from the grid

pencilSolve(arr[3][3][3][3]) Places a number in the grid where there is only one possible number to place

isSolved(arr[3][3][3][3]) Returns true/false depending if the grid is solved or not, true - its solved & false - its either invalid or has 0 left (empty slots)

solveBox(arr[3][3][3][3]) Runs the pencil solve function until grid is solved if its solvable, if not prints out "Puzzle is invalid. Cannot be solved!"

isSolvable(arr[3][3][3][3]) Returns true/false depending on if the grid has one unique solution (also solves the grid)

duplicateArr(oArr[3][3][3][3], int dArr[3][3][3][3]) Stores all the values from oArr (original array) into dArr (duplicate array)

createBox(arr[3][3][3][3]) Takes a full box as input, creates a solvable puzzle with unique solution. Full box as in an array that is a valid sudoku grid & has no 0