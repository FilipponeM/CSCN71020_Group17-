// Group 17 Final Project 
// Triangle and Rectangle Solver 
// Fall 2022 - Software Implementation 
// Members: Matteo Filippone, Yao Wang, Ryan Tu
// Main source file 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "triangleSolver.h"
#include "triangleAngleCalculator.h"
#include "rectangleSolver.h"

#define TRIANGLESIDES 3


int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();
		int shapeChoice = printShapeMenu();
		switch (shapeChoice)
		{
		case 2:
			printf_s("Rectangle selected.\n");

			POINT points [RECTANGLEPOINTS];

			// get user input for 4 points of rectangle
			getRectangleSides(points);

			// find if points given makes a rectangle
			if (isRectangle(points) != true) // not rectangle -> break
			{
				break;
			}
			else // is rectangle -> print it
			{
				sortRectanglePoints(points);
				printRectangle(points);
			}

			break;

		case 1:
			printf_s("Triangle selected.\n");

			// get user input for 3 sides of the triangle 
			int triangleSides[TRIANGLESIDES] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			
			// display error message if sum of two side lengths is less than or equal to third side length 
			// this means it is not a triangle
			if (triangleSidesPtr[0] + triangleSidesPtr[1] <= triangleSidesPtr[2] || triangleSidesPtr[0] + triangleSidesPtr[2] <= triangleSidesPtr[1]
				|| triangleSidesPtr[1] + triangleSidesPtr[2] <= triangleSidesPtr[0])
			{
				printf("Invalid side lengths, please try again.");
				break;
			}

			// returns the type of triangle 
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);

			char* compare = {"Not a triangle"};
			int value = (strcmp(result, compare));
			if (value != 0) {
				// calculates the three angles inside of the triangle and returns sum of angles
				double triangleAngles[TRIANGLESIDES] = { 0.0, 0.0, 0.0 };
				double sumOfInteriorAngles = triangleAnglesCalculator(triangleSides, triangleAngles);
				printf_s("Interior angles of the triangle are %.3lf, %.3f, %.3lf and the sum is %.3lf", triangleAngles[0], triangleAngles[1], triangleAngles[2], sumOfInteriorAngles);
				
			}
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
	printf_s("2. Rectangle\n");
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number:");
	scanf_s("%d", &shapeChoice);
	int temp = getchar(); // to clear stdin

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


