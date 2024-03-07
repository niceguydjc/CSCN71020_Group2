//Maksymp-input-implementation
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int** createCoordinateArray(int** CoordinateArray) {
	printf("Enter coordinates for the rectangle\n");
	for (int i = 0; i <= 3; i++) {
		printf("Enter coordinate for point number %d\n", i + 1);
		int x_coordinate = 0;
		int y_coordinate = 0;
		printf("x: ");
		int symbols_returned_x = scanf("%d", &x_coordinate);
		if (symbols_returned_x != 1) {
			printf("The input is not suitable for the program.exiting\n");
			exit(EXIT_FAILURE);
		}
		printf("\ny: ");
		int symbols_returned_y = scanf("%d", &y_coordinate);
		if (symbols_returned_y != 1) {
			printf("The input is not suitable for the program.exiting\n");
			exit(EXIT_FAILURE);
		}
		CoordinateArray[i][0] = x_coordinate;
		CoordinateArray[i][1] = y_coordinate;
	}
	return **CoordinateArray;
}