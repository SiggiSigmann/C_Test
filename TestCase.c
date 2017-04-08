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
	unsigned short int Case;
	unsigned short int Expected;
	char Name[100];
} TestCase;

Test testFuntion(int input, int expected);

/*
 * runTest initialisiert den Testlauf
 * @param *test Zeiger auf Liste mit Testfällen.
 * @param Anzahl der Tests.
 */
void runTest(int lenght, TestCase *test) {
	Test t;
	int ok=0;
	int fail=0;
	for (int i = 0; i < lenght; i++) {
		printf("Test Nr.%i (%s): \n", (i+1), test[i].Name);
		printf("\tInput: %#x; Expected-Output: %#x; ", test[i].Case,
				test[i].Expected);
		t = testFuntion(test[i].Case, test[i].Expected);
		if (OK == t) {
			printf("\tOK \n");
			ok++;
		} else{
			printf("\tFAIL \n");
			fail++;
		}
		printf("\n");
	}
	printf("Result Tests: %i OK: %i Fails: %i",lenght,ok,fail);
}

/*
 * testFuntion initialisiert den test und liefert das Ergebnis zurück.
 * @param input Funktionsparameter.
 * @param expected erwartetes Ergebnis.
 * @return Ergebis des Tests.
 */
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

