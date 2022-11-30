// Test for triangle sides function 
// Will test the return of the triangle sides finder 
// Ryan Tu - November 2022

#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include <stdbool.h>

extern "C" char* analyzeTriangle(int side1, int side2, int side3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace triangleSolverTest
{
	TEST_CLASS(triangleSolverTest)
	{
	public:
		
		// Tests if scalene works  
		TEST_METHOD(ScaleneTest1)
		{
			int triangleSides[] = { 3, 4, 5 };
			char *tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Scalene triangle", *tringleType, false);
		}

		TEST_METHOD(ScaleneTest2)
		{
			int triangleSides[] = { 5, 1, 6 };
			char* tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Scalene triangle", *tringleType, false);


		}

		// Tests if isoceles works 
		TEST_METHOD(IsoscelesTest1)
		{
			int triangleSides[] = { 1, 1, 7 };
			char* tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Isosceles triangle", *tringleType, false);

		}
		TEST_METHOD(IsoscelesTest2)
		{
			int triangleSides[] = { 3, 2, 2 };
			char* tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Isosceles triangle", *tringleType, false);

		}

		TEST_METHOD(EquilateralTest1)
		{
			int triangleSides[] = { 2, 2, 2 };
			char* tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Equilateral triangle", *tringleType, false);

		}

		TEST_METHOD(EquilateralTest2)
		{
			int triangleSides[] = { 4, 4, 4 };
			char* tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Equilateral triangle", *tringleType, false);

		}

		TEST_METHOD(NotATriangleTest1) {

			int triangleSides[] = { 0, -2, 1 };
			char* tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Not a triangle", *tringleType, false);

		}

		TEST_METHOD(NotATriangleTest2) {

			int triangleSides[] = { 3, -12, -6};
			char* tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Not a triangle", *tringleType, false);

		}

		TEST_METHOD(FinalTest1) {

			int triangleSides[] = { 3, -3, 3 };
			char* tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Equilateral triangle", *tringleType, false);

		}

		TEST_METHOD(FinalTest2) {

			int triangleSides[] = { 3, 4, 5 };
			char* tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Isosceles triangle", *tringleType, false);

		}

		TEST_METHOD(FinalTest3) {

			int triangleSides[] = { 8, 12, 12};
			char* tringleType[25];

			*tringleType = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

			Assert::AreEqual("Scalene triangle", *tringleType, false);

		}


	};
}
