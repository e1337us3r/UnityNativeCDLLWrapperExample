#include "stdafx.h"
extern "C" { 

	

	// This functio uses the standard recursive algorithm for finding nth term in fibonacci sequence
	int NthFibonacciNumber(int n) {

		// Sanity check
		if (n < 0)
			return -1;
		
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else return NthFibonacciNumber(n - 1) + NthFibonacciNumber(n - 2);
	}


	// This function replaces characters of the pattern with replacementChar (if pattern exists in target string) 
	char* DeletePattern(char* target, char* pattern, int targetLenght, int patternLenght, char replacementChar) {
		int startIndex = FindPattern(target, pattern,targetLenght,patternLenght);

		//pattern doesn't exist in target string
		if (startIndex == -1) return target;

		// replace pattern with replacementChar given
		for (int i = 0; i < patternLenght; i++)
		{
			*(target + startIndex + i) = replacementChar;
		}

		return target;
	}


	// This function tries to find the pattern in target string, returns -1 if not found
	int FindPattern(char* target, char* pattern, int targetLenght, int patternLenght){
	
		//loop until matching first letter of pattern
		// "targetLenght-patternLenght" this is a small trick to decrease total iteration count
		for (int i = 0; i < targetLenght-patternLenght; i++)
		{
			//first letter of pattern matched
			if (*(target + i) == *pattern) {
				
				//start looping from second letter since first letter is already checked
				int cursor = 1;

				//loop until either cursor equals to patternLenght or we find a char in sequence that doesn't match
				while (cursor < patternLenght && (*(target + i + cursor) == *(pattern+cursor)))				
					cursor++;
				
				// 100% match
				if (cursor == patternLenght)
					//return starting index of the pattern in the target string
					return i;
				
			}
		}

		return -1;
	}
	
	// This function uses the enhanced bubble sort algorithm
	// it is more efficient than standard bubble sort for all cases except the worst case
	void SortCubeArray(Cube cubeArray[], int cubeCount)
	{
		bool didSwap = false;

		for (int i = 0; i < cubeCount - 1; i++)
		{
			didSwap = false;
			for (int j = 0; j < cubeCount - i - 1; j++)
			{
				if (cubeArray[j].y > cubeArray[j + 1].y)
				{
					Cube temp = cubeArray[j];
					cubeArray[j] = cubeArray[j + 1];
					cubeArray[j + 1] = temp;

					didSwap = true;
				}
			}

			if (didSwap == false)
				break;
		}

	}



	// A specialized version of bubble sort 
	// int *cubeArray : 2 dim int array, the first row holds y information while the second row holds indexes
	// int cubeCount: amount of cubes in array
	/*
	int* SortCubeArray(int *cubeArray, int cubeCount) {

		for (int i = 0; i < cubeCount - 1; i++)

			for (int j = 0; j < cubeCount - i - 1; j++)
				if (*(cubeArray + (0 * cubeCount + j)) > *(cubeArray + 0 + j + 1)) {
					int temp = *(cubeArray + (0 * cubeCount + j));
					*(cubeArray + (0 * cubeCount + j)) = *(cubeArray + (0 * cubeCount + j + 1));
					*(cubeArray + (0 * cubeCount + j + 1)) = temp;

					//when swapping the y values of boxes,
					//swap indexes that correspond to those boxes as well
					temp = *(cubeArray + (1*cubeCount + j));
					*(cubeArray + (1 * cubeCount + j)) = *(cubeArray + (1 * cubeCount + j + 1));
					*(cubeArray + (1 * cubeCount + j + 1)) = temp;

				}

		return cubeArray;
	}*/


}