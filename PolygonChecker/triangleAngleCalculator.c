// Ryan Tu - November 2022 - software implementation group project
// Calculates angles inside of triangle 

#include <stdio.h>
#include <math.h>
#include "triangleAngleCalculator.h"

#define PI 3.14159265359


void triangleAnglesCalculator(int side1, int side2, int side3)
{
	// first angle C
	float s1;
	s1 = (float)side1;

	float s2;
	s2 = (float)side2;

	float s3;
	s3 = (float)side3;

	float ans = (2.0*side1*side2);
	float radians = acos(((s1*s1) + (s2*s2) - (s3*s3)) / ans) ;

	float degrees = ((radians * 180.0) / PI);

	printf_s("First angle is %.4f", degrees);
	
}
