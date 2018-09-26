/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 4-2 Due 10th September 2018
This program calculate the factorial for a given positive interger. */
#include <stdio.h>
#include <math.h>
int main() {
	int n;
	double p;
	int i = 1;
	char r = 'Y';
	/*inputStr: */
	while (r == 'Y' || r == 'y') {
		printf("Input a number to calculate its factorial :");
		scanf("%d", &n);
		if (n == 0) {
			p = 1;
			printf("The factorial of %d is %lf.\n", n, p);
			r = 'N';
		}
		else if (n > 0) {
			i = 1; /* can't declare over already declared variable*/
			p = 1;
			while (i <= n) {
				p = p*i;
				i++;
			}
			printf("The factorial of %d is %lf.\n", n, p);
			r = 'N';
		}
		else {
			printf("Incorrect Input!\n");
		}
	}
	/* no goto*/


	return 0;
}