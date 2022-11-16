// Group 17 Final Project 
// Triangle and Rectangle Solver 
// Fall 2022 - Software Implementation 
// Members: Matteo Filippone, Yao Wang, Ryan Tu

#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "triangleAngleCalculator.h"

#define TRIANGLESIDES 3

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{

		case 1:
			printf_s("Triangle selected.\n");

			// get user input for 3 sides of the triangle 
			int triangleSides[TRIANGLESIDES] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			
			// returns the type of triangle 
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);

			// calculates the three angles inside of the triangle and returns sum of angles
			float triangleAngles[TRIANGLESIDES] = { 0, 0, 0 };
			float sumOfInteriorAngles = triangleAnglesCalculator(triangleSides, triangleAngles);
			printf_s("Interior angles of the triangle are %.3f, %.3f, %.3f and the sum is %.3f", triangleAngles[0], triangleAngles[1], triangleAngles[2], sumOfInteriorAngles);
			break;

		case 0:
			continueProgram = false;
			break;

		default:
			printf_s("Invalid value entered.\n");
			break;

		}
	}

	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number:");
	scanf_s("%d", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}
