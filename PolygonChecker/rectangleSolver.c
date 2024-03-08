//denimm - software implementation

#include "rectangleSolver.h"


//create the rectangle
RECTANGLE createRectangle(int ArrayOfXYPairs[4][2]) {
	//check if set of points makes a rectangle
		//lines made between all points contains 2 pairs of identical sides


	//start all corners off with the same coordinate
	int initialx = ArrayOfXYPairs[0][0];
	int initialy = ArrayOfXYPairs[0][1];


	RECTANGLE newRectangle = {0};
	newRectangle.topLeftCorner.x = initialx;
	newRectangle.topLeftCorner.y = initialy;

	newRectangle.topRightCorner.x = initialx;
	newRectangle.topRightCorner.y = initialy;

	newRectangle.bottomLeftCorner.x = initialx;
	newRectangle.bottomLeftCorner.y = initialy;

	newRectangle.bottomRightCorner.x = initialx;
	newRectangle.bottomRightCorner.y = initialy;




	//run through each corner until the lowest x and highest y is found
	//find top left corner & assign
	for (int index = 0; index < 4; index++) {

		if (ArrayOfXYPairs[index][0] < newRectangle.topLeftCorner.x) {
			newRectangle.topLeftCorner.x = ArrayOfXYPairs[index][0];
		}
		if (ArrayOfXYPairs[index][1] > newRectangle.topLeftCorner.y) {
			newRectangle.topLeftCorner.y = ArrayOfXYPairs[index][1];
		}
	}
	//top right
	for (int index = 0; index < 4; index++) {

		if (ArrayOfXYPairs[index][0] > newRectangle.topRightCorner.x) {
			newRectangle.topRightCorner.x = ArrayOfXYPairs[index][0];
		}
		if (ArrayOfXYPairs[index][1] > newRectangle.topRightCorner.y) {
			newRectangle.topRightCorner.y = ArrayOfXYPairs[index][1];
		}
	}
	//bottom right
	for (int index = 0; index < 4; index++) {

		if (ArrayOfXYPairs[index][0] > newRectangle.bottomRightCorner.x) {
			newRectangle.bottomRightCorner.x = ArrayOfXYPairs[index][0];
		}
		if (ArrayOfXYPairs[index][1] < newRectangle.bottomRightCorner.y) {
			newRectangle.bottomRightCorner.y = ArrayOfXYPairs[index][1];
		}
	}
	//bottom left
	for (int index = 0; index < 4; index++) {

		if (ArrayOfXYPairs[index][0] < newRectangle.bottomLeftCorner.x) {
			newRectangle.bottomLeftCorner.x = ArrayOfXYPairs[index][0];
		}
		if (ArrayOfXYPairs[index][1] < newRectangle.bottomLeftCorner.y) {
			newRectangle.bottomLeftCorner.y = ArrayOfXYPairs[index][1];
		}
	}
	
	return newRectangle;
}


