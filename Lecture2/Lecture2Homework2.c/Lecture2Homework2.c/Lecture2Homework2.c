/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework Assignment 2-2 Due 3th September 2018
This program find z value from given x (5.2) and y (3.5) using given formula */
#include <stdio.h>
#include <math.h>
int main() {
	double x = 5.2, y = 3.5;
	double z;
	z = (y*(pow(x, 2) - pow(y, 2))) / (pow(x, 2) + (3 * x*y));
	printf("z is equal to %f\n", z);
	return 0;
}