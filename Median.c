/**
 * Author - Debag101
 * Purpose - Median finder of an array
 * Date - 14 05 2023
 * */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Prototype of median finder function
int medianFinder(int*,int);

//Main starts
int main(int argc, char const argv[]) {
	int size;
	printf("\nEnter the size of the array => ");
	//Getting size of array
	scanf("%d",&size);
	//Declaring array
	int numArray[size];
	//Getting values for array
	for(int i = 0; i < size; i++) {
		printf("\nEnter element at index %d => ",i);
		scanf("%d",&numArray[i]);
	}
	//Getting median
	medianFinder(numArray, size);
	//Exit code
	printf("\nenter any key to exit ...... ");
	getch();
	system("cls");
	//main ends
	return 0;
}

int medianFinder(int arr[], int size) {
	//if odd elements present
	if(size % 2 != 0) {
		printf("\nMedian Elements are => %d",arr[size / 2]);
	//if even elements present
	}else {
		printf("\nMedian Elements are => %d and %d",arr[size / 2 - 1], arr[size / 2 ]);
	}
}