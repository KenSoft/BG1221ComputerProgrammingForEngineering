/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 10-2 Due 19th November 2018
This program calculate the cylinder volume*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define PI 3.14159265358979323846
void calculatevolume(double r, double h, double *v);
void main() {
	double r = 0, h = 0, v;
	do {
		printf("Enter radius : ");
		scanf("%lf", &r);
		if (r != -1) {
			printf("Enter height : ");
			scanf("%lf", &h);
			calculatevolume(r, h, &v);
			printf("Volume of cylinder = %lf\n\n", v);

		}
	} while (r != -1);


}
void calculatevolume(double r, double h, double *v){
	*v = PI*r*r*h;
}
