//denimm - software implementation

#include "rectangleSolver.h"
#include <math.h>

#define QUADPOINTS 4 // number of points in a quadrilateral
#define LINESINAQUAD 6 // number of possible lines made by a quad
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

//create lines
	LINE Lines[LINESINAQUAD] = {0};
	for (int i = 0; i < LINESINAQUAD; i++) {
		//case to make a line with 4 & 1
		if (i == LINESINAQUAD - 1) {
			Lines[i] = createLine(Points[i], Points[0]);
			continue;
		}
		//case to make a line with point 2 & 4
		if (i == LINESINAQUAD - 2) {
			Lines[i] = createLine(Points[1], Points[QUADPOINTS - 1]);
			continue;
		}
		//connect points 1 - 4
		Lines[i] = createLine(Points[i], Points[i + 1]);
	}

//calculate slope from lines to assign them to .line1-4
	LINE ValidLines[QUADPOINTS] = { 0 }; // only 4 valid lines
	int validLinesCounter = 0;
	for (int i = 0; i < LINESINAQUAD; i++) {
		//case for if the line is vertical (slope is divided by zero)
		if (Lines[i].point1.x == Lines[i].point2.x) {

			////////////////////////////////////////////////////////////////idk what to do yet
			continue;
		}

		//check if line has a parallel counterpart with slope, if it is, add it to the list of valid lines
		for (int i2 = i + 1; i2 < LINESINAQUAD; i2++) {
			
			//continue if the line has already been included in ValidLines


			if (findSlope(Lines[i]) == findSlope(Lines[i2])) {
				ValidLines[validLinesCounter] = Lines[i];
				ValidLines[validLinesCounter + 2] = Lines[i2]; //add both lines to the list
			}


		}


	}

//check if its a square, rectangle, or invalid

	
QUADRILATERAL newQuad = {0};
newQuad.line1 = ValidLines[0];
newQuad.line2 = ValidLines[1];
newQuad.line3 = ValidLines[2];
newQuad.line4 = ValidLines[3];

//calculate perimiter
	newQuad.perimiter = findPerimiter(newQuad);


//if it is a rectangle, assign the area
	if (!isRectangle(newQuad))// exit early if its not a rectangle
		return newQuad;

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

double findSlope(LINE line) {/////////////not done
	double x1 = line.point1.x;
	double x2 = line.point2.x;
	double y1 = line.point1.y;
	double y2 = line.point2.y;

	double dy = y1 - y2;
	double dx = x1 - x2;

	double slope = 0;

	if(dx == 0){
		return;
	}
	slope = dy / dx;
	return slope;
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
//detect if a quad is a rectangle
bool isRectangle(QUADRILATERAL quad) {
	//check if 2 sets of lengths are equal
	if (quad.line1.length == quad.line2.length) {
		if (quad.line3.length != quad.line4.length)
			return false;
	}
	else if (quad.line1.length == quad.line3.length) {
		if (quad.line2.length != quad.line4.length)
			return false;
	}
	else if (quad.line1.length == quad.line4.length) {
		if (quad.line2.length != quad.line3.length)
			return false;
	}

	//check that 2 sets of slopes are equal
	if ((quad.line1.point1.x == quad.line1.point2.x && quad.line2.point1.x == quad.line2.point2.x) || findSlope(quad.line1) == findSlope(quad.line2)) {
		if ((quad.line3.point1.x == quad.line3.point2.x && quad.line4.point1.x == quad.line4.point2.x) || findSlope(quad.line3) == findSlope(quad.line4))
			return true;
	}
	else if ((quad.line1.point1.x == quad.line1.point2.x && quad.line3.point1.x == quad.line3.point2.x) || findSlope(quad.line1) == findSlope(quad.line3)) {
		if ((quad.line2.point1.x == quad.line2.point2.x && quad.line4.point1.x == quad.line4.point2.x) || findSlope(quad.line2) == findSlope(quad.line4))
			return true;
	}
	else if ((quad.line1.point1.x == quad.line1.point2.x && quad.line4.point1.x == quad.line4.point2.x) || findSlope(quad.line1) == findSlope(quad.line4)) {
		if ((quad.line3.point1.x == quad.line3.point2.x && quad.line2.point1.x == quad.line2.point2.x) || findSlope(quad.line2) == findSlope(quad.line3))
			return true;
	}

	return false;
}
double findPerimiter(QUADRILATERAL quad) {
	double perimiter = 0;
	perimiter = quad.line1.length + quad.line2.length + quad.line3.length + quad.line4.length;

	return perimiter;
}