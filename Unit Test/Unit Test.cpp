#include "pch.h"
#include "CppUnitTest.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

extern "C" struct rectangle createRectangle(int ArrayOfPoints[4][2]);



int equalRectangles(RECTANGLE rectangle1, RECTANGLE rectangle2);

namespace input
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
	};
}
namespace triangle
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};
}
namespace rectangles
{
	TEST_CLASS(area)
	{
	public:
		TEST_METHOD(Test001)
		{
			




		}
	};
	TEST_CLASS(perimeter)
	{
	public:

		TEST_METHOD(Test001)
		{





		}
	};
	TEST_CLASS(exceptions)
	{
	public:

		TEST_METHOD(Test001)
		{
			RECTANGLE expected;
			expected.bottomRightCorner.x = 8;
			expected.bottomRightCorner.y = 2;
			expected.bottomLeftCorner.x = 2;
			expected.bottomLeftCorner.y = 2;
			expected.topRightCorner.x = 8;
			expected.topRightCorner.y = 6;
			expected.topLeftCorner.x = 2;
			expected.topLeftCorner.y = 6;

			int InputArray[4][2] = {
				{8,2}, {2, 2}, {8, 6}, {2, 6}
			};

			RECTANGLE actual = createRectangle(InputArray);
			int result = equalRectangles(expected, actual);
			Assert::AreEqual(result, 1);

		}
	};
}

//compares two rectangle structures, returns 1 if they are equal
int equalRectangles(RECTANGLE rectangle1, RECTANGLE rectangle2) {
	//compare top left
	if (rectangle1.topLeftCorner.x != rectangle2.topLeftCorner.x) {
		return 0;
	}
	if (rectangle1.topLeftCorner.y != rectangle2.topLeftCorner.y) {
		return 0;
	}
	//compare top right
	if (rectangle1.topRightCorner.x != rectangle2.topRightCorner.x) {
		return 0;
	}
	if (rectangle1.topRightCorner.y != rectangle2.topRightCorner.y) {
		return 0;
	}

	if (rectangle1.bottomRightCorner.x != rectangle2.bottomRightCorner.x) {
		return 0;
	}
	if (rectangle1.bottomRightCorner.y != rectangle2.bottomRightCorner.y) {
		return 0;
	}

	if (rectangle1.bottomLeftCorner.x != rectangle2.bottomLeftCorner.x) {
		return 0;
	}
	if (rectangle1.bottomLeftCorner.y != rectangle2.bottomLeftCorner.y) {
		return 0;
	}

	return 1;
}