/*
 * TestCase.c
 *
 *  Created on: 07.04.2017
 *      Author: Tobias Sigmann
 */

#include <stdio.h>

typedef struct {
	unsigned short int Case;
	unsigned short int Expected;
	char Name[100];
} TestCase;

void runTest(int lenght, TestCase *test) {
	int soultion;
	for (int i = 0; i < lenght; i++) {
		printf("Test Nr.%i (%s): \n", i, test[i].Name);
		printf("\tInput: %#x; Expected-Output: %#x; ", test[i].Case,
				test[i].Expected);
		soultion = test[i].Case;
		printf("Output: %#x\n", soultion);
		if (test[i].Expected == soultion) {
			printf("\tOK \n");
		} else
			printf("\tFAIL \n");
		printf("\n");

	}
}

int main(void) {
	int number = 3;
	TestCase test[] = { { 1, 0, "Test auf 1" },
						{ 2, 3, "Test 2" },
						{ 3, 3, "Test 3" } };
	runTest(number, test);
	return 0;
}

