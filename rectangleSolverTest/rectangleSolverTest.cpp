#include "pch.h"
#include "CppUnitTest.h"

extern "C" typedef struct point
{
	char id;
	int x;
	int y;
}POINT;

extern "C" int findLargest(int*, int);
extern "C" bool isRectangle(POINT , POINT , POINT , POINT );
extern "C" int findDistanceUnit(POINT, POINT);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rectangleSolverTest
{
	TEST_CLASS(rectangleSolverTest)
	{
	public:

		// findLargest tests
		TEST_METHOD(findLargestTest1)
		{
			int value[4] = { 3, 5, 6, 10 };
			int result = findLargest(value, 4);
			Assert::AreEqual(10, result);
		}
		TEST_METHOD(findLargestTest2)
		{
			int value[4] = { 8, 5, 6, 3 };
			int result = findLargest(value, 4);
			Assert::AreEqual(8, result);
		}

		// printRectangleTests
		TEST_METHOD(isRectangleTest1)
		{
			// horizaontal rectangle
			POINT a, b, c, d;
			a.x = 0;
			a.y = 1;
			b.x = 0;
			b.y = 3;
			c.x = 3;
			c.y = 1;
			d.x = 3;
			d.y = 3;
			bool result = isRectangle( a, b, c, d);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(isRectangleTest2)
		{
			// square
			POINT a, b, c, d;
			a.x = 0;
			a.y = 1;
			b.x = 0;
			b.y = 3;
			c.x = 2;
			c.y = 1;
			d.x = 2;
			d.y = 3;
			bool result = isRectangle(a, b, c, d);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(isRectangleTest3)
		{
			// verticle rectangle
			POINT a, b, c, d;
			a.x = 0;
			a.y = 1;
			b.x = 0;
			b.y = 6;
			c.x = 3;
			c.y = 1;
			d.x = 3;
			d.y = 6;
			bool result = isRectangle(a, b, c, d);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(isRectangleTest4)
		{
			// diagonal rectangle
			POINT a, b, c, d;
			a.x = 0;
			a.y = 1;
			b.x = -2;
			b.y = 3;
			c.x = 3;
			c.y = 4;
			d.x = 1;
			d.y = 6;
			bool result = isRectangle(a, b, c, d);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(isRectangleTest5)
		{
			// not rectangle
			POINT a, b, c, d;
			a.x = 0;
			a.y = 1;
			b.x = -2;
			b.y = 3;
			c.x = 3;
			c.y = 1;
			d.x = 3;
			d.y = 3;
			bool result = isRectangle(a, b, c, d);
			Assert::AreEqual(false, result);
		}
		TEST_METHOD(isRectangleTest6)
		{
			// not rectangle not a 4 sided shape
			POINT a, b, c, d;
			a.x = 0;
			a.y = 1;
			b.x = 0;
			b.y = 1;
			c.x = 3;
			c.y = 1;
			d.x = 3;
			d.y = 3;
			bool result = isRectangle(a, b, c, d);
			Assert::AreEqual(false, result);
		}
		// findDistanceUnit tests
		TEST_METHOD(findDistanceUnitTest1)
		{
			POINT a, b;
			a.x = 0;
			a.y = 2;
			b.x = 4;
			b.y = 6;
			int result = findDistanceUnit(a, b);
			Assert::AreEqual(32, result);
		}
		TEST_METHOD(findDistanceUnitTest2)
		{
			POINT a, b;
			a.x = 6;
			a.y = 2;
			b.x = 3;
			b.y = 4;
			int result = findDistanceUnit(a, b);
			Assert::AreEqual(13, result);
		}
		TEST_METHOD(findDistanceUnitTest3)
		{
			// zero distance
			POINT a, b;
			a.x = 0;
			a.y = 2;
			b.x = 0;
			b.y = 2;
			int result = findDistanceUnit(a, b);
			Assert::AreEqual(0, result);
		}
	};
}
