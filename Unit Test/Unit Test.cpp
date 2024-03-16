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


extern "C" int inputIsSuitable(int);
extern "C" QUADRILATERAL createQuadrilateral(double array[4][2]);
extern "C" LINE createLine(POINT point1, POINT point2);
extern "C" POINT createPoint(double pair[2]);
extern "C" char* analyzeTriangle(int, int, int);
extern "C" double findSlope(LINE line);
extern "C" double findLength(LINE);
extern "C" double findArea(QUADRILATERAL quad);
extern "C" double findPerimiter(QUADRILATERAL quad);
extern "C" bool isRectangle(QUADRILATERAL quad);

namespace input
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Input_for_rectangle_coordinates_and_triangle_is_not_suitable)
		{
			int parameter = 0;
			int expected = EXIT_FAILURE;
			int actual = inputIsSuitable(parameter);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(Input_for_rectangle_coordinates_and_triangle_is_suitable)
		{
			int parameter = 1;
			int expected = 1;
			int actual = inputIsSuitable(parameter);
			Assert::AreEqual(expected, actual);
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
	TEST_CLASS(createPointF)
	{
	public:
		TEST_METHOD(Test001)
		{
			double QuadArray[4][2] = { {5,10}, {5,5}, {15,10}, {15,5} };
			POINT point = createPoint(QuadArray[3]);

			bool equal = 0;
			//if the x and y of the point are correct, assert true
			if (point.x == 15 && point.y == 5)
				equal = true;
			Assert::IsTrue(equal);
		}
	};
	TEST_CLASS(createLineF)
	{
	public:
		TEST_METHOD(Test001)
		{
			double QuadArray[4][2] = { {5,10}, {5,5}, {15,10}, {15,5} };
			POINT point1 = createPoint(QuadArray[0]);
			POINT point2 = createPoint(QuadArray[1]);
			LINE testLine = createLine(point1, point2);
			bool expected = 0;
			if (testLine.point1.x == 5 && testLine.point1.y == 10 && testLine.point2.x == 5 && testLine.point2.y == 5) {
				expected = true;
			}
			Assert::IsTrue(expected);
		}
	};

	TEST_CLASS(findLengthF)
	{
	public:

		TEST_METHOD(Test001)
		{
			double QuadArray[4][2] = { {5,10}, {5,5}, {15,10}, {15,5} };
			POINT point1 = createPoint(QuadArray[0]);
			POINT point2 = createPoint(QuadArray[1]);
			LINE testLine = createLine(point1, point2);

			double expected = 5;
			double actual = findLength(testLine);
			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(findSlopeF)
	{
	public:
		TEST_METHOD(Test001)
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

	TEST_CLASS(isRectangleF)
	{
	public:
		TEST_METHOD(Test001)
		{
			double QuadArray[4][2] = { {5,10}, {5,5}, {15,10}, {15,5} };
			QUADRILATERAL testQuad = createQuadrilateral(QuadArray);
			bool expected = true;
			bool actual = isRectangle(testQuad);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(Test002)
		{
			double QuadArray[4][2] = { {5,10}, {20,5}, {15,10}, {30,5} }; //diamond, not rectangle
			QUADRILATERAL testQuad = createQuadrilateral(QuadArray);
			bool expected = false;
			bool actual = isRectangle(testQuad);
			Assert::AreEqual(expected, actual);
		}
	};


	TEST_CLASS(findAreaF)
	{
	public:
		TEST_METHOD(Test001)
		{
			double expected = 50;
			double QuadArray[4][2] = { {5,10}, {5,5}, {15,10}, {15,5} };

			QUADRILATERAL testQuad = createQuadrilateral(QuadArray);
			double actual = testQuad.area;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(Test002)
		{
			double expected = 50;
			double QuadArray[4][2] = { {5,10}, {5,5}, {15,10}, {15,5} };

			QUADRILATERAL testQuad = createQuadrilateral(QuadArray);
			double actual = findArea(testQuad);
			Assert::AreEqual(expected, actual);
		}
	};
	TEST_CLASS(findPerimeterF)
	{
	public:

		TEST_METHOD(Test001)
		{
			double expected = 30;
			double QuadArray[4][2] = { {5,10}, {5,5}, {15,10}, {15,5} };
		
			QUADRILATERAL testQuad = createQuadrilateral(QuadArray);
			double actual = findPerimiter(testQuad);
			Assert::AreEqual(expected, actual);
		}
	};
}