/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework Assignment 3-3 Due 10th September 2018
This program find volume and weight of a steel cylinder based on entered radius and height */
#include <stdio.h>
#include <math.h>
int main() {
	int x1, x2, y1, y2, x;
	double m, c, y;
	printf("Input two coordinates and one x that you want to find the y value in format x1 y1 x2 y2 x: ");
	scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &x);

	m = (y2 - y1) / (x2 - x1);
	c = ((x2*y1 - x1*y2)) / (x2 - x1);
	y = (m*x) + c;

	printf("Slope = %.2lf y-Intercept = %.2lf y-value for given x (%d) = %.2lf\n", m, c, x, y);
	return 0;

}