#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
#include "input.h"

int side = 0;
double side_1;
double side_2;
double side_3;

int main() {
	double array_of_coordinates_for_rectangle[4][2] = { 0 };


	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf("Enter the lengths of the three sides of a triangle:\n");
			if (scanf("%lf %lf %lf", &side_1, &side_2, &side_3) != 3) {
				printf("Invalid input. Please enter three numeric values.\n");
				return 1; // Exit with error status
			}

			// Check for non-positive side lengths
			if (side_1 <= 0 || side_2 <= 0 || side_3 <= 0) {
				printf("Sides must be greater than zero.\n");
				return 1; // Exit with error status
			}

			// Check if the sides form a triangle using the triangle inequality theorem
			if (side_1 + side_2 > side_3 && side_1 + side_3 > side_2 && side_2 + side_3 > side_1) {
				printf("The sides form a triangle.\n");
				calculateTriangleAngles(side_1, side_2, side_3);
			}
			else {
				printf("The given sides do not form a triangle.\n");
			}
			break;
		case 2:
			getRectangleCoordinates(array_of_coordinates_for_rectangle);

			QUADRILATERAL quad = createQuadrilateral(array_of_coordinates_for_rectangle);



			printf("perimiter: %lf\n", quad.perimiter);
			if (quad.isRectangle)
				printf("area: %lf\n", quad.area);

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
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

