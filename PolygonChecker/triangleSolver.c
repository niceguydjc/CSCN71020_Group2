#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#include "triangleSolver.h"

void calculateTriangleAngles(double side_1, double side_2, double side_3) {
    double alpha, beta, gamma; // Angles opposite sides a, b, and c respectively

    // Calculating angles in radians using the law of cosines
    alpha = acos((side_2 * side_2 + side_3 * side_3 - side_1 * side_1) / (2 * side_2 * side_3));
    beta = acos((side_1 * side_1 + side_3 * side_3 - side_2 * side_2) / (2 * side_1 * side_3));
    gamma = acos((side_1 * side_1 + side_2 * side_2 - side_3 * side_3) / (2 * side_1 * side_2));

    // Converting angles to degrees
    alpha = alpha * (180.0 / M_PI);
    beta = beta * (180.0 / M_PI);
    gamma = gamma * (180.0 / M_PI);

    printf("The angles of the triangle are: \n");
    printf("Alpha: %lf degrees\n", alpha);
    printf("Beta: %lf degrees\n", beta);
    printf("Gamma: %lf degrees\n", gamma);
}