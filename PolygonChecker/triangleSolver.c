#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#include "triangleSolver.h"

TriangleAngles calculateTriangleAngles(double side_1, double side_2, double side_3) {
    TriangleAngles angles; // Use the TriangleAngles struct

    // Calculating angles in radians using the law of cosines
    angles.alpha = acos((side_2 * side_2 + side_3 * side_3 - side_1 * side_1) / (2 * side_2 * side_3));
    angles.beta = acos((side_1 * side_1 + side_3 * side_3 - side_2 * side_2) / (2 * side_1 * side_3));
    angles.gamma = acos((side_1 * side_1 + side_2 * side_2 - side_3 * side_3) / (2 * side_1 * side_2));

    // Converting angles to degrees
    angles.alpha = angles.alpha * (180.0 / M_PI);
    angles.beta = angles.beta * (180.0 / M_PI);
    angles.gamma = angles.gamma * (180.0 / M_PI);

    return angles; // Return the struct with angles
}