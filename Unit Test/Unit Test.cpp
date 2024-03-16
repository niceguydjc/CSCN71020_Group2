#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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



extern "C" float** createCoordinateArray(float** CoordinateArray);
extern "C" QUADRILATERAL createQuadrilateral(double array[4][2]);
extern "C" LINE createLine(POINT point1, POINT point2);
extern "C" POINT createPoint(double pair[2]);
extern "C" char* analyzeTriangle(int, int, int);
extern "C" double findSlope(LINE line);
extern "C" double findLength(LINE);


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
	TEST_CLASS(assigningLines)
	{
	public:

		TEST_METHOD(TestcreatePoint)
		{
			double QuadArray[4][2] = { {5,10}, {5,5}, {5,10}, {15,5} };
			POINT point = createPoint(QuadArray[3]);

			bool equal = 0;
			//if the x and y of the point are correct, assert true
			if (point.x == 5 && point.y == 10)
				equal = true;
			Assert::IsTrue(equal);
		}
		TEST_METHOD(TestfindLength)
		{
			double QuadArray[4][2] = { {5,10}, {5,5}, {5,10}, {15,5} };
			POINT point1 = createPoint(QuadArray[0]);
			POINT point2 = createPoint(QuadArray[1]);
			LINE testLine = createLine(point1, point2);

			double expected = 5;
			double actual = findLength(testLine);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestfindSlopeFunct)
		{
			double coord1[2] = { 10, 10 };
			double coord2[2] = { 5, 5 };

			POINT point1 = createPoint(coord1);
			POINT point2 = createPoint(coord2);
			LINE line = createLine(point1, point2);

			double expected = 1;
			double actual = findSlope(line);
			Assert::AreEqual(expected, actual);
		}

	};
	TEST_CLASS(area)
	{
	public:
		TEST_METHOD(Test001)
		{
		int expected = 50;
		double QuadArray[4][2] = { {5,10}, {5,5}, {5,10}, {15,5} };

		QUADRILATERAL testQuad = createQuadrilateral(QuadArray);
		int actual = testQuad.area;
		Assert::AreEqual(expected, actual);
		}
	};
	TEST_CLASS(perimeter)
	{
	public:

		TEST_METHOD(Test001)
		{
		int expected = 30;
		double QuadArray[4][2] = { {5,10}, {5,5}, {5,10}, {15,5} };
		
		QUADRILATERAL testQuad = createQuadrilateral(QuadArray);
		int actual = testQuad.perimiter;
		Assert::AreEqual(expected, actual);
		}
	};
}