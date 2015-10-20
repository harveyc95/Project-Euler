/* Project Euler Problem 35 - https://projecteuler.net/problem=35
 * Circular primes
 * The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 * How many circular primes are there below one million?
 *
 * Created by Harvey Chen on 20/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <math.h>
#include <string>

bool isPalindrome (int n, int base);
int fetchDigit (int n, int ith, int base);
void SieveOfEratosthenes (bool array[], int range);
int rotateInt (int n, int ith);
int numDigits (int n);
bool circularPrime (int n);

int main () {
	int range = 1000000;
	int numCircular = 0;
	bool circular = false;
	bool array[range + 1];

	SieveOfEratosthenes (array, range);

	for (int i = 0; i <= range; i++) {
		if (array[i]) {
			if (circularPrime(i)) {
				circular = true;
				for (int j = 1; j <= numDigits(i) && circular; j++) {
					if (!array[rotateInt(i, j)])
						circular = false;
				}
				if (circular) {
					printf("%d\n", i);
					numCircular++;
				}
			}
		}
	}
	printf("%d\n", numCircular);
}

int fetchDigit (int n, int ith, int base) {
	while(ith--) {
		n /= base;
	}
	return (n % base);
}

void SieveOfEratosthenes (bool array[], int range) {
	
	array[0] = 0;
	array[1] = 0;
	for (int i = 2; i <= range; i++) { // set all to true
		array[i] = 1;
	}
	int upperBound = ceil(sqrt(range));
	for (int i = 2; i <= upperBound; i++) {
		if (array[i]) {
			for (int j = i*i; j <= range; j += i) {
				array[j] = 0;
			}
		}
	}
	return;
}

int rotateInt (int n, int ith) {
	int numberOfDigits = numDigits(n);
	int array[numberOfDigits];
	for (int i = numberOfDigits - 1; i >= 0; i--) {
		array[i] = fetchDigit(n, i, 10);
		// printf("%d\n", array[i]);
	}
	int returnVal = 0;
	for (int i = numberOfDigits - 1; i >= 0; i--) {
		returnVal += (int)pow(10, i) * array[(i+ith)%numberOfDigits];
		// printf("%d\n",returnVal);
	}
	return returnVal;
}

int numDigits (int n) {
	int temp = n;
	int digits = 1;
	while (temp/=10) {
		digits++;
	}
	return digits;
}

bool circularPrime (int n) {
	int temp = n;
	int digits = numDigits(n);
	int singleDigit = 0;
	if (digits == 1)	return true;
	for (int i = 0; i < digits; i++) {
		singleDigit = n % 10;
		if (singleDigit == 0 || singleDigit == 2 || singleDigit == 4 || singleDigit == 5 || singleDigit == 6 || singleDigit == 8)
			return false;
	}
	return true;
}