#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#include "triangleSolver.h"

int main() {
    double side_1;
    double side_2;
    double side_3;

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

    return 0;
}