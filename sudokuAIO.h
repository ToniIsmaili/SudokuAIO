/*
	File: sudokuAIO.h
 
	Created By: Blerton Ismaili
	Date: 11, April 2022
 
	Description: This program uses an empty sudoku grid in the form of an 
				 array (arr[3][3][3][3]), to fill an empty sudoku grid,
				 to create a solvable sudoku puzzle & to check if the
				 solution is valid.
 */

#include <iostream>

// Global Constant Variables
const int sizeArr = 3;
const int rowLen = 9;
const int colLen = 9;
const int clearMax = 20000;
const int solveTries = 100;
const int pairs = 41;
int pairsDup[pairs];
bool startApp = false;

// Runs srand function only once for random numbers
void startUp() {
	if (!startApp)
	{
		srand((unsigned)time(0));
	}
	startApp = true;
}

// Prints each rows, boxs & columns state (if there are repeating numbers from 1 - 9)
void checkBox(int arr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	int checkSpace[9], checkIndeks = 0, prevSpace = 0;
	bool spaceState = true;

	// Checks all the 3x3 boxes for repeating numbers
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			for (int k = 0; k < sizeArr; k++)
			{
				for (int l = 0; l < sizeArr; l++)
				{
					checkSpace[checkIndeks] = arr[i][j][k][l];
					checkIndeks++;
				}
			}

			checkIndeks = 0;

			for (int iLen = 0; iLen < rowLen; iLen++)
			{
				for (int jLen = iLen + 1; jLen < rowLen; jLen++)
				{
					if (checkSpace[iLen] != checkSpace[jLen])
					{
						spaceState = true;
					}
					else
					{
						spaceState = false;
						jLen = rowLen;
						iLen = rowLen;
					}
				}
			}
			std::cout << "Row: " << i << " Column: " << j << " -> " << spaceState << std::endl;
		}
	}

	std::cout << std::endl;

	// Checks all the rows for repeating numbers
	for (int i = 0; i < sizeArr; i++)
	{
		for (int k = 0; k < sizeArr; k++)
		{
			for (int j = 0; j < sizeArr; j++)
			{
				for (int l = 0; l < sizeArr; l++)
				{
					checkSpace[checkIndeks] = arr[i][j][k][l];
					checkIndeks++;
				}
			}

			checkIndeks = 0;

			for (int iLen = 0; iLen < rowLen; iLen++)
			{
				for (int jLen = iLen + 1; jLen < rowLen; jLen++)
				{
					if (checkSpace[iLen] != checkSpace[jLen])
					{
						spaceState = true;
					}
					else
					{
						spaceState = false;
						jLen = rowLen;
						iLen = rowLen;
					}
				}
			}
			std::cout << "Row: " << i << " " << k << " -> " << spaceState << std::endl;
		}
	}

	std::cout << std::endl;

	// Checks all the columns for repeating numbers
	for (int j = 0; j < sizeArr; j++)
	{
		for (int l = 0; l < sizeArr; l++)
		{
			for (int i = 0; i < sizeArr; i++)
			{
				for (int k = 0; k < sizeArr; k++)
				{
					checkSpace[checkIndeks] = arr[i][j][k][l];
					checkIndeks++;
				}
			}

			checkIndeks = 0;

			for (int iLen = 0; iLen < rowLen; iLen++)
			{
				for (int jLen = iLen + 1; jLen < rowLen; jLen++)
				{
					if (checkSpace[iLen] != checkSpace[jLen])
					{
						spaceState = true;
					}
					else
					{
						spaceState = false;
						jLen = rowLen;
						iLen = rowLen;
					}
				}
			}
			std::cout << "Column: " << j << " " << l << " -> " << spaceState << std::endl;
		}
	}

	std::cout << std::endl;
}

// Returns true/false depending if the numbers fill the grid without breaking sudoku rules, true - grid is valid & false - grid is invalid
bool stateBox(int arr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	int checkSpace[9], checkIndeks = 0, prevSpace = 0;
	bool boxState = true, rowState = true, columnState = true;

	// Checks all the 3x3 boxes for repeating numbers
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			// Saves all the numbers in an array
			for (int k = 0; k < sizeArr; k++)
			{
				for (int l = 0; l < sizeArr; l++)
				{
					checkSpace[checkIndeks] = arr[i][j][k][l];
					checkIndeks++;
				}
			}

			checkIndeks = 0;

			for (int iLen = 0; iLen < rowLen; iLen++)
			{
				for (int jLen = iLen + 1; jLen < rowLen; jLen++)
				{
					if (checkSpace[iLen] != checkSpace[jLen] || checkSpace[iLen] == 0)
					{
						boxState = true;
					}
					else
					{
						boxState = false;
						jLen = rowLen;
						iLen = rowLen;
						i = sizeArr;
						j = sizeArr;
					}
				}
			}
		}
	}

	// Checks all the rows for repeating numbers
	for (int i = 0; i < sizeArr; i++)
	{
		for (int k = 0; k < sizeArr; k++)
		{
			for (int j = 0; j < sizeArr; j++)
			{
				// Saves all the numbers in an array
				for (int l = 0; l < sizeArr; l++)
				{
					checkSpace[checkIndeks] = arr[i][j][k][l];
					checkIndeks++;
				}
			}

			checkIndeks = 0;

			for (int iLen = 0; iLen < rowLen; iLen++)
			{
				for (int jLen = iLen + 1; jLen < rowLen; jLen++)
				{
					if (checkSpace[iLen] != checkSpace[jLen] || checkSpace[iLen] == 0)
					{
						rowState = true;
					}
					else
					{
						rowState = false;
						jLen = rowLen;
						iLen = rowLen;
						i = sizeArr;
						k = sizeArr;
					}
				}
			}
		}
	}

	// Checks all the columns for repeating numbers
	for (int j = 0; j < sizeArr; j++)
	{
		for (int l = 0; l < sizeArr; l++)
		{
			for (int i = 0; i < sizeArr; i++)
			{
				// Saves all the numbers in an array
				for (int k = 0; k < sizeArr; k++)
				{
					checkSpace[checkIndeks] = arr[i][j][k][l];
					checkIndeks++;
				}
			}

			checkIndeks = 0;

			for (int iLen = 0; iLen < rowLen; iLen++)
			{
				for (int jLen = iLen + 1; jLen < rowLen; jLen++)
				{
					if (checkSpace[iLen] != checkSpace[jLen] || checkSpace[iLen] == 0)
					{
						columnState = true;
					}
					else
					{
						columnState = false;
						jLen = rowLen;
						iLen = rowLen;
						j = sizeArr;
						l = sizeArr;
					}
				}
			}
		}
	}

	// Prints the state of the grid (true - everything is allright, false - some numbers repeat)
	if (boxState == true && rowState == true && columnState == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Prints the entier array (grid) in the console
void printBox(int arr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					std::cout << arr[i][j][k][l] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
}

// Fills the entier array (grid) with 0
void flushBox(int arr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			for (int k = 0; k < sizeArr; k++)
			{
				for (int l = 0; l < sizeArr; l++)
				{
					arr[i][j][k][l] = 0;
				}
			}
		}
	}
}

// Fills the entier array (grid) with numbers from 1 - 9, in each box, row & column
void fillBox(int arr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	int xPos, yPos, clearCount = 0;
	bool numPlaced = false;

	startUp();

	std::cout << "Array flushed..." << std::endl;
	flushBox(arr);

	std::cout << "Filling the array..." << std::endl;

	for (int num = 1; num < 10; num++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				do
				{
					// Get the position
					xPos = rand() % sizeArr;
					yPos = rand() % sizeArr;

					if (arr[i][j][xPos][yPos] == 0)
					{
						arr[i][j][xPos][yPos] = num;
						numPlaced = true;
					}
					else
					{
						numPlaced = false;
					}

					if (clearCount < clearMax)
					{
						if (!stateBox(arr))
						{
							for (int i = 0; i < sizeArr; i++)
							{
								for (int j = 0; j < sizeArr; j++)
								{
									for (int k = 0; k < sizeArr; k++)
									{
										for (int l = 0; l < sizeArr; l++)
										{
											if (arr[i][j][k][l] == num)
											{
												arr[i][j][k][l] = 0;
											}
										}
									}
								}
							}
							numPlaced = false;
							clearCount++;
							i = 0;
							j = 0;
						}
					}
					else
					{
						flushBox(arr);
						clearCount = 0;
						num = 1;
					}
				} while (!numPlaced);
			}
		}
		clearCount = 0;
	}
}

// Returns a random value from 1 - 41
int selectPair() {

	startUp();

	int pairIndex = (rand() % 41) + 1;

	return pairIndex;
}

// Returns a random value from 1 - 41, each number only appears once
int uniquePair() {

	bool hasReturned = false;

	while (!hasReturned)
	{
		int uniquePair = selectPair(), dupIndex = 0;

		for (int i = 0; i < 41; i++)
		{
			if (uniquePair != pairsDup[i])
			{
				dupIndex++;
			}
		}

		if (dupIndex == 41)
		{
			for (int i = 0; i < 41; i++)
			{
				if (pairsDup[i] == 0)
				{
					pairsDup[i] = uniquePair;
					i = 41;
				}
			}
			return uniquePair;
			hasReturned = true;
		}
	}
}

// Removes a symmetrical pair from the grid
void removePair(int arr[sizeArr][sizeArr][sizeArr][sizeArr], int pairIndex) {

	switch (pairIndex)
	{
	case 1:
		arr[0][0][0][0] = 0, arr[2][2][2][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 2:
		arr[0][0][0][1] = 0, arr[2][2][2][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 3:
		arr[0][0][0][2] = 0, arr[2][2][2][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 4:
		arr[0][1][0][0] = 0, arr[2][1][2][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 5:
		arr[0][1][0][1] = 0, arr[2][1][2][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 6:
		arr[0][1][0][2] = 0, arr[2][1][2][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 7:
		arr[0][2][0][0] = 0, arr[2][0][2][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 8:
		arr[0][2][0][1] = 0, arr[2][0][2][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 9:
		arr[0][2][0][2] = 0, arr[2][0][2][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 10:
		arr[0][0][1][0] = 0, arr[2][2][1][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 11:
		arr[0][0][1][1] = 0, arr[2][2][1][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 12:
		arr[0][0][1][2] = 0, arr[2][2][1][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 13:
		arr[0][1][1][0] = 0, arr[2][1][1][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 14:
		arr[0][1][1][1] = 0, arr[2][1][1][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 15:
		arr[0][1][1][2] = 0, arr[2][1][1][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 16:
		arr[0][2][1][0] = 0, arr[2][0][1][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 17:
		arr[0][2][1][1] = 0, arr[2][0][1][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 18:
		arr[0][2][1][2] = 0, arr[2][0][1][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 19:
		arr[0][2][2][2] = 0, arr[2][0][0][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 20:
		arr[0][2][2][1] = 0, arr[2][0][0][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 21:
		arr[0][2][2][0] = 0, arr[2][0][0][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 22:
		arr[0][1][2][2] = 0, arr[2][1][0][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 23:
		arr[0][1][2][1] = 0, arr[2][1][0][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 24:
		arr[0][1][2][0] = 0, arr[2][1][0][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 25:
		arr[0][0][2][2] = 0, arr[2][2][0][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 26:
		arr[0][0][2][1] = 0, arr[2][2][0][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 27:
		arr[0][0][2][0] = 0, arr[2][2][0][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 28:
		arr[1][0][0][0] = 0, arr[1][2][2][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 29:
		arr[1][0][0][1] = 0, arr[1][2][2][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 30:
		arr[1][0][0][2] = 0, arr[1][2][2][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 31:
		arr[1][1][0][0] = 0, arr[1][1][2][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 32:
		arr[1][1][0][1] = 0, arr[1][1][2][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 33:
		arr[1][1][0][2] = 0, arr[1][1][2][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 34:
		arr[1][0][2][2] = 0, arr[1][2][0][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 35:
		arr[1][0][2][1] = 0, arr[1][2][0][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 36:
		arr[1][0][2][0] = 0, arr[1][2][0][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 37:
		arr[1][0][1][0] = 0, arr[1][2][1][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 38:
		arr[1][0][1][1] = 0, arr[1][2][1][1] = 0;
		//cout << pairIndex << "\n";
		break;
	case 39:
		arr[1][0][1][2] = 0, arr[1][2][1][0] = 0;
		//cout << pairIndex << "\n";
		break;
	case 40:
		arr[1][1][1][0] = 0, arr[1][1][1][2] = 0;
		//cout << pairIndex << "\n";
		break;
	case 41:
		arr[1][1][1][1] = 0;
		//cout << pairIndex << "\n";
		break;
	default:
		std::cout << "something is wrong bich";
		std::cout << pairIndex << "";
		break;
	}
}

// Places a number in the grid where there is only one possible number to place
void pencilSolve(int arr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	int marks[sizeArr][sizeArr][sizeArr][sizeArr][sizeArr * sizeArr] = { 0 }, marksAmount[sizeArr][sizeArr][sizeArr][sizeArr] = { 0 }, counter = 0;

	// fills marks array with all possible valid numbers
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			for (int k = 0; k < sizeArr; k++)
			{
				for (int l = 0; l < sizeArr; l++)
				{
					if (arr[i][j][k][l] == 0)
					{
						for (int num = 1; num <= 9; num++)
						{
							arr[i][j][k][l] = num;
							if (stateBox(arr))
							{
								marks[i][j][k][l][num - 1] = num;
							}
							else
							{
								marks[i][j][k][l][num - 1] = 0;
							}
							arr[i][j][k][l] = 0;
						}
					}
				}
			}
		}
	}

	// print out the markings 
	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					for (int num = 0; num < 9; num++)
					{
						cout << marks[i][j][k][l][num] << " ";
					}
					cout << endl;
				}
			}
			cout << endl;
		}
		cout << endl;
	}*/

	// amount of marks for each cell
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			for (int k = 0; k < sizeArr; k++)
			{
				for (int l = 0; l < sizeArr; l++)
				{
					for (int num = 0; num < 9; num++)
					{
						if (marks[i][j][k][l][num] != 0)
						{
							counter++;
						}
					}
					marksAmount[i][j][k][l] = counter;
					counter = 0;
				}
			}
		}
	}

	// print out the amount of marks per cell
	//printBox(marksAmount);

	// place the number if there is only one mark for that cell
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			for (int k = 0; k < sizeArr; k++)
			{
				for (int l = 0; l < sizeArr; l++)
				{
					if (marksAmount[i][j][k][l] == 1)
					{
						for (int num = 0; num < 9; num++)
						{
							if (marks[i][j][k][l][num] != 0)
							{
								arr[i][j][k][l] = marks[i][j][k][l][num];
							}
						}
					}
				}
			}
		}
	}
}

// Returns true/false depending if the grid is solved or not, true - its solved & false - its either invalid or has 0 left (empty slots)
bool isSolved(int arr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			for (int k = 0; k < sizeArr; k++)
			{
				for (int l = 0; l < sizeArr; l++)
				{
					if (arr[i][j][k][l] == 0)
					{
						return false;
					}
				}
			}
		}
	}

	if (stateBox(arr))
	{
		return true;
	}
	else
	{
		return false;
	}

};

// Runs the pencil solve function until grid is solved if its solvable, if not prints out "Puzzle is invalid. Cannot be solved!"
void solveBox(int arr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	for (int i = 0; i < solveTries; i++)
	{
		pencilSolve(arr);
	}

	if (!isSolved(arr))
	{
		std::cout << "Puzzle is invalid. Cannot be solved!\n";
	}

	// gets stuck if puzzle is impossible, considering putting a cap on how many tries it has
	//while (!isSolved(arr))
	//{
	//	pencilSolve(arr);
	//}
}

// Returns true/false depending on if the grid has one unique solution (also solves the grid)
bool isSolvable(int arr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	for (int i = 0; i < solveTries; i++)
	{
		pencilSolve(arr);
	}

	if (isSolved(arr))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Stores all the values from oArr (original array) into dArr (duplicate array)
void duplicateArr(int oArr[sizeArr][sizeArr][sizeArr][sizeArr], int dArr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			for (int k = 0; k < sizeArr; k++)
			{
				for (int l = 0; l < sizeArr; l++)
				{
					dArr[i][j][k][l] = oArr[i][j][k][l];
				}
			}
		}
	}
}

// Takes a full box as input, creates a solvable puzzle with unique solution
void createBox(int arr[sizeArr][sizeArr][sizeArr][sizeArr]) {

	int attempts = 0, tryArr[sizeArr][sizeArr][sizeArr][sizeArr], memoryArr[sizeArr][sizeArr][sizeArr][sizeArr];

	duplicateArr(arr, tryArr);
	duplicateArr(arr, memoryArr);

	while (attempts < pairs)
	{
		removePair(tryArr, uniquePair());

		duplicateArr(tryArr, memoryArr);

		if (isSolvable(tryArr))
		{
			duplicateArr(memoryArr, arr);
			duplicateArr(memoryArr, tryArr);
		}
		else
		{
			duplicateArr(arr, tryArr);
		}

		attempts++;
	}
}
