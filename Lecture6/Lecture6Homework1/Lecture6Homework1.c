/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 6-1 Due 15th October 2018
This program calculate value of z when x is between 5 and 10 and y is between 3 to 8 using the given formula. */
#include <stdio.h>
#include <math.h>
int main() {
	int x = 5, y = 3;
	double z = 0;
	printf("%-14c %-14c %-14c\n", 'x', 'y', 'z');
	for (x; x <= 10; x++) {
		y = 3;
		for (y; y <= 8; y++) {

			if (0 == (pow(x, 2) - (2 * x*y) + pow(y, 2))) {
				printf("%-14d %-14d %-14s\n", x,y,"Function is undefined");


			}
			else {
				z = (pow(x, 3) - (4 * x*pow(y, 3)) - (3 * pow(y, 2)) - x) / (pow(x, 2) - (2 * x*y) + pow(y, 2));
				printf("%-14d %-14d %-14lf\n", x, y, z);

			}
		}

	}
	return 0;
}