// Function definitions for rectangle solving
// Yao Wang ywang0789

#include "rectangleSolver.h"

POINT createPoint(char c, int x, int y)
{
	POINT p;
	p.id = c;
	p.x = x;
	p.y = y;
	return p;
}

void printRectangle(POINT a, POINT b, POINT c, POINT d)
{
	// find distances b/w points
	int distance[6];
	distance[0] = findDistanceUnit(a, b);
	distance[1] = findDistanceUnit(a, c);
	distance[2] = findDistanceUnit(a, d);
	distance[3] = findDistanceUnit(b, c);
	distance[4] = findDistanceUnit(b, d);
	distance[5] = findDistanceUnit(c, d);
	// find max distance
	int max = findLargest(distance, 6);

	// print coordinates
	printf("Points %c = (%d, %d)\n", a.id, a.x, a.y);
	printf("Points %c = (%d, %d)\n", b.id, b.x, b.y);
	printf("Points %c = (%d, %d)\n", c.id, c.x, c.y);
	printf("Points %c = (%d, %d)\n", d.id, d.x, d.y);

	// print side lengths
	if (max != distance[0])
		printf("Distance from point %c to %c is %lf\n", a.id, b.id, sqrt(distance[0]));
	if (max != distance[1])
		printf("Distance from point %c to %c is %lf\n", a.id, c.id, sqrt(distance[1]));
	if (max != distance[2])
		printf("Distance from point %c to %c is %lf\n", a.id, d.id, sqrt(distance[2]));
	if (max != distance[3])
		printf("Distance from point %c to %c is %lf\n", b.id, c.id, sqrt(distance[3]));
	if (max != distance[4])
		printf("Distance from point %c to %c is %lf\n", b.id, d.id, sqrt(distance[4]));
	if (max != distance[5])
		printf("Distance from point %c to %c is %lf\n", c.id, d.id, sqrt(distance[5]));

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

bool isRectangle(POINT a, POINT b, POINT c, POINT d)
{
	// find distances b/w points
	int distance[6]; 
	distance[0] = findDistanceUnit(a, b);
	distance[1] = findDistanceUnit(a, c);
	distance[2] = findDistanceUnit(a, d);
	distance[3] = findDistanceUnit(b, c);
	distance[4] = findDistanceUnit(b, d);
	distance[5] = findDistanceUnit(c, d);

	// check is any distances are zero
	if (haveZero(distance, 6) == true)
	{
		printf("This is not a 4 sided shape\n");
		return false;
	}
	// sort array of distances from largest to smallest
	sortInts(distance, 6);
	
	// check if 2 longest distances are equal and size lengths are equal
	if (distance[0] == distance[1] && distance[2] == distance[3] && distance[4] == distance[5])
	{
		printf("This is a rectangle/square\n");

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