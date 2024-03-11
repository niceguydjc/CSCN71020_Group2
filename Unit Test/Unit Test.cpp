#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" float** createCoordinateArray(float** CoordinateArray);

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