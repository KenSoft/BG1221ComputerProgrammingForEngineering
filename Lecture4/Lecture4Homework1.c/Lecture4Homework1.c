/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 4-1 Due 17th September 2018
This program determine the roots of a given quadratic equation */
#include <stdio.h>
#include <math.h>
#define TOLERANCE 1.0e-3
int main() {
	int a, b, c;
	double rootNature, x1, x2, y1, y2;
	printf("Input ax^2+bx+c in format a b c:");
	scanf("%d %d %d", &a, &b, &c);
	rootNature = pow(b, 2) - (4 * a*c);
	x1 = ((-b) + sqrt(pow(b, 2) - (4 * a*c))) / (2 * a);
	x2 = ((-b) - sqrt(pow(b, 2) - (4 * a*c))) / (2 * a);
	y1 = (a*pow(x1, 2)) + (b*x1) + c;
	y2 = (a*pow(x2, 2)) + (b*x2) + c;
	if (fabs(rootNature) <= TOLERANCE) {
		/* one double root*/
		printf("x1 = (%.4lf, %.4lf)\n", x1,y1);
		printf("x2 = (%.4lf, %.4lf)\n", x2,y2);
	}
	else if (rootNature > 0) {
		/* two real root*/
		printf("x1 = (%.4lf, %.4lf)\n", x1,y1);
		printf("x2 = (%.4lf, %.4lf)\n", x2,y2);
	}
	else if (rootNature < 0) {
		/* two imaginary root*/
		printf("No root found!\n");
	}



	return 0;
}