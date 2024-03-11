#pragma once

#include <stdbool.h>
#include <stdio.h>
//define rectangle structure
typedef struct point {
	double x;
	double y;
} POINT;

typedef struct line {
	POINT point1;
	POINT point2;
	double slope;


} LINE;

//define rectangle structure
typedef struct quadrilateral {
	LINE line1;
	LINE line2;
	LINE line3;
	LINE line4;
	LINE line5;
	LINE line6;
	bool isRectangle;
} QUADRILATERAL;

#define QUADRILATERALPOINTS 4

#define LINESINAQUAD 6

QUADRILATERAL createQuadrilateral(double ArrayOfPoints[4][2]);

POINT createPoint(double pair[2]);

LINE createLine(POINT, POINT);

double findSlope(LINE);

void filterLines(LINE*, QUADRILATERAL);
