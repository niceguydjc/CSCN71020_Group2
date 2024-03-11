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
}