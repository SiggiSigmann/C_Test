/*
 * TestCase.c
 *
 *  Created on: 07.04.2017
 *      Author: Tobias Sigmann
 */

#include <stdio.h>

typedef enum{
	OK, FAIL
}Test;

typedef struct {
	unsigned short int testCase;
	unsigned short int expected;
	char name[50];
} TestCase;

Test testFuntion(int input, int expected);

/*
 * runTest initialisiert den Testlauf
 * @param *test Zeiger auf Liste mit Testf�llen.
 * @param Anzahl der Tests.
 */
void runTest(int lenght, TestCase *test) {
	Test t;
	int ok=0;
	int fail=0;
	for (int i = 0; i < lenght; i++) {
		printf("Test Nr.%i (%s): \n", (i+1), test[i].name);
		printf("\tInput: %#x; Expected-Output: %#x; ", test[i].testCase,
				test[i].expected);
		t = testFuntion(test[i].testCase, test[i].expected);
		if (OK == t) {
			printf("\tOK \n");
			ok++;
		} else{
			printf("\tFAIL \n");
			fail++;
		}
		printf("\n");
	}
	printf("Result Tests: %i OK: %i Fails: %i\n",lenght,ok,fail);
}

Test testFuntion(int input, int expected){
	int soultion=input;

	printf("Output: %#x\n", soultion);
	if(soultion==expected){
		return OK;
	}else{
		return FAIL;
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

