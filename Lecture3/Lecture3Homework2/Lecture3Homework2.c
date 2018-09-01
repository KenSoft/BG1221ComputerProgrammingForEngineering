/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework Assignment 3-2 Due 10th September 2018
This program find volume and weight of a steel cylinder based on entered radius and height */
#include <stdio.h>
#include <math.h>
#define PI 3.141593
#define DENSITY 0.284
int main() {
	double radius, height, volume, weight;
	printf("Enter the radius: ");
	scanf("%lf", &radius);
	printf("Enter the height: ");
	scanf("%lf", &height);
	volume = PI*pow(radius, 2)*height;
	weight = volume*DENSITY;
	printf("Volume is %.4lf. Weight is %.4lf.\n",volume,weight);

	return 0;
}