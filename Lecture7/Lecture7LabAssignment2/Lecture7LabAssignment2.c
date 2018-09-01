/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 7-2 Due 15th October 2018
This program roll the dice 6,000 times and show the results. */
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,random,one=0,two=0,three=0,four=0,five=0,six=0;
	for (i = 0; i < 6000; i++) {
		switch (rand() % 6) {
		case 0:
			one++;
			break;
		case 1:
			two++;
			break;
		case 2:
			three++;
			break;
		case 3:
			four++;
			break;
		case 4:
			five++;
			break;
		case 5:
			six++;
			break;
		}
	}
	printf("%-8s %-8s\n", "Face", "Frequency");
	printf("%-8d %-8d\n", 1, one);
	printf("%-8d %-8d\n", 2, two);
	printf("%-8d %-8d\n", 3, three);
	printf("%-8d %-8d\n", 4, four);
	printf("%-8d %-8d\n", 5, five);
	printf("%-8d %-8d\n", 6, six);
	return 0;
}