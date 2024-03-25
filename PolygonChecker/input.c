//Maksymp-input-implementation
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "input.h"

void getRectangleCoordinates(double rectangle_coordinates[4][2]) {
	printf("Enter rectangle coordinates:");
	for (int i = 0; i <= 3; i++) {
		printf("Enter coordinate for point number %d\n", i+1);
		double x_coordinate = 0;
		double y_coordinate = 0;
		printf("\nx: ");
		int symbols_returned_x = scanf("%lf", &x_coordinate);
		symbols_returned_x = inputIsSuitable(symbols_returned_x);
		printf("\ny: ");
		int symbols_returned_y = scanf("%lf", &y_coordinate);
		symbols_returned_y = inputIsSuitable(symbols_returned_y);
		rectangle_coordinates[i][0] = x_coordinate;
		rectangle_coordinates[i][1] = y_coordinate;
	}
}
int inputIsSuitable(int symbols_returned) {
	if (symbols_returned != 1) {
		printf("The input is not suitable for the program.exiting\n");
		exit(EXIT_FAILURE);
	}
	else {
		return symbols_returned;
	}
}
int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	int symbols_returned = 0;
	for (int i = 0; i < 3; i++)
	{
		symbols_returned = scanf("%d", &triangleSides[i]);
		if (symbols_returned <= 0) {
			printf("The side you entered is less or equal to zero.");
			symbols_returned = 0;
		}
		symbols_returned = inputIsSuitable(symbols_returned);
	}
	return triangleSides;
}