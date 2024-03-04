#pragma once

//define rectangle structure
typedef struct point {
	int x;
	int y;
} POINT;

//define rectangle structure
typedef struct rectangle {
	POINT topLeftCorner;
	POINT topRightCorner;
	POINT bottomLeftCorner;
	POINT bottomRightCorner;
	int area;
	int perimeter;
} RECTANGLE;

RECTANGLE createRectangle(int ArrayOfPoints[4][2]);