/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 6-1 Due 8th October 2018
This program calculate the average values for each of four experiments results*/
#include <stdio.h>
#include <math.h>

int main() {
	double sumResult = 0, average, result;
	int  experimentCount = 1, resultCount, resultCountDivisor;
	for (experimentCount; experimentCount <= 4; experimentCount++) {
		resultCount = 0;
		sumResult = 0;
		printf("Enter the number of test results for experiment #%d:", experimentCount);
		scanf("%d", &resultCount);
		resultCountDivisor = resultCount;
		printf("Enter %d test results for experiment #%d:\n", resultCount, experimentCount);
		for (resultCount; resultCount > 0; resultCount--) {
			result = 0;
			scanf("%lf", &result);
			sumResult = sumResult + result;
		}
		average = sumResult / (double)resultCountDivisor;
		printf("\nThe average for experiment #%d is %.2lf\n", experimentCount, average);

	}




	return 0;
}