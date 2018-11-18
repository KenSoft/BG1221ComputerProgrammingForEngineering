/* BG1221 Computer Programming For Engineering, 1/2018

Group Member:
1. Kasidis (Ken) Arunruangsirilert ID 6116803 Section 641
2. Thanyawee (Meimei) Chunhasawasdikul ID 6115300 Section 641

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
void listCar();
void changeSpace();
void changeFee();
void writeLog();
// Global Variable
int parkingRate[11][2] = { {0} };
char licensePlate[1000][3];
int parkingLotRead[100];
int parkingLotLeft[100];
int customerArray[1000][15] = { { 0 } };
int customerCount = 0;
int count = 0, countRate = 0;
int currentCarCount = 0;
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
	printf("[3] Display/Change Parking Lots\n");
	printf("[4] Display/Change Parking Fee\n");
	printf("[5] End the Day and Print the Report (Exit)\n");
	printf(":: ");
	scanf("%d", &selection);
	while (selection < 1 || selection > 5) {
		printf("Invalid Selection!!\n");
		printf(":: ");
		scanf("%d", &selection);
	}
	return selection;
}
int carIn() {
	int address;
	int *time;
	system("cls");
	printf("=========================================================Car In=========================================================\n");
	for (address = 0; address < 1000; address++) {
		if (customerArray[address][0] == 0) {
			break;
		}

	}
	//printf("Address = %d\n", address);
	printf("There are %d floor(s) existed.\n", parkingLotRead[0]);
	printf("Enter the car license plate :");
	scanf("%s %d",&licensePlate[address] , &customerArray[address][0]);
	while (customerArray[address][0] < 1 || customerArray[address][0]>9999) {
		printf("Invalid Input!!\n");
		printf("Enter the car license plate :");
		scanf("%s %d", &licensePlate[address], &customerArray[address][0]);
	}
	printf("Enter the floor : ");
	scanf(" %d", &customerArray[address][13]);
	while (customerArray[address][13] < 1 || customerArray[address][13] > parkingLotRead[0] || parkingLotLeft[customerArray[address][13]] == 0) {
		if (customerArray[address][13] < 1 || customerArray[address][13] > parkingLotRead[0]) {
			printf("Invalid Input!!\n");
		}
		else if (parkingLotLeft[customerArray[address][13]] == 0) {
			printf("The selected floor is full, please select a new one!!\n");
		}
		printf("Enter the floor : ");
		scanf(" %d", &customerArray[address][13]);
	}
	parkingLotLeft[customerArray[address][13]]--;
	printf("The License Plate is %s%d\n", licensePlate[address], customerArray[address][0]);
	time = getTime();
	customerArray[address][1] = time[0];
	customerArray[address][2] = time[1];
	customerArray[address][3] = time[2];
	customerArray[address][4] = time[3];
	customerArray[address][5] = time[4];
	customerArray[address][6] = time[5];
	printf("Time is %d/%d/%d %02d:%02d:%02d\n", customerArray[address][3], customerArray[address][2], customerArray[address][1], customerArray[address][4], customerArray[address][5], customerArray[address][6]);
	printf("Floor parked is %d\n", customerArray[address][13]);
	printf("Data Saved!\n");
	currentCarCount++;
	system("pause");
	system("cls");
	return 0;
}
void listCar() {
	int floor,address;
	system("cls");
	printf("Enter floor : ");
	scanf(" %d", &floor);
	printf("\n\n====================================================Car in Floor No. %d=================================================\n", floor);
	for (address = 0; address < 1000; address++) {
		if (customerArray[address][7] > 2000) {
			
		}
		else if (customerArray[address][13] == floor) {
			printf("%c%c%c%d\n",  licensePlate[address][0], licensePlate[address][1], licensePlate[address][2], customerArray[address][0]);
		}

	}
	system("pause");
	system("cls");
}
void changeSpace() {
	char confirm;
	int *parkingLotNumber;
	int countTransfer;
	system("cls");
	printf("[Warning] All car data will be in this process, continue? (Y/N) : ");
	scanf(" %c", &confirm);
	if (confirm == 'Y') {
		int i, j;
		for (i = 0; i < 1000; i++) {
			for (j = 0; j < 15; j++) {
				customerArray[i][j] = 0;
			}
		}
		
		customerCount = 0;
		for (i = 0; i < 1000; i++) {
			for (j = 0; j < 3; j++) {
				licensePlate[i][j]='\0';
			}
		}
		for (i = 0; i < 100; i++) {
			parkingLotRead[i]=0;
			parkingLotLeft[i]=0;
		}
		parkingLotNumber=parkingLotsNumberSetup();
		for (countTransfer = 0; countTransfer < 100; countTransfer++) {
			parkingLotRead[countTransfer] = parkingLotNumber[countTransfer];
		}
		for (countTransfer = 0; countTransfer < 100; countTransfer++) {
			parkingLotLeft[countTransfer] = parkingLotRead[countTransfer];
		}
		FILE *file;
		file = fopen("config.txt", "w");
		fprintf(file, "Floor=%d\n", parkingLotNumber[0]);
		for (count = 1; count <= 99; count++) {
			fprintf(file, "Floor %d=%d\n", count, parkingLotNumber[count]);
		}
		fprintf(file, "Rate=%d\n", parkingRate[10][0]);
		for (countRate = 0; countRate <= 9; countRate++) {
			fprintf(file, "R %d %d\n", parkingRate[countRate][0], parkingRate[countRate][1]);
		}
		fclose(file);

		printf("Floor Updated!\n");
		system("pause");
	}
	system("cls");
}
void changeFee() {
	char confirm;
	int i, j, displayLoop, selection=0;
	system("cls");
	while (selection != 2) {
		system("cls");
		printf("%-15s %-15s\n", "Time (Minutes)", "Fee per hour");
		for (displayLoop = 0; displayLoop < parkingRate[10][0]; displayLoop++) {
			printf("%-15d %-15d\n", parkingRate[displayLoop][0], parkingRate[displayLoop][1]);
		}
	

		printf("==========================================================Menu==========================================================\n");
		printf("[1] Change Parking Fee\n");
		printf("[2] Back to main menu\n");
		printf(":: ");
		scanf("%d", &selection);
		while (selection < 1 || selection > 3) {
			printf("Invalid Selection!!\n");
			printf(":: ");
			scanf("%d", &selection);
		}
		system("cls");
		switch (selection) {
		case 1:
			printf("[Warning] All parking rates will be in this process, continue? (Y/N) : ");
			scanf(" %c", &confirm);
			if (confirm == 'Y') {

				for (i = 0; i < 1000; i++) {
					for (j = 0; j < 15; j++) {
						parkingRate[i][j] = 0;
					}
				}
				parkingFeeRateSetup(parkingRate);
				FILE *file;
				file = fopen("config.txt", "w");
				fprintf(file, "Floor=%d\n", parkingLotRead[0]);
				for (count = 1; count <= 99; count++) {
					fprintf(file, "Floor %d=%d\n", count, parkingLotRead[count]);
				}
				fprintf(file, "Rate=%d\n", parkingRate[10][0]);
				for (countRate = 0; countRate <= 9; countRate++) {
					fprintf(file, "R %d %d\n", parkingRate[countRate][0], parkingRate[countRate][1]);
				}
				fclose(file);

				printf("Rate Updated!\n");
				system("pause");
				system("cls");

			}
			break;
		default:
			system("cls");
			break;
		}
	}
	
	

	system("cls");
}
int displayParkingLots() {
	int countPrint = 1;
	int selection = 0;


	while (selection != 3) {
		system("cls");
		printf("=====================================================Parking Lots Left==================================================\n");
		printf("%-10s %-10s %-10s\n", "Floor", "Capacity", "Left");

		for (countPrint = 1; countPrint <= parkingLotRead[0]; countPrint++) {
			printf("%-10d %-10d %-10d\n", countPrint, parkingLotRead[countPrint], parkingLotLeft[countPrint]);
		}
		printf("==========================================================Menu==========================================================\n");
		printf("[1] List car in specific floor\n");
		printf("[2] Change the parking space\n");
		printf("[3] Back to main menu\n");
		printf(":: ");
		scanf("%d", &selection);
		while (selection < 1 || selection > 3) {
			printf("Invalid Selection!!\n");
			printf(":: ");
			scanf("%d", &selection);
		}
		switch (selection) {
		case 1:
			listCar();
			break;
		case 2:
			changeSpace();
			break;
		default:
			break;
		}
	}
	system("cls");
	return 0;

}
int carOut() {
	int plateNumber, address;
	int *time;
	int hrs=0;
	int diffHours, diffMinutes, diffSeconds;
	int countAddLotFree;
	int loop = 0, rateAddress;
	int rateCalCount;
	int totalSecondParked;
	int fee = 0, currentRate;
	char plateLetter[4];
	system("cls");
	printf("=========================================================Car Out========================================================\n");
	if (currentCarCount != 0) {
		printf("Enter the car license plate :");
		scanf("%s %d", &plateLetter, &plateNumber);
		for (address = 0; address < 1001; address++) {
			// printf("%d %d", plateNumber, customerArray[address][0]);
			//printf("%c %c %c %c %c %c", plateLetter[0], plateLetter[1], plateLetter[2], licensePlate[address][0], licensePlate[address][1], licensePlate[address][2]);
			if (plateLetter[0] == licensePlate[address][0] && plateLetter[1] == licensePlate[address][1] && plateLetter[2] == licensePlate[address][2] && plateNumber == customerArray[address][0]) {
				break;
			}
		}
		while (address == 1001) {
			printf("Not Found!! Please Re-enter\n");
			printf("Enter the car license plate :");
			scanf("%s %d", &plateLetter, &plateNumber);
			for (address = 0; address < 1001; address++) {
				if (plateLetter[0] == licensePlate[address][0] && plateLetter[1] == licensePlate[address][1] && plateLetter[2] == licensePlate[address][2] && plateNumber == customerArray[address][0]) {
					break;
				}
			}
		}
		printf("Address = %d\n", address);
		time = getTime();
		customerArray[address][7] = time[0];
		customerArray[address][8] = time[1];
		customerArray[address][9] = time[2];
		customerArray[address][10] = time[3];
		customerArray[address][11] = time[4];
		customerArray[address][12] = time[5];

		diffHours = customerArray[address][10] - customerArray[address][4];
		diffMinutes = customerArray[address][11] - customerArray[address][5];
		diffSeconds = customerArray[address][12] - customerArray[address][6];
		if (diffSeconds < 0) {
			diffSeconds = diffSeconds + 60;
			diffMinutes--;
		}
		if (diffMinutes < 0) {
			diffMinutes = diffMinutes + 60;
			diffHours--;
		}
		printf("Parked for %02d:%02d:%02d\n", diffHours, diffMinutes, diffSeconds);
		//Calculate Parking Fee
		totalSecondParked = diffSeconds;
		totalSecondParked = totalSecondParked + (diffMinutes * 60);
		totalSecondParked = totalSecondParked + (diffHours * 3600);
		//Debug
		//totalSecondParked = 36001;
		printf("Parked for %d second, calculating the fee with %d rate...\n", totalSecondParked, parkingRate[10][0]);
		//Adding fee
		if (totalSecondParked <= (parkingRate[0][0]*60)) {
			fee = 0;
		}
		else {
			while (totalSecondParked > 0) {
				for (loop = 1; loop < parkingRate[10][0]; loop++) {
					if (parkingRate[loop][0] > (hrs * 60)) {
						rateAddress = loop;
						currentRate = parkingRate[rateAddress][1];
						break;
					}
				}
				
				fee = fee + currentRate;
				hrs++;
				totalSecondParked = totalSecondParked - 3600;
			}
		}
		printf("The Parking fee is %d baht.\n", fee);
		parkingLotLeft[customerArray[address][13]]++;
		customerArray[address][14] = fee;
		currentCarCount--;
	}
	else {
		printf("Error! No car parked yet!!\n");
	}
	system("pause");
	system("cls");
	return 0;
}
void writeLog() {
	int *time;
	int d, m, y;
	int count = 0;
	int tAddress = 0;
	int address = 0;
	int totalFee = 0;
	int diffHours, diffMinutes, diffSeconds;
	time = getTime();
	d = time[2];
	m = time[1];
	y = time[0];
	char str[20];
	sprintf(str, "%02d-%02d-%d", d,m,y);
	strcat(str, "-log.txt");
	printf("File name %s\n", str);
	FILE *file;
	file = fopen(str, "w");
	fprintf(file, "==================Summary Report==================\n");
	fprintf(file, "%-15s %-10s %-10s %-10s %-5s %-4s\n", "License Plate", "Time In", "Time Out", "Time Parked", "Floor", "Fee");
	for (tAddress = 0; tAddress < 1000; tAddress++) {
		diffHours = customerArray[tAddress][10] - customerArray[tAddress][4];
		diffMinutes = customerArray[tAddress][11] - customerArray[tAddress][5];
		diffSeconds = customerArray[tAddress][12] - customerArray[tAddress][6];
		if (diffSeconds < 0) {
			diffSeconds = diffSeconds + 60;
			diffMinutes--;
		}
		if (diffMinutes < 0) {
			diffMinutes = diffMinutes + 60;
			diffHours--;
		}
		if (diffHours < 0) {
			diffHours = diffMinutes = diffSeconds = 0;
		}
		fprintf(file, "%c%c%c%-12d   %02d:%02d:%02d     %02d:%02d:%02d     %02d:%02d:%02d   %-5d %-4d\n", licensePlate[tAddress][0], licensePlate[tAddress][1], licensePlate[tAddress][2], customerArray[tAddress][0], customerArray[tAddress][4],
			customerArray[tAddress][5], customerArray[tAddress][6], customerArray[tAddress][10], customerArray[tAddress][11], customerArray[tAddress][12],
			diffHours,diffMinutes,diffSeconds, customerArray[tAddress][13], customerArray[tAddress][14]);
		totalFee = totalFee + customerArray[tAddress][14];
		if (customerArray[tAddress+1][0] == 0) {
			break;
		}
	}
	fprintf(file, "\nTotal Car in the Database: %d\n", tAddress);
	fprintf(file, "Total Fee received = %d\n\n", totalFee);
	fprintf(file, "Cars that left overnight\n");
	fprintf(file, "%12s %s5\n", "License Plate", "Floor");
	for (address = 0; address <= tAddress; address++) {
		if (customerArray[address][7] < 2000) {
			fprintf(file,"%c%c%c%-12d %-5d\n", licensePlate[address][0], licensePlate[address][1], licensePlate[address][2], customerArray[address][0], customerArray[address][13]);
		}

	}




	fclose(file);
}

void main() {
	int *time;
	int selection = 0;
	int countTransfer = 0;
	time = getTime();
	
	configIO();
	system("cls");
	for (countTransfer = 0; countTransfer < 100; countTransfer++) {
		parkingLotLeft[countTransfer] = parkingLotRead[countTransfer];
	}
	while (selection != 5) {
		selection = menu();
		switch (selection) {
		case 1:
			carIn();
			break;
		case 2:
			carOut();
			break;
		case 3:
			displayParkingLots();
			break;
		case 4:
			changeFee();
			break;
		default:
			writeLog();
			break;
		}
	}
}