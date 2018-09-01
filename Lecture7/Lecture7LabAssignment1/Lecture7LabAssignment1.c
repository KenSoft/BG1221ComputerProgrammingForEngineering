/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 7-1 Due 15th October 2018
This program plot a histogram based on elements of an array. */
#include <stdio.h>
int main() {
	int setOfInteger[10] = { 20,9,12,4,15,7,10,2,18,8 }, i, j;
	printf("%-12s %-12s %-12s\n", "Element", "Value", "Histogram");

	for (i = 0; i < sizeof(setOfInteger)/sizeof(int); i++) {
		printf("%-12d %-12d ", i, setOfInteger[i]);
		for (j = 0; j < setOfInteger[i]; j++) {
			printf("*");
		}
		printf("\n");
	}


	return 0;
}