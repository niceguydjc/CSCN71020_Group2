//Maksymp-input-implementation
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "input.h"

//float** createCoordinateArray(float** CoordinateArray) {
//	printf("Enter coordinates for the rectangle\n");
//	for (int i = 0; i <= 3; i++) {
//		printf("Enter coordinate for point number %d\n", i + 1);
//		float x_coordinate = 0;
//		float y_coordinate = 0;
//		printf("x: ");
//		int symbols_returned_x = scanf("%f", &x_coordinate);
//		if (symbols_returned_x != 1) {
//			printf("The input is not suitable for the program.exiting\n");
//			exit(EXIT_FAILURE);
//		}
//		printf("\ny: ");
//		int symbols_returned_y = scanf("%f", &y_coordinate);
//		if (symbols_returned_y != 1) {
//			printf("The input is not suitable for the program.exiting\n");
//			exit(EXIT_FAILURE);
//		}
//		CoordinateArray[i][0] = x_coordinate;
//		CoordinateArray[i][1] = y_coordinate;
//	}
//	return CoordinateArray;
//}
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
