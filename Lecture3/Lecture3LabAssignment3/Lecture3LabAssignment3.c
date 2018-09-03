/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803
Lab Assignment 3-3*/
#include <stdio.h>
#include <math.h>
int main() {
	int x1, x2, y1, y2;
	double distance;
	printf("Input two coordinates to find the distance between them in format x1 y1 x2 y2: ");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2); /* ( ) can't be used in older versions*/
	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	printf("The distance between two points is %.2lf\n", distance);



	return 0;
}