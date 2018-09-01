/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 6-2 Due 8th October 2018
This program determine and count disk drive manufacturer. */
#include <stdio.h>
int main() {
	printf("Enter -1 for manufacturer’s code to END the program\n");
	int input, threeM = 0, sony = 0, maxell = 0, verbatim = 0;
	do {
		printf("Enter the manufacturer’s code :");
		scanf("%d", &input);
		switch (input) {
		case 1:
			threeM++;
			printf("It is from 3M Corporation.\n");
			break;
		case 2:
			maxell++;
			printf("It is from Maxell Corporation.\n");
			break;
		case 3:
			sony++;
			printf("It is from Spny Corporation.\n");
			break;
		case 4:
			verbatim++;
			printf("It is from Verbatim Corporation.\n");
			break;
		case -1:
			break;
			break;
		default:
			printf("Invalid Code Entered ! Enter new manufacturer’s code !\n");
		}
	} while (input != -1);
	printf("Totals of each disk drive manufacturer are :\n3M Corporation : %d\nMaxell Corporation : %d\nSony Corporation : %d\nVerbatim Corporation : %d\n", threeM, maxell, sony, verbatim);

	return 0;
}