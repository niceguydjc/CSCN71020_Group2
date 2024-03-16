#pragma once

#include <stdbool.h>
#include <stdio.h>

#define QUADRILATERALPOINTS 4

#define LINESINAQUAD 6

//define rectangle structure
typedef struct point {
	double x;
	double y;
} POINT;

typedef struct line {
	POINT point1;
	POINT point2;
	double length;


} LINE;

//define rectangle structure
typedef struct quadrilateral {
	LINE line1;
	LINE line2;
	LINE line3;
	LINE line4;
	bool isRectangle;
	double perimiter;
	double area;
} QUADRILATERAL;



QUADRILATERAL createQuadrilateral(double ArrayOfPoints[4][2]);

POINT createPoint(double pair[2]);

LINE createLine(POINT, POINT);

double findSlope(LINE line);
double findLength(LINE line);
double findArea(QUADRILATERAL quad);
double findPerimiter(QUADRILATERAL quad);

bool isRectangle(QUADRILATERAL quad);

void printLine(LINE);
