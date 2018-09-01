/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework Assignment 2-1 Due 3th September 2018
This program convert given value (30.5) in pounds to kg */

#include <stdio.h>
#include <math.h>
#define LBINKG 0.453592
int main() {
	double lb, kg;
	lb = 30.5;
	kg = lb*LBINKG;
	printf("The weight of %f", lb);
	printf(" pounds equal to %f", kg);
	printf(" kilograms.\n");


	return 0;
}