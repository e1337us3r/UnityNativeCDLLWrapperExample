#pragma once
#ifdef TESTFUNCDLL_EXPORT
#define TESTFUNCDLL_API __declspec(dllexport) 
#else
#define TESTFUNCDLL_API __declspec(dllimport) 
#endif


struct Cube
{
	int y, index;
};

extern "C" {


	TESTFUNCDLL_API void SortCubeArray(Cube cubeArray[], int cubeCount);
	//TESTFUNCDLL_API int* SortCubeArray(int *cubeArray, int cubeCount);
	TESTFUNCDLL_API int NthFibonacciNumber(int n);
	TESTFUNCDLL_API char* DeletePattern(char* target, char* pattern, int targetLenght, int patternLenght, char replacementChar);
	TESTFUNCDLL_API int FindPattern(char* target, char* pattern, int targetLenght, int patternLenght);
}