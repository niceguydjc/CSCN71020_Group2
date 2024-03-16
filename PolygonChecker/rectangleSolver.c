//denimm - software implementation

#include "rectangleSolver.h"

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
				ValidLines[validLinesCounter + 2] = Lines[i2]; //add both linesto the list
			}


		}


	}

//(optional) sort the lines into their proper order


//check if its a square, rectangle, or invalid

	
	QUADRILATERAL newQuad = {0};


//calculate perimiter

//calculate area



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
	newLine.length = distance(point1, point2);
	return newLine;
}

double findSlope(LINE line) {/////////////not done
	double x1 = line.point1.x;
	double x2 = line.point2.x;
	double y1 = line.point1.y;
	double y2 = line.point2.y;

	printf("POINTSINSLOPEFUNCT: %lf, %lf, %lf, %lf\n", x1, x2, y1, y2);

	double dy = y1 - y2;
	double dx = x1 - x2;

	if(dx == 0){
		return;
	}
	double slope = dy / dx;
	return slope;
}

double findLength(LINE line) {
	double length = 0;
	////////////////////////////////////////////////
	return length;
}