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


extern "C" struct rectangle;
extern "C" RECTANGLE createRectangle;

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
namespace rectangle
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
			expected.topLeftCorner.x = 6;

			int InputArray[4][2] = {
				{8,2}, {2, 2}, {8, 6}, {2, 6}
			};

			RECTANGLE actual = createRectangle(InputArray);

			Assert::AreEqual(expected, actual);//might not work, may have to check each member individually

		}
	};
}