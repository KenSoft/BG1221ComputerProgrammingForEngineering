/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803
Lab Assignment 3-2*/
#include <stdio.h>
#include <math.h>
#define PI 3.141593
int main() {
	double diameter, radius, circumference, area;
	printf("Input circle radius: ");
	scanf("%lf", &radius);
	circumference = 2 * PI*radius;
	diameter = 2 * radius;
	area = PI*pow(radius, 2.0);
	printf("Radius = %.4lf Area = %.4lf Diameter = %.4lf Circumference = %.4lf\n", radius, area, diameter, circumference);


	return 0;
}