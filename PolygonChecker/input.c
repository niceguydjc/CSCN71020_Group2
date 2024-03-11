//Maksymp-input-implementation
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


float** createCoordinateArray(float** CoordinateArray) {
	printf("Enter coordinates for the rectangle\n");
	for (int i = 0; i <= 3; i++) {
		printf("Enter coordinate for point number %d\n", i + 1);
		float x_coordinate = 0;
		float y_coordinate = 0;
		printf("x: ");
		int symbols_returned_x = scanf("%f", &x_coordinate);
		if (symbols_returned_x != 1) {
			printf("The input is not suitable for the program.exiting\n");
			exit(EXIT_FAILURE);
		}
		printf("\ny: ");
		int symbols_returned_y = scanf("%f", &y_coordinate);
		if (symbols_returned_y != 1) {
			printf("The input is not suitable for the program.exiting\n");
			exit(EXIT_FAILURE);
		}
		CoordinateArray[i][0] = x_coordinate;
		CoordinateArray[i][1] = y_coordinate;
	}
	return CoordinateArray;
}