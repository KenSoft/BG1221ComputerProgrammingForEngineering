/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 8-1 Due 22th October 2018
This program take 2 arrays input and find the sum of it*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int first[2][3], second[2][3], sum[2][3];
	printf("Enter elements of the first array (2x3) :\nEnter row 1 :");
	scanf("%d %d %d", &first[0][0], &first[0][1], &first[0][2]);
	printf("Enter row 2 :");
	scanf("%d %d %d", &first[1][0], &first[1][1], &first[1][2]);
	printf("Enter elements of the second array (2x3) :\nEnter row 1 :");
	scanf("%d %d %d", &second[0][0], &second[0][1], &second[0][2]);
	printf("Enter row 2 :");
	scanf("%d %d %d", &second[1][0], &second[1][1], &second[1][2]);

	printf("%-12s %-12s %-12s", "First Array", "Second Array", "Result Array\n");
	printf("%-4d%-4d%-4d %-4d%-4d%-4d %-4d%-4d%-4d\n",
		first[0][0], first[0][1], first[0][2],
		second[0][0], second[0][1], second[0][2],
		first[0][0] + second[0][0], first[0][1] + second[0][1], first[0][2] + second[0][2]
	);
	printf("%-4d%-4d%-4d %-4d%-4d%-4d %-4d%-4d%-4d\n",
		first[1][0], first[1][1], first[1][2],
		second[1][0], second[1][1], second[1][2],
		first[1][0] + second[1][0], first[1][1] + second[1][1], first[1][2] + second[1][2]
	);




	return 0;
}