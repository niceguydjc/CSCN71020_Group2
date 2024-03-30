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



//////////////////////
//put functions here//
//////////////////////
extern "C" int inputIsSuitable(int);
extern "C" {
	typedef struct {
		double alpha;
		double beta;
		double gamma;
	} TriangleAngles;

	TriangleAngles calculateTriangleAngles(double side_1, double side_2, double side_3);
}
extern "C" QUADRILATERAL createQuadrilateral(double ArrayOfPoints[4][2]);
extern "C" LINE createLine(POINT point1, POINT point2);
extern "C" POINT createPoint(double pair[2]);
extern "C" double findLength(LINE);
extern "C" double findArea(QUADRILATERAL quad);
extern "C" double findPerimiter(QUADRILATERAL quad);
extern "C" bool isRectangle(QUADRILATERAL quad);
extern "C" int compareLines(LINE lhs, LINE rhs);

namespace input
{
	TEST_CLASS(ScanfReturnValueCheck)
	{
	public:
		
		TEST_METHOD(Input_for_rectangle_coordinates_and_triangle_is_not_suitable)
		{
			int parameter = 0;
			int expected = 1;
			int actual = inputIsSuitable(parameter);
			Assert::AreNotEqual(expected, actual);
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
	TEST_CLASS(RightAngle)
	{
	public:

		TEST_METHOD(TestRightAngledTriangle) {
			TriangleAngles angles = calculateTriangleAngles(3, 4, 5);

			// Asserts to check the angles with a tolerance
			Assert::AreEqual(90.0, angles.alpha, 0.1, L"Alpha angle is not correct.");
			Assert::AreEqual(53.13, angles.beta, 0.1, L"Beta angle is not correct.");
			Assert::AreEqual(36.87, angles.gamma, 0.1, L"Gamma angle is not correct.");
		}
	};

	TEST_CLASS(Equilateral)
	{
	public:

		TEST_METHOD(TestEquilateralTriangle) {
			TriangleAngles angles = calculateTriangleAngles(6, 6, 6);

			// Since it's an equilateral triangle, all angles should be close to 60 degrees
			Assert::AreEqual(60.0, angles.alpha, 0.1, L"Alpha angle is not correct for an equilateral triangle.");
			Assert::AreEqual(60.0, angles.beta, 0.1, L"Beta angle is not correct for an equilateral triangle.");
			Assert::AreEqual(60.0, angles.gamma, 0.1, L"Gamma angle is not correct for an equilateral triangle.");
		}
	};

	TEST_CLASS(Scalene)
	{
	public:

		TEST_METHOD(TestScaleneTriangle) {
			TriangleAngles angles = calculateTriangleAngles(7, 8, 9);

			// Expected angles are calculated beforehand and are specific to this scalene triangle
			Assert::AreEqual(44.415308597, angles.alpha, 0.1, L"Alpha angle is not correct for a scalene triangle.");
			Assert::AreEqual(55.150399829, angles.beta, 0.1, L"Beta angle is not correct for a scalene triangle.");
			Assert::AreEqual(80.434291574, angles.gamma, 0.1, L"Gamma angle is not correct for a scalene triangle.");
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
	TEST_CLASS(createQuadrilateralF)
	{
	public:
		TEST_METHOD(Test001)
		{
			bool actual = false;
			double QuadArray[4][2] = { {5,10}, {5,5}, {15,10}, {15,5} };
			POINT TL = createPoint(QuadArray[0]);
			POINT TR = createPoint(QuadArray[2]);
			POINT BR = createPoint(QuadArray[3]);
			POINT BL = createPoint(QuadArray[1]);

			LINE line1 = createLine(TL, TR);
			LINE line2 = createLine(TR, BR);
			LINE line3 = createLine(BR, BL);
			LINE line4 = createLine(BL, TL);



			QUADRILATERAL testQuad = createQuadrilateral(QuadArray);
			if (compareLines(testQuad.line1, line1) && compareLines(testQuad.line2, line2) && compareLines(testQuad.line3, line3) && compareLines(testQuad.line4, line4))
				actual = true;
			Assert::IsTrue(actual);
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
	TEST_CLASS(compareLinesF)
	{
	public:

		TEST_METHOD(Test001)
		{
			bool expected = true;
			double QuadArray[4][2] = { {5,10}, {5,5}, {15,10}, {15,5} };
			POINT p1 = createPoint(QuadArray[0]);
			POINT p2 = createPoint(QuadArray[1]);
			POINT p3 = createPoint(QuadArray[2]);
			POINT p4 = createPoint(QuadArray[3]);

			LINE line1 = createLine(p1, p2);
			LINE line2 = createLine(p1, p2);

			bool actual = compareLines(line1, line2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(Test002)
		{
			bool expected = false;
			double QuadArray[4][2] = { {5,10}, {5,5}, {15,10}, {15,5} };
			POINT p1 = createPoint(QuadArray[0]);
			POINT p2 = createPoint(QuadArray[1]);
			POINT p3 = createPoint(QuadArray[2]);
			POINT p4 = createPoint(QuadArray[3]);

			LINE line1 = createLine(p1, p2);
			LINE line2 = createLine(p3, p2);

			bool actual = compareLines(line1, line2);
			Assert::AreEqual(expected, actual);
		}
	};
}