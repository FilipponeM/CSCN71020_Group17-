// Group 17 Final Project 
// Triangle and Rectangle Solver 
// Fall 2022 - Software Implementation 
// Members: Matteo Filippone, Yao Wang, Ryan Tu
// Function definitions for rectangle solving

#include "rectangleSolver.h"


POINT createPoint(int x, int y, char id)
{
	POINT p;
	p.x = x;
	p.y = y;
	p.id = id;
	return p;
}

int findLargest(int* n, int size)
{
	if (size < 1)
	{
		fprintf(stderr, "Array size error");
		exit(1);
	}

	int max = n[0];
	for (int i = 1; i < size; i++)
	{
		if (max < n[i])
			max = n[i];
	}

	return max;
}

bool isRectangle(POINT* p)
{
	// find distances b/w points
	int distance[RECTANGLELINES]; 
	int count = 0;
	for (int i = 0; i < RECTANGLEPOINTS; i++)
	{
		for (int j = i + 1; j < RECTANGLEPOINTS; j++)
		{
			distance[count] = findDistanceUnit(p[i],p[j]);
			count++;
		}
	}

	// check is any distances are zero
	if (haveZero(distance, RECTANGLELINES) == true)
	{
		printf("This is not a 4 sided shape\n");
		return false;
	}
	// sort array of distances from largest to smallest
	sortInts(distance, RECTANGLELINES);
	
	// check if 2 longest distances are equal and size lengths are equal
	if (distance[0] == distance[1] && distance[2] == distance[3] && distance[4] == distance[5] && distance[2] != distance[4])
	{
		printf("This is a rectangle\n");

		return true;
	}
	else if (distance[0] == distance[1] && distance[2] == distance[3] && distance[4] == distance[5] && distance[2] == distance[4])
	{
		printf("This is a square\n");

		return true;
	}
	else
	{
		printf("This is not a rectangle\n");
		return false;
	}
		
}

int findDistanceUnit(POINT a, POINT b)
{
	int dx = b.x - a.x;
	int dy = b.y - a.y;
	int d = SQUARE(dx) + SQUARE(dy);
	return d;
}

void sortInts(int* n, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (n[i] < n[j])
			{
				temp = n[i];
				n[i] = n[j];
				n[j] = temp;
			}
		}
	}
}


bool haveZero(int* n, int size)
{
	for (int i = 0; i < 6; i++)
	{
		if (n[i] == 0)
			return true;
	}
	return false;
}


void getRectangleSides(POINT* p)
{
	int temp;
	int x, y;
	char id = 'A';

	for (int i = 0; i < RECTANGLEPOINTS; i++)
	{
		printf_s("Enter point %c of the rectangle: \n", id);
		printf_s("x: ");
		scanf_s("%d", &x);
		temp = getchar(); // to clear stdin
		printf_s("y: ");
		scanf_s("%d", &y);
		temp = getchar(); // to clear stdin
		p[i] = createPoint(x, y, id);
		id++;
	}
}

void sortRectanglePoints(POINT* p)
{

	// find distances b/w points
	int distance[RECTANGLELINES];
	int count = 0;
	for (int i = 0; i < RECTANGLEPOINTS; i++)
	{
		for (int j = i + 1; j < RECTANGLEPOINTS; j++)
		{
			distance[count] = findDistanceUnit(p[i], p[j]);
			count++;
		}
	}

	// find max distance
	int max = findLargest(distance, RECTANGLELINES);

	// sort points 
	POINT temp;
	for (int i = 0; i < RECTANGLEPOINTS - 2; i++)
	{
		if (findDistanceUnit(p[i], p[i + 1]) == max)
		{
			temp = p[i + 1];
			p[i+1]= p[i + 2];
			p[i + 2] = temp;
			continue;
		}
	}
}


void printRectangle(POINT* p)
{
	// print coordinates
	for (int i = 0; i < RECTANGLEPOINTS; i++)
	{
		printf("Point %c = (%d, %d)\n", p[i].id, p[i].x, p[i].y);
	}

	// print side lengths
	printf("Distance from point %c to %c is %lf\n", p[0].id, p[1].id, findSideLength(p[0], p[1]));
	printf("Distance from point %c to %c is %lf\n", p[1].id, p[2].id, findSideLength(p[1], p[2]));
	printf("Distance from point %c to %c is %lf\n", p[2].id, p[3].id, findSideLength(p[2], p[3]));
	printf("Distance from point %c to %c is %lf\n", p[3].id, p[0].id, findSideLength(p[3], p[0]));

	// print perimeter
	printf("The perimeter is: %lf\n", findPerimeter(p));

	// print area
	printf("The area is: %lf\n", findRectangleArea(p));
	

}

double findPerimeter(POINT* p)
{
	double perimeter;
	double s1, s2, s3, s4;
	s1 = findSideLength(p[0], p[1]);
	s2 = findSideLength(p[1], p[2]);
	s3 = findSideLength(p[2], p[3]);
	s4 = findSideLength(p[3], p[0]);

	perimeter = s1 + s2 + s3 + s4;
	return perimeter;
}

double findSideLength(POINT a, POINT b)
{
	double len = sqrt(findDistanceUnit(a, b));
	return len;
}

double findRectangleArea(POINT* p)
{
	double s1, s2, area;
	s1 = findSideLength(p[0], p[1]);
	s2 = findSideLength(p[1], p[2]);
	area = s1 * s2;
	return area;
}