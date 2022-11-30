#pragma once
// Group 17 Final Project 
// Triangle and Rectangle Solver 
// Fall 2022 - Software Implementation 
// Members: Matteo Filippone, Yao Wang, Ryan Tu
// Function declaration and description for rectangle solving
#define RECTANGLEPOINTS 4 // number of rectangle sides
#define RECTANGLELINES 6 // number of connecting points in a rectangle
#define SQUARE(n)	n*n
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>


// point struct for x and y coordinates
typedef struct point
{
	char id;
	int x;
	int y;
}POINT;

// creates a point struct
POINT createPoint(int x, int y, char id);

// checks if 4 points given makes a rectangle
// compares all distances betweeen points:
// - no distances are 0
// - 2 longest distances (hypotenuse) are equal
bool isRectangle(POINT*);

// returns the SQUARED distance b/w 2 points for comparison 
// formula for distance b/w 2 points: d = sqrt[(x2 - x1)^2 + (y2 - y1)^2]
// * d is squared to negate square root to avoid imprecision
int findDistanceUnit(POINT, POINT);

// sorts array of ints in descending order
void sortInts(int* n, int size);

// checks if there are any zeros in int array
bool haveZero(int* n, int size);

// find largest int value from array
int findLargest(int* n, int size);

// gets 4 points of rectangle from user input
void getRectangleSides(POINT*);

// sort points so points adjacent in array make rectangle sides instead of hypotenuse
// must verify if isRectangle() first
void sortRectanglePoints(POINT* p);

// prints rectangle side to screen
// must verify if isRectangle() first
void printRectangle(POINT*);

// returns perimeter of 4 points
// must be sorted
double findPerimeter(POINT* p);

// returns side len between 2 points 
// square root of distanceUnit()
double findSideLength(POINT, POINT);

// returns area of rectangle
// must verify points make rectangle 
// must be sorted points
double findRectangleArea(POINT* p);