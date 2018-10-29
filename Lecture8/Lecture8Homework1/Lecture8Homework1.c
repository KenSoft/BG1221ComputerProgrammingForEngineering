/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 8-1 Due 5th November 2018
This program selection sort an Array*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main() {
	int inputArray[10] = { 6,8,2,3,10,7,9,5,4,1 };
	int loopElements = 0, tempMin, address, loopSort = 0, tempHolder, printLoop = 0;
	for (loopSort; loopSort < 9; loopSort++) {
		loopElements = loopSort;
		for (loopElements; loopElements <= 9; loopElements++) {
			if (loopElements == loopSort) {
				tempMin = inputArray[loopSort];
				address = loopSort;
			}
			else if (tempMin > inputArray[loopElements]) {
				tempMin = inputArray[loopElements];
				address = loopElements;
			}

		}
		tempHolder = inputArray[loopSort];
		inputArray[loopSort] = inputArray[address];
		inputArray[address] = tempHolder;
		printf("Iteration %d\n", loopSort + 1);
		printLoop = 0;
		for (printLoop; printLoop <= 9; printLoop++) {
			printf("%d\n", inputArray[printLoop]);
		}
		printf("\n");
	}
	printf("Final Result\n");
	printLoop = 0;
	for (printLoop; printLoop <= 9; printLoop++) {
		printf("%d\n", inputArray[printLoop]);
	}
	printf("\n");
}