#pragma once

// Define the TriangleAngles struct
typedef struct {
    double alpha;
    double beta;
    double gamma;
} TriangleAngles;

// Update the function prototype to return TriangleAngles struct
TriangleAngles calculateTriangleAngles(double side_1, double side_2, double side_3);