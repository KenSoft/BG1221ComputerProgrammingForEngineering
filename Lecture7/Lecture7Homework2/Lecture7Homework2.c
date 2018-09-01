/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Homework 7-2 Due 22th October 2018
This program calculate salespeople salary */
#include <stdio.h>
int main() {
	int counter[9] = { 0,0,0,0,0,0,0,0,0 }, input;
	double salary;
	do {
		printf("Enter employee gross sales (-1 to end) :");
		scanf("%d", &input);
		if (input == -1) {
			break;
		}
		salary = (input*0.09) + 200;
		printf("Employee Commission is $%.2lf\n",salary);
		if (salary >= 200 && salary < 300) {
			counter[0]++;
		}
		else if (salary >= 300 && salary < 400) {
			counter[1]++;
		}
		else if (salary >= 400 && salary < 500) {
			counter[2]++;
		}
		else if (salary >= 500 && salary < 600) {
			counter[3]++;
		}
		else if (salary >= 600 && salary < 700) {
			counter[4]++;
		}
		else if (salary >= 700 && salary < 800) {
			counter[5]++;
		}
		else if (salary >= 800 && salary < 900) {
			counter[6]++;
		}
		else if (salary >= 900 && salary < 1000) {
			counter[7]++;
		}
		else if (salary >= 1000) {
			counter[8]++;
		}

	} while (input != -1);
	printf("Number of employees in the salary range :\n");
	printf("$200 - $299 : %d\n", counter[0]);
	printf("$300 - $399 : %d\n", counter[1]);
	printf("$400 - $499 : %d\n", counter[2]);
	printf("$500 - $599 : %d\n", counter[3]);
	printf("$600 - $699 : %d\n", counter[4]);
	printf("$700 - $799 : %d\n", counter[5]);
	printf("$800 - $899 : %d\n", counter[6]);
	printf("$900 - $999 : %d\n", counter[7]);
	printf("Over $1000  : %d\n", counter[8]);
	return 0;
}