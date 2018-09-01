/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803
Lab Assignment 2-2*/

#include <stdio.h>
int main() {
	double C, F;
	F = 75.0;
	C = (F - 32)*(5.0/9.0);

	printf("%f", F);
	printf(" Degree Fahrenheit is equal to %f", C);
	printf(" Degree Celcius.\n");
	return 0;
}