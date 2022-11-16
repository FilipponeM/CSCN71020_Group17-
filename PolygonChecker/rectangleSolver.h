#pragma once
// Function declaration and description for rectangle solving
// Yao Wang ywang0789
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

// creates point struct from x y coordinates
POINT createPoint(char c,int x, int y);

// creates an array of 
POINT* sortPoints(POINT*);

// checks if 4 points given makes a rectangle
// compares all distances betweeen points:
// - no distances are 0
// - 2 longest distances (hypotenuse) are equal
// - side distances must not be equal
bool isRectangle(POINT*);

// returns the SQUARED distance b/w 2 points for comparison 
// formula for distance b/w 2 points: d = sqrt[(x2 - x1)^2 + (y2 - y1)^2]
// * d is squared to negate square root to avoid imprecision
int findDistanceUnit(POINT, POINT);

// sorts array of ints in descending order
void sortInts(int* n, int size);

// checks if there are any zeros in int array
bool haveZero(int* n, int size);