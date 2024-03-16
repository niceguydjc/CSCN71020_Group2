#include "pch.h"
#include "CppUnitTest.h"
#include "triangleSolver.h"



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

extern "C" RECTANGLE createRectangle(int ArrayOfPoints[4][2]);
extern "C" char* analyzeTriangle(int, int, int);


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

		TEST_METHOD(TestRightAngledTriangle) {
			double alpha, beta, gamma;
			TriangleCalculator::calculateTriangleAngles(3, 4, 5, alpha, beta, gamma);

			// Asserts to check the angles with a tolerance
			Assert::AreEqual(90.0, alpha, 0.1, L"Alpha angle is not correct.");
			Assert::AreEqual(53.13, beta, 0.1, L"Beta angle is not correct.");
			Assert::AreEqual(36.87, gamma, 0.1, L"Gamma angle is not correct.");
		}
	};

	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestEquilateralTriangle) {
			double alpha, beta, gamma;
			TriangleCalculator::calculateTriangleAngles(6, 6, 6, alpha, beta, gamma);

			// Since it's an equilateral triangle, all angles should be close to 60 degrees
			Assert::AreEqual(60.0, alpha, 0.1, L"Alpha angle is not correct for an equilateral triangle.");
			Assert::AreEqual(60.0, beta, 0.1, L"Beta angle is not correct for an equilateral triangle.");
			Assert::AreEqual(60.0, gamma, 0.1, L"Gamma angle is not correct for an equilateral triangle.");
		}
	};

	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestScaleneTriangle) {
			double alpha, beta, gamma;
			TriangleCalculator::calculateTriangleAngles(7, 8, 9, alpha, beta, gamma);

			// Expected angles are calculated beforehand and are specific to this scalene triangle
			Assert::AreEqual(44.415308597, alpha, 0.1, L"Alpha angle is not correct for a scalene triangle.");
			Assert::AreEqual(55.150399829, beta, 0.1, L"Beta angle is not correct for a scalene triangle.");
			Assert::AreEqual(80.434291574, gamma, 0.1, L"Gamma angle is not correct for a scalene triangle.");
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
	TEST_CLASS(createSquare)
	{
	public:
		int InputArray[4][2] = {
			{8,2}, {2, 2}, {8, 6}, {2, 6}
		};
		RECTANGLE actual = createRectangle(InputArray);

		TEST_METHOD(Test001){

			Assert::AreEqual(actual.topLeftCorner.x, 2);

		}
		TEST_METHOD(Test002) {

			Assert::AreEqual(actual.topLeftCorner.y, 6);

		}

		TEST_METHOD(Test003) {

			Assert::AreEqual(actual.topRightCorner.x, 8);

		}
		TEST_METHOD(Test004) {

			Assert::AreEqual(actual.topRightCorner.y, 6);

		}

		TEST_METHOD(Test005) {

			Assert::AreEqual(actual.bottomLeftCorner.x, 2);

		}
		TEST_METHOD(Test006) {

			Assert::AreEqual(actual.bottomLeftCorner.y, 2);

		}

		TEST_METHOD(Test007) {

			Assert::AreEqual(actual.topRightCorner.x, 8);

		}
		TEST_METHOD(Test008) {

			Assert::AreEqual(actual.topRightCorner.y, 2);

		}
	};
}