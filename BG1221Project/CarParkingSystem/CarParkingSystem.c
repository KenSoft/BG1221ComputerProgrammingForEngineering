/* BG1221 Computer Programming For Engineering, 1/2018

Group Member:
1.  Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
2.	Thanyawee (Meimei) Chunhasawasdikul ID 6115300 Section 641

Project Due 26th November 2018
Just Another Car Parking Management System by KenSoftTH */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#include <time.h>
// Function Definition
void configIO();
int parkingFeeRateSetup();
int parkingLotsNumberSetup();
int menu();
int carIn();
int carOut();
int displayParkingLots();
int printReport();
int checkConfigExist();
int getTime();
int parkingRate[11][2] = { {0} };
char licensePlate[1000][3];
int parkingLotRead[100];
int customerArray[1000][14] = { { 0 } };
int customerCount = 0;
int count = 0, countRate = 0;
// Functions
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
int getTime() {
	//int time[6] = { 0,0,0,0,0,0 };
	int hours, minutes, seconds, day, month, year;
	int timeArray[6] = {0};

	// time_t is arithmetic time type
	time_t now;

	// Obtain current time
	// time() returns the current time of the system as a time_t value
	time(&now);

	// Convert to local time format and print to stdout
	//printf("Today is : %s", ctime(&now));

	// localtime converts a time_t value to calendar time and returns a pointer
	// to a tm structure with its members filled with the corresponding values
	struct tm *local = localtime(&now);

	timeArray[3] = hours = local->tm_hour;			// get hours since midnight	(0-23)
	timeArray[4] = minutes = local->tm_min;			// get minutes passed after the hour (0-59)
	timeArray[5] = seconds = local->tm_sec;			// get seconds passed after the minute (0-59)

	timeArray[2] = day = local->tm_mday;			// get day of month (1 to 31)
	timeArray[1] = month = local->tm_mon + 1;		// get month of year (0 to 11)
	timeArray[0] = year = local->tm_year + 1900;	// get year since 1900
									// print local time
	// print current date

	return timeArray;
}
void configIO() {
	int floor;
	int *parkingLotNumber;

	// This function read and write the config file
	// printf("%d", checkConfigExist());
	if (checkConfigExist()) {
		// If config file exist --> Not the first time
		int count = 0,placeholder;
		printf("File Existed!\n");
		FILE *file;
		file = fopen("config.txt", "r");

		for (count = 0; count < 100; count++) {
			if (count == 0) {
				fscanf(file, "Floor=%d\n", &parkingLotRead[0]);
				printf("%d floors\n", parkingLotRead[0]);
			}
			else {
				fscanf(file, "Floor %d=%d\n", &placeholder, &parkingLotRead[count]);
				printf("Read line %d value %d\n", count + 1, parkingLotRead[count]);
			}
		}
		fscanf(file, "Rate=%d\n", &parkingRate[10][0]);
		printf("%d rates\n", parkingRate[10][0]);
		 for (countRate = 0; countRate < 10; countRate++) {
		 		fscanf(file, "R %d %d\n", &parkingRate[countRate][0], &parkingRate[countRate][1]);
		 		printf("Read line %d value %d minutes %d baht per hour\n", countRate + 1, parkingRate[countRate][0], parkingRate[countRate][1]);
		 
		 }
		fclose(file);
	}
	else {
		// Config file not exist, so launch the setup process!
		int countTransfer = 0;
		printf("File not Exist!\n");
		parkingLotNumber = parkingLotsNumberSetup();
		parkingFeeRateSetup(parkingRate);

		FILE *file;
		file = fopen("config.txt", "w");
		fprintf(file, "Floor=%d\n", parkingLotNumber[0]);
		for (count = 1; count <= 99; count++) {
			fprintf(file,"Floor %d=%d\n",count, parkingLotNumber[count]);
		}
		fprintf(file, "Rate=%d\n", parkingRate[10][0]);
		for (countRate = 0; countRate <= 9; countRate++) {
			fprintf(file, "R %d %d\n", parkingRate[countRate][0], parkingRate[countRate][1]);
		}
		fclose(file);
		for (countTransfer = 0; countTransfer < 100; countTransfer++) {
			parkingLotRead[countTransfer] = parkingLotNumber[countTransfer];
		}
		printf("\nSetup Completed!\n");
	}
}
int parkingFeeRateSetup(int rate[11][2]) {
	// This function receive parking fee rate from the user
	int rateCount, count, hour, displayLoop;
	printf("\n");
	printf("---Parking Fee Rate Setup Wizard---\n");
	printf("How many parking fee rate are there? (including free parking) :");
	scanf("%d", &rateCount);
	rate[10][0] = rateCount;
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
	int floor, count;
	static int parkingLotNumber[100];
	printf("\n---Parking Lots Number Setup Wizard---\n");
	printf("How many floor does the parking building has? :");
	scanf("%d", &floor);
	while (floor > 99 || floor < 1) {
		printf("Invalid Input!!! How many floor does the parking building has? :");
		scanf("%d", &floor);
	}
	for (count = 1; count <= floor; count++) {
		printf("Enter number of parking lots for the floor number %d :", count);
		scanf("%d", &parkingLotNumber[count]);
	}	
	parkingLotNumber[0] = floor;

	return parkingLotNumber;
}
int menu() {
	int selection;
	printf("========================================Just another parking system by KenSoftTH========================================\n");
	printf("Please select from the menu below\n");
	printf("[1] Car In\n");
	printf("[2] Car Out\n");
	printf("[3] Display Parking Lots\n");
	printf("[4] End the Day and Print Parking Report (Exit)\n");
	printf(":: ");
	scanf("%d", &selection);
	while (selection < 1 || selection > 4) {
		printf("Invalid Selection!!\n");
		printf(":: ");
		scanf("%d", &selection);
	}
	return selection;
}

int carIn() {
	int address, plate;
	int *time;
	system("cls");
	for (address = 0; address < 1000; address++) {
		if (customerArray[address][0] == 0) {
			break;
		}

	}
	printf("address = %d\n", address);
	printf("Enter the car license plate :");
	scanf("%s %d",&licensePlate[address] , &plate);
	while (plate < 1 || plate>9999) {
		printf("Invalid Input!!\n");
		printf("Enter the car license plate :");
		scanf("%s %d", &licensePlate[address], &plate);
	}
	printf("%d\n", parkingLotRead[0]);
	printf("The License Plate is %s%d\n", licensePlate[address], plate);
	time = getTime();
	customerArray[address][1] = time[0];
	customerArray[address][2] = time[1];
	customerArray[address][3] = time[2];
	customerArray[address][4] = time[3];
	customerArray[address][5] = time[4];
	customerArray[address][6] = time[5];
	printf("Time is %d/%d/%d %d:%d:%d\n", customerArray[address][3], customerArray[address][2], customerArray[address][1], customerArray[address][4], customerArray[address][5], customerArray[address][6]);
	printf("Data Saved!\n");
	system("pause");
	system("cls");
	return 0;
}


void main() {
	int *time;
	int selection = 0;
	time = getTime();
	
	configIO();
	system("cls");
	while (selection != 4) {
		selection = menu();
		switch (selection) {
		case 1:
			carIn();
			break;
		default:
			break;
		}
	}
}