/* BG1221 Computer Programming For Engineering, 1/2018

Group Member:
1.  Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
2.	Thanyawee (Meimei) Chunhasawasdikul ID 6115300 Section 641

Project Due 26th November 2018
Just Another Car Parking Management System by KenSoftTH */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void configIO();
double parkingFeeRateSetup();
int parkingLotsNumberSetup();
int checkConfigExist();

int checkConfigExist() {
	//Check if config.txt exists or not
	FILE *file;
	file = fopen("config.txt", "r");
	if (file)
	{
		fclose(file);
		return 1;
	}
	else {
		return 0;
	}
}

void configIO() {
	int floor, parkingLotNumber[100];
	// This function read and write the config file
	// printf("%d", checkConfigExist());
	if (checkConfigExist()) {
		// If config file exist --> Not the first time
		printf("File Existed!\n");

	}
	else {
		// Config file not exist, so launch the setup process!
		printf("File not Exist!\n");
		parkingLotNumber[100] = parkingLotsNumberSetup();
		parkingFeeRateSetup();
	}
}

double parkingFeeRateSetup() {
	// This function receive parking fee rate from the user
	int rateCount, rate[10][2] = {0}, count, hour, displayLoop;
	printf("\n");
	printf("---Parking Fee Rate Setup Wizard---\n");
	printf("How many parking fee rate are there? (including free parking) :");
	scanf("%d", &rateCount);
	while (rateCount < 1 || rateCount>10) {
		printf("Incorrect Input!! How many parking fee rate are there? (including free parking) :");
		scanf("%d", &rateCount);
	}
	for (count = 0; count < rateCount; count++) {
		if (count == 0) {
			printf("How much time (in minutes) can people park without any fee?:");
			scanf("%d", &rate[0][0]);
			rate[0][1] = 0;
			printf("%-15s %-15s\n", "Time (Minutes)", "Fee per hour");
			printf("%-15d %-15d\n", rate[0][0], rate[0][1]);
		}
		else {
			printf("\nHow many hours from the start does this rate apply?:");
			scanf("%d", &hour);
			rate[count][0] = hour*60;
			printf("How much fee per hour?:");
			scanf("%d", &rate[count][1]);
			printf("%-15s %-15s\n", "Time (Minutes)", "Fee per hour");
			for (displayLoop=0; displayLoop <= count; displayLoop++) {
				printf("%-15d %-15d\n", rate[displayLoop][0], rate[displayLoop][1]);
			}
		}

	}
	return 0;

}

int parkingLotsNumberSetup() {
	// This function receive the number of parking lots and floor from the user
	int floor, count, parkingLotNumber[100];
	printf("\n---Parking Lots Number Setup Wizard---\n");
	printf("How many floor does the parking building has? :");
	scanf("%d", &floor);
	for (count = 1; count <= floor; count++) {
		printf("Enter number of parking lots for the floor number %d :", count);
		scanf("%d", &parkingLotNumber[count]);
	}	

	return parkingLotNumber[100];
}




void main() {
	configIO();

}