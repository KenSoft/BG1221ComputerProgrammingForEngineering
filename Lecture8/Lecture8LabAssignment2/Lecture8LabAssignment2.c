/* BG1221 Computer Programming For Engineering, 1/2018
By Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
Lab Assignment 8-2 Due 22th October 2018
This program written client account number, name, and balance to the file */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main() {
	FILE *client; 
	client = fopen("client.txt", "w");
	fclose(client);
	char name[30];
	int acNumber;
	double balance;
	while (!feof(stdin)) {
		client = fopen("client.txt", "a");
		printf(": ");
		scanf("%d %s %lf", &acNumber, &name, &balance);
		fprintf(client, "%-6d %-30s %-10.2lf\n", acNumber, name, balance);
		fclose(client);
	}
	

}
