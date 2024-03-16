#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

int main() {
	double array[4][2] = { {0,1},{1.6,0.2},{0,-3},{-1.6,-2.2} };
	QUADRILATERAL quad = createQuadrilateral(array);

	printf("test that lines are stored:\n");

	/*printLine(quad.Lines[0]);
	printLine(quad.Lines[1]);
	printLine(quad.Lines[2]);
	printLine(quad.Lines[3]);

	*/

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	int symbols_returned = 0;
	for (int i = 0; i < 3; i++)
	{
		symbols_returned=scanf("%d", &triangleSides[i]);
		if (symbols_returned != 1) {
			printf("Error. Yor input is not suitable for the program. exiting");
			exit(EXIT_FAILURE);
		}
	}
	return triangleSides;
}