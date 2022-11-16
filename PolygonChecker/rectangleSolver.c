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

//POINT* sortPoints(POINT* p)
//{
//	//POINT* newp = (POINT*)malloc(sizeof(POINT) * 4);
//	POINT temp;
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = i + 1; j < 4; j++)
//		{
//			if (p[i].y < p[j].y)
//			{
//				temp = p[i];
//				p[i] = p[j];
//				p[j] = temp;
//			}
//			else if (p[i].y == p[j].y && p[i].x > p[j].x)
//			{
//				temp = p[i];
//				p[i] = p[j];
//				p[j] = temp;
//			}
//		}
//	}
//
//}

bool isRectangle(POINT* p)
{
	// find distances b/w points
	// ab, ac, ad, bc, bd, cd
	int d[6];
	int counter = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			d[counter] = findDistanceUnit(p[i], p[j]);
			counter++;
		}
	}

	// check is any distances are zero
	if (haveZero(d, 6) == true)
	{
		printf("This is not a 4 sided shape\n");
		return false;
	}

	// sort array of distances
	sortInts(d, 6);
	
	// check if 2 longest distances are equal and size lengths are not equal
	// rectangle or square
	if (d[0] == d[1] && d[2] != d[4])
	{
		printf("This is a rectangle\n");
		return true;
	}
	else if (d[0] == d[1]) 
	{
		printf("This is a square\n");
		return false;
	}
	else
		return false;
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