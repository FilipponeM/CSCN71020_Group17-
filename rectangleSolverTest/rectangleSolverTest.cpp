#include "pch.h"
#include "CppUnitTest.h"

extern "C" typedef struct point
{
	char id;
	int x;
	int y;
}POINT;

extern "C" int findLargest(int*, int);
extern "C" bool isRectangle(POINT*);
extern "C" int findDistanceUnit(POINT, POINT);
extern "C" POINT createPoint(int x, int y, char id);
extern "C" void sortInts(int* n, int size);
extern "C" bool haveZero(int* n, int size);
extern "C" void sortRectanglePoints(POINT* p);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rectangleSolverTest
{
	TEST_CLASS(rectangleSolverTest)
	{
	public:

		// findLargest tests
		TEST_METHOD(findLargest_Test1)
		{
			int value[4] = { 3, 5, 6, 10 };
			int result = findLargest(value, 4);
			Assert::AreEqual(10, result);
		}
		TEST_METHOD(findLargest_Test2)
		{
			int value[4] = { 8, 5, 6, 3 };
			int result = findLargest(value, 4);
			Assert::AreEqual(8, result);
		}

		// printRectangleTests
		TEST_METHOD(isRectangle_Test1)
		{
			// horizaontal rectangle
			POINT p[4];
			p[0].x = 0;
			p[0].y = 1;
			p[1].x = 0;
			p[1].y = 3;
			p[2].x = 3;
			p[2].y = 1;
			p[3].x = 3;
			p[3].y = 3;

			bool result = isRectangle(p);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(isRectangle_Test2)
		{
			// square
			POINT p[4];
			p[0].x = 0;
			p[0].y = 1;
			p[1].x = 0;
			p[1].y = 3;
			p[2].x = 2;
			p[2].y = 1;
			p[3].x = 2;
			p[3].y = 3;

			bool result = isRectangle(p);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(isRectangle_Test3)
		{
			// verticle rectangle
			POINT p[4];
			p[0].x = 0;
			p[0].y = 1;
			p[1].x = 0;
			p[1].y = 6;
			p[2].x = 3;
			p[2].y = 1;
			p[3].x = 3;
			p[3].y = 6;

			bool result = isRectangle(p);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(isRectangle_Test4)
		{
			// diagonal rectangle
			POINT p[4];
			p[0].x = 0;
			p[0].y = 1;
			p[1].x = -2;
			p[1].y = 3;
			p[2].x = 3;
			p[2].y = 4;
			p[3].x = 1;
			p[3].y = 6;

			bool result = isRectangle(p);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(isRectangle_Test5)
		{
			// not rectangle
			POINT p[4];
			p[0].x = 0;
			p[0].y = 1;
			p[1].x = -2;
			p[1].y = 3;
			p[2].x = 3;
			p[2].y = 1;
			p[3].x = 3;
			p[3].y = 3;

			bool result = isRectangle(p);
			Assert::AreEqual(false, result);
		}
		TEST_METHOD(isRectangle_Test6)
		{
			// not rectangle not a 4 sided shape
			POINT p[4];
			p[0].x = 0;
			p[0].y = 1;
			p[1].x = 0;
			p[1].y = 1;
			p[2].x = 3;
			p[2].y = 1;
			p[3].x = 3;
			p[3].y = 3;

			bool result = isRectangle(p);
			Assert::AreEqual(false, result);
		}
		// findDistanceUnit tests
		TEST_METHOD(findDistanceUnit_Test1)
		{
			POINT a, b;
			a.x = 0;
			a.y = 2;
			b.x = 4;
			b.y = 6;
			int result = findDistanceUnit(a, b);
			Assert::AreEqual(32, result);
		}
		TEST_METHOD(findDistanceUnit_Test2)
		{
			POINT a, b;
			a.x = 6;
			a.y = 2;
			b.x = 3;
			b.y = 4;
			int result = findDistanceUnit(a, b);
			Assert::AreEqual(13, result);
		}
		TEST_METHOD(findDistanceUnit_Test3)
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
		// createPoint() tests
		TEST_METHOD(createPoint_Test1)
		{
			POINT result = createPoint(3, 2, 'A');
			Assert::AreEqual(3, result.x);
			Assert::AreEqual(2, result.y);
			Assert::AreEqual('A', result.id);
		}
		TEST_METHOD(createPoint_Test2)
		{
			POINT result = createPoint(-3, 0, 'D');
			Assert::AreEqual(-3, result.x);
			Assert::AreEqual(0, result.y);
			Assert::AreEqual('D', result.id);
		}
		// sortInts() tests
		TEST_METHOD(sortInts_Test1)
		{
			int value[6] = {7, 5, 0, 7, -13, 2 };
			sortInts(value, 10);
			int result[6] = {7, 7, 5, 2, 0, -13 };
			Assert::AreEqual(value[0], result[0]);
			Assert::AreEqual(value[1], result[1]);
			Assert::AreEqual(value[2], result[2]);
			Assert::AreEqual(value[3], result[3]);
			Assert::AreEqual(value[4], result[4]);
			Assert::AreEqual(value[5], result[5]);
		}
		TEST_METHOD(sortInts_Test2)
		{
			int value[6] = { 0, 2, 0, -13, -13, 2 };
			sortInts(value, 10);
			int result[6] = { 2, 2, 0, 0, -13, -13 };
			Assert::AreEqual(value[0], result[0]);
			Assert::AreEqual(value[1], result[1]);
			Assert::AreEqual(value[2], result[2]);
			Assert::AreEqual(value[3], result[3]);
			Assert::AreEqual(value[4], result[4]);
			Assert::AreEqual(value[5], result[5]);
		}
		// haveZero() tests
		TEST_METHOD(haveZero_Test1)
		{
			int value[6] = { 7, 5, 0, 7, -13, 2 };
			bool result = haveZero(value, 6);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(haveZero_Test2)
		{
			int value[6] = { 7, 2, 4, 7, -13, 2 };
			bool result = haveZero(value, 6);
			Assert::AreEqual(false, result);
		}
		// sortRectanglePoints tests
		TEST_METHOD(sortRectanglePoints_Test1)
		{
			// no sort needed
			POINT p[4];
			p[0].x = 0;
			p[0].y = 1;
			p[1].x = 3;
			p[1].y = 1;
			p[2].x = 3;
			p[2].y = 6;
			p[3].x = 0;
			p[3].y = 6;

			sortRectanglePoints(p);
			
			POINT expected[4];
			expected[0].x = 0;
			expected[0].y = 1;
			expected[1].x = 3;
			expected[1].y = 1;
			expected[2].x = 3;
			expected[2].y = 6;
			expected[3].x = 0;
			expected[3].y = 6;

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(expected[i].x, p[i].x);
				Assert::AreEqual(expected[i].y, p[i].y);
			}
		}
		TEST_METHOD(sortRectanglePoints_Test2)
		{
			POINT p[4];
			p[0].x = 0;
			p[0].y = 1;
			p[1].x = -2;
			p[1].y = 3;
			p[2].x = 3;
			p[2].y = 4;
			p[3].x = 1;
			p[3].y = 6;
			sortRectanglePoints(p);

			POINT expected[4];
			expected[0].x = 0;
			expected[0].y = 1;
			expected[1].x = -2;
			expected[1].y = 3;
			expected[2].x = 1;
			expected[2].y = 6;
			expected[3].x = 3;
			expected[3].y = 4;

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(expected[i].x, p[i].x);
				Assert::AreEqual(expected[i].y, p[i].y);
			}
		}
		TEST_METHOD(sortRectanglePoints_Test3)
		{
			// square
			POINT p[4];
			p[0].x = 0;
			p[0].y = 1;
			p[1].x = 2;
			p[1].y = 3;
			p[2].x = 0;
			p[2].y = 3;
			p[3].x = 2;
			p[3].y = 1;

			sortRectanglePoints(p);

			POINT expected[4];
			expected[0].x = 0;
			expected[0].y = 1;
			expected[1].x = 0;
			expected[1].y = 3;
			expected[2].x = 2;
			expected[2].y = 3;
			expected[3].x = 2;
			expected[3].y = 1;

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(expected[i].x, p[i].x);
				Assert::AreEqual(expected[i].y, p[i].y);
			}
		}
		TEST_METHOD(sortRectanglePoints_Test4)
		{
			// diagonal rectangle
			POINT p[4];
			p[0].x = 0;
			p[0].y = 1;
			p[1].x = 1;
			p[1].y = 6;
			p[2].x = 3;
			p[2].y = 4;
			p[3].x = -2;
			p[3].y = 3;

			sortRectanglePoints(p);

			POINT expected[4];
			expected[0].x = 0;
			expected[0].y = 1;
			expected[1].x = 3;
			expected[1].y = 4;
			expected[2].x = 1;
			expected[2].y = 6;
			expected[3].x = -2;
			expected[3].y = 3;

			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(expected[i].x, p[i].x);
				Assert::AreEqual(expected[i].y, p[i].y);
			}
		}
	};
}
