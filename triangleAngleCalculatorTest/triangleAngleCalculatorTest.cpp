// Group 17 Final Project 
// Triangle and Rectangle Solver 
// Fall 2022 - Software Implementation 
// Members: Matteo Filippone, Yao Wang, Ryan Tu
// Test cases for triangle angle function - tests the angles and sum

#include "pch.h"
#include "CppUnitTest.h"

#include <cmath>

extern "C" double triangleAnglesCalculator(int* triangleSides, double* interiorAngles);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace triangleAngleCalculatorTest
{
	TEST_CLASS(triangleAngleCalculatorTest)
	{
	public:
		
		//EQUILATERAL TRIANGLE TEST 
		
		// Test sum of angles 
		TEST_METHOD(SumOfAnglesTest)
		{
			int triangleSides[] = { 3, 3, 3 };
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			double sumResult = 180.0;
			sumResult = triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(sumResult);

			Assert::AreEqual(180.0, rounded);
		}

		// Test angle 1 
		TEST_METHOD(FirstAngleTest)
		{
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			int triangleSides[] = { 3, 3, 3 };
			triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(triangleAngles[0]);
			Assert::AreEqual(60.0, rounded);
		}

		// Test angle 2 
		TEST_METHOD(SecondAngleTest)
		{
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			int triangleSides[] = { 3, 3, 3 };
			triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(triangleAngles[1]);
			Assert::AreEqual(60.0, rounded);
		}

		// Test angle 3 
		TEST_METHOD(ThirdAngleTest)
		{
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			int triangleSides[] = { 3, 3, 3 };
			triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(triangleAngles[2]);
			Assert::AreEqual(60.0, rounded);
		}


		//Scalene TRIANGLE TEST
 
		// Test sum of angles 
		TEST_METHOD(SumOfScaleneAngleTest)
		{
			int triangleSides[] = { 3, 4, 5 };
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			double sumResult = 180.0;
			sumResult = triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(sumResult);

			Assert::AreEqual(180.0, rounded);
		}

		// Test angle 1 
		TEST_METHOD(ScaleneAngleTest1)
		{
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			int triangleSides[] = { 3, 4, 5 };
			triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(triangleAngles[0]);
			Assert::AreEqual(90.0, rounded);
		}

		// Test angle 2 
		TEST_METHOD(ScaleneAngleTest2)
		{
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			int triangleSides[] = { 3, 4, 5 };
			triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(triangleAngles[1]);
			Assert::AreEqual(53.0, rounded);
		}

		// Test angle 3 
		TEST_METHOD(ScaleneAngleTest3)
		{
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			int triangleSides[] = { 3, 4, 5 };
			triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(triangleAngles[2]);
			Assert::AreEqual(37.0, rounded);
		}

		// Failing test cases [
		TEST_METHOD(FailingSumOfAngleTest)
		{
			int triangleSides[] = { 4, 4, 4};
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			double sumResult = 181.0;
			sumResult = triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(sumResult);

			Assert::AreEqual(181.0, rounded);
		}

		TEST_METHOD(FailingAngleTest1)
		{
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			int triangleSides[] = { 3, 4, 5 };
			triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(triangleAngles[2]);
			Assert::AreEqual(38.0, rounded);
		}

		TEST_METHOD(FailingAngleTest2)
		{
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			int triangleSides[] = { 4, 4, 4 };
			triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(triangleAngles[2]);
			Assert::AreEqual(61.0, rounded);
		}

		TEST_METHOD(FailingAngleTest3)
		{
			double triangleAngles[] = { 0.0, 0.0, 0.0 };
			int triangleSides[] = { 2, 3, 4 };
			triangleAnglesCalculator(triangleSides, triangleAngles);

			double rounded = round(triangleAngles[2]);
			Assert::AreEqual(30.0, rounded);
		}

	};
}
