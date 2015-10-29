/* Project Euler Problem 34 - https://projecteuler.net/problem=34
 * Digit factorials
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 * 
 * Created by Harvey Chen on 29/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

// precalculate 16 factorial numbers using dynamic programming

#include <stdio.h>
#include <math.h>

typedef long long LL;

int numDigits (LL n, int base = 10);
int fetchDigit (LL n, int ith, int base = 10);
bool isDigitFactorial(LL num, LL array[]);

int main (int argc, char *argv[]) {
	LL fact[16+1];
	LL sum = 0;
	fact[0] =  fact[1] = 1;
	for (int i = 2; i <= 16; i++) {
		fact[i] = i * fact[i-1];
	}
	for (int i = 3; i <= 999999; i++) {
		if(isDigitFactorial(i, fact)) {
			printf("%d is digit factorial\n", i);
			sum += i;
		}
	}
	printf("sum of all digit factorial %llu\n", sum);
}

int numDigits (LL n, int base) {
	LL temp = n;
	LL digits = 1;
	while (temp/=base) {
		digits++;
	}
	return digits;
}

int fetchDigit (LL n, int ith, int base) {
	while(ith--) {
		n /= base;
	}
	return (n % base);
}

bool isDigitFactorial(LL num, LL array[]) {
	LL digitFactorialSum = 0;
	for (int i = 0; i < numDigits(num); i++) {
		digitFactorialSum += array[fetchDigit(num, i)];
	}
	if (num == digitFactorialSum)	return true;
	else	return false;
}