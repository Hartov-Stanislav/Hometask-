#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

const int SIZE = sizeof(int) * 8;

// Converts int number to additional code of this number
void convertToAd(int number, bool binaryNumber[])
{
	for (int i = (SIZE - 1); i >= 0; i--) {
		binaryNumber[i] = number & 1;
		number >>= 1;
	}
}

// Adds the second to the first number in additional code
void sumOfBin(bool firstNumber[], bool secondNumber[], bool binarySum[])
{
	int carryover = 0;
	for (int i = (SIZE - 1); i >= 0; i--) {
		binarySum[i] = firstNumber[i] ^ secondNumber[i] ^ carryover;
		carryover = (firstNumber[i] & secondNumber[i]) || (firstNumber[i] & carryover) || (secondNumber[i] & carryover);
	}
}

// Converts additional code of number to decimal number
int convertToDec(bool number[])
{
	int decimal = 0;
	int powerOfTwo = 1;
	for (int i = (SIZE - 1); i >= 0; i--) {
		decimal |= (number[i] * powerOfTwo);
		powerOfTwo <<= 1;
	}
	return decimal;
}

// Checks array of answer with true array answer
bool checkNumber(bool number[], bool answer[])
{
	for (int i = 0; i < SIZE; i++) 
	{
		if (number[i] != answer[i]) 
		{
			return false;
		}
	}
	return true;
}

// Testing covertion to Additional code
bool testConvertToAdd()
{
	int firstNumber = 13;
	int secondNumber = 25;
	bool firstBinNumber[32] = { 0 };
	bool secondBinNumber[32] = { 0 };
	convertToAd(firstNumber, firstBinNumber);
	convertToAd(secondNumber, secondBinNumber);
	bool answer1[32] = { 0 };
	answer1[28] = 1;
	answer1[29] = 1;
	answer1[31] = 1;
	bool answer2[32] = { 0 };
	answer2[31] = 1;
	answer2[28] = 1;
	answer2[27] = 1;
	return (checkNumber(firstBinNumber, answer1) & checkNumber(secondBinNumber, answer2));
}

// Testing adds function
bool testSum() {
	int number1 = 13;
	int number2 = 25;
	int number3 = -7;
	bool firstNumber[32] = { 0 };
	bool secondNumber[32] = { 0 };
	bool thirdNumber[32] = { 0 };
	convertToAd(number1, firstNumber);
	convertToAd(number2, secondNumber);
	convertToAd(number3, thirdNumber);
	bool sum1[32] = { 0 };
	bool sum2[32] = { 0 };
	bool sum3[32] = { 0 };
	sumOfBin(firstNumber, secondNumber, sum1);
	sumOfBin(firstNumber, thirdNumber, sum2);
	sumOfBin(secondNumber, thirdNumber, sum3);
	int result1 = convertToDec(sum1);
	int result2 = convertToDec(sum2);
	int result3 = convertToDec(sum3);
	return ((result1 == 38) & (result2 == 6) & (result3 == 18));
}

bool testConvertToDec()
{
	bool number1[32] = { 0 };
	bool number2[32] = { 0 };
	number2[28] = 1;
	number2[29] = 1;
	number2[31] = 1;
	int answer1 = convertToDec(number1);
	int answer2 = convertToDec(number2);
	return ((answer1 == 0) & (answer2 == 13));
}

int main() {
	if (!testConvertToAdd() || !testSum() || !testConvertToDec())
	{
		printf("Tests failed\n");
		return 1;
	}
	printf("Please enter first number ");
	int firstNumber = 0;
	scanf("%d", &firstNumber);
	bool firstBinaryNumber[32] = { 0 };
	convertToAd(firstNumber, firstBinaryNumber);
	printf("\n");
	printf("Additional code of firts number = ");
	for (int i = 0; i < 32; i++) 
	{
		printf("%d", firstBinaryNumber[i]);
	}
	printf("\n");
	printf("Please enter second number ");
	int secondNumber = 0;
	scanf("%d", &secondNumber);
	bool secondBinaryNumber[32] = { 0 };
	convertToAd(secondNumber, secondBinaryNumber);
	printf("\n");
	printf("Additional code of second number = ");
	for (int i = 0; i < 32; i++)
	{
		printf("%d", secondBinaryNumber[i]);
	}
	bool binarySum[32] = { 0 };
	sumOfBin(firstBinaryNumber, secondBinaryNumber, binarySum);
	int result = convertToDec(binarySum);
	printf("\n");
	printf("Sum of this numbers = %d", result);
}