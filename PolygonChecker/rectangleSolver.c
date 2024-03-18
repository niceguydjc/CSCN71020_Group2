//denimm - software implementation

#include "rectangleSolver.h"
#include <math.h>

#define QUADPOINTS 4 // number of points in a quadrilateral
#define LINESINAQUAD 6 // number of possible lines made by a quad
#define PI 3.14159265
void printLine(LINE line) {
	printf("point 1:\nx: %lf, ", line.point1.x);
	printf("y: %lf\n", line.point1.y);
	printf("point 2:\nx: %lf, ", line.point2.x);
	printf("y: %lf\n", line.point2.y);
	printf("length: %lf\n", line.length);
}

//create the rectangle
QUADRILATERAL createQuadrilateral(double ArrayOfXYPairs[4][2]) {//////////////not done

//create points and assign to array
	POINT Points[QUADPOINTS] = {0};
	for (int i = 0; i < QUADPOINTS; i++) {
		Points[i] = createPoint(ArrayOfXYPairs[i]);
	}

//loop through each point and assign them to corners

	POINT TLCorner = Points[0];
	POINT TRCorner = Points[0];
	POINT BLCorner = Points[0];
	POINT BRCorner = Points[0];

	for (int i = 0; i < QUADPOINTS; i++) {
		if (Points[i].x <= TLCorner.x && Points[i].y >= TLCorner.y)
			TLCorner = Points[i];
		if (Points[i].x >= TRCorner.x && Points[i].y >= TRCorner.y)
			TRCorner = Points[i];
		if (Points[i].x <= BLCorner.x && Points[i].y <= BLCorner.y)
			BLCorner = Points[i];
		if (Points[i].x >= BRCorner.x && Points[i].y <= BRCorner.y)
			BRCorner = Points[i];
	}

//make the quadrilateral
	QUADRILATERAL newQuad = {0};
	newQuad.line1 = createLine(TLCorner, TRCorner);
	newQuad.line2 = createLine(TRCorner, BRCorner);
	newQuad.line3 = createLine(BRCorner, BLCorner);
	newQuad.line4 = createLine(BLCorner, TLCorner);

//calculate perimiter
	newQuad.perimiter = findPerimiter(newQuad);


//if it is a rectangle, assign the area
	if (!isRectangle(newQuad))// exit early if its not a rectangle
		return newQuad;

	newQuad.isRectangle = true;

	//calculate area
	newQuad.area = findArea(newQuad);

	return newQuad;
}

POINT createPoint(double pair[2]) {
	POINT newPoint = {0};
	newPoint.x = pair[0];
	newPoint.y = pair[1];
	return newPoint;
}

LINE createLine(POINT point1, POINT point2) {
	LINE newLine = {0};
	newLine.point1 = point1;
	newLine.point2 = point2;
	newLine.length = findLength(newLine);
	return newLine;
}

double findLength(LINE line) {
	double length = 0;
	double dx = line.point1.x - line.point2.x;
	double dy = line.point1.y - line.point2.y;
	length = sqrt((dx * dx) + (dy * dy)); //find the deistance between two points

	return length;
}

double findArea(QUADRILATERAL quad) {
	double area = 0;
	//find two lines that arent equal and calculate their area
	if (quad.line1.length != quad.line2.length) {
		area = quad.line1.length * quad.line2.length;
	}
	else if (quad.line1.length != quad.line3.length) {
		area = quad.line1.length * quad.line3.length;
	}
	else if (quad.line1.length != quad.line4.length) {
		area = quad.line1.length * quad.line4.length;
	}

	return area;
}

double findPerimiter(QUADRILATERAL quad) {
	double perimiter = 0;
	perimiter = quad.line1.length + quad.line2.length + quad.line3.length + quad.line4.length;

	return perimiter;
}

//detect if a quad is a rectangle
bool isRectangle(QUADRILATERAL quad) {
	//check if 2 sets of lengths are equal
	return (quad.line1.length == quad.line3.length && quad.line2.length == quad.line4.length);
}

int compareLines(LINE lhs, LINE rhs) {
	if (lhs.point1.x == rhs.point1.x && lhs.point1.y == rhs.point1.y && lhs.point2.x == rhs.point2.x && lhs.point2.y == rhs.point2.y)
		return 1;
	return 0;
}