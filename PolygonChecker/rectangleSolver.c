//denimm - software implementation

#include "rectangleSolver.h"


void printLine(LINE line) {
	printf("point 1:\nx: %lf, ", line.point1.x);
	printf("y: %lf\n", line.point1.y);
	printf("point 2:\nx: %lf, ", line.point2.x);
	printf("y: %lf\n", line.point2.y);
}
//create the rectangle
QUADRILATERAL createQuadrilateral(double ArrayOfXYPairs[4][2]) {
	//check if set of points makes a rectangle
		//lines made between all points contains 2 pairs of identical sides


	QUADRILATERAL newQuad = {0};


	//create all 4 points
	POINT point1 = createPoint(ArrayOfXYPairs[0]);
	POINT point2 = createPoint(ArrayOfXYPairs[1]);
	POINT point3 = createPoint(ArrayOfXYPairs[2]);
	POINT point4 = createPoint(ArrayOfXYPairs[3]);

	//run through all six possible lines then add them to an array.
	//makes a line from each point 1,2 2,3 3,4 1,4, 2,4, 1,3


	LINE line1 = createLine(point1, point2);
	LINE line2 = createLine(point2, point3);
	LINE line3 = createLine(point3, point4);
	LINE line4 = createLine(point4, point1);
	LINE line5 = createLine(point1, point3);
	LINE line6 = createLine(point2, point4);

	LINE LineArray[LINESINAQUAD] = { line1, line2, line3, line4, line5, line6 };

	printf("testing coordinates\n");
	printLine(line1);
	printLine(line2);
	printLine(line3);
	printLine(line4);
	printLine(line5);
	printLine(line6);


	printf("testing slopes\n");
	printf("%lf\n", line1.slope);
	printf("%lf\n", line2.slope);
	printf("%lf\n", line3.slope);
	printf("%lf\n", line4.slope);
	printf("%lf\n", line5.slope);
	printf("%lf\n", line6.slope);

	
	return newQuad;
}

POINT createPoint(double* pair) {
	POINT newPoint = {0};
	newPoint.x = pair[0];
	newPoint.y = pair[1];
	return newPoint;
}

LINE createLine(POINT point1, POINT point2) {
	LINE newLine = {0};
	newLine.point1 = point1;
	newLine.point2 = point2;
	newLine.slope = findSlope(newLine);
	return newLine;
}

double findSlope(LINE line) {
	double x1 = line.point1.x;
	double x2 = line.point2.x;
	double y1 = line.point1.y;
	double y2 = line.point2.y;

	printf("POINTSINSLOPEFUNCT: %lf, %lf, %lf, %lf\n", x1, x2, y1, y2);

	double dy = y1 - y2;
	double dx = x1 - x2;
	printf("deltas: x %lf y %lf\n", dx, dy);
	double slope = dy / dx;
	printf("SLOPE: %lf\n", slope);
	return slope;
}

void filterLines(LINE* LineList, QUADRILATERAL quad) {
	
	int finalIndex = 0;
	//two lines are parallel if they have the same slope. this function will compare the lines until two sets of parallel lines is found
	for (int index1 = 0; index1 <= LINESINAQUAD; index1++) {

		for (int index2 = 0; index2 <= LINESINAQUAD; index2++) {
			if (LineList[index1].slope != LineList[index2].slope) {
				continue;
			}

			




		}

	}
}
