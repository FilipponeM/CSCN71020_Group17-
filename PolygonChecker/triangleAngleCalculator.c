// Ryan Tu - November 2022
// Software Implementation group project
// Calculates angles inside of triangle and returns sum

#include <stdio.h>
#include <math.h>
#include "triangleAngleCalculator.h"

#define PI 3.14159265359


double triangleAnglesCalculator(int* triangleSides, double* interiorAngles)
{
	double s1 = triangleSides[0];
	double s2 = triangleSides[1];
	double s3 = triangleSides[2];

	// first angle 
	double divideBy = (2.0*s1*s2);
	double answerRadians = acos(((s1*s1) + (s2*s2) - (s3*s3)) / divideBy) ;
	interiorAngles[0] = ((answerRadians * 180.0) / PI);

	// second angle
	divideBy = (2.0 * s1 * s3);
	answerRadians = acos(((s1 * s1) + (s3 * s3) - (s2 * s2)) / divideBy);
	interiorAngles[1] = ((answerRadians * 180.0) / PI);

	// third angle
	divideBy = (2.0 * s2 * s3);
	answerRadians = acos(((s2 * s2) + (s3 * s3) - (s1 * s1)) / divideBy);
	interiorAngles[2] = ((answerRadians * 180.0) / PI);

	// calculating the sum
	double sumOfAngles = interiorAngles[0] + interiorAngles[1] + interiorAngles[2];

	return sumOfAngles;

}
