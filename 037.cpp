/* Project Euler Problem 37 - https://projecteuler.net/problem=37
 * Truncatable primes
 * The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, 
 * and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
 * Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 *
 * Created by Harvey Chen on 21/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <math.h>
#include <string>

void SieveOfEratosthenes (bool array[], unsigned long long range);
int numDigits (int n, int base = 10);
bool isTruncatablePrime (int n, bool array[]);

int main () {
	unsigned long long range = 1000000;
	bool array[range + 1];
	int sum = 0;
	int count = 0;
	SieveOfEratosthenes (array, range);

	for (int i = 0; i <= range; i++) {
		if (array[i] && isTruncatablePrime(i, array)) {
			count++;
			printf("%d\n", i);
			sum += i;
		} else {
		//	printf("%d is not a truncatable prime\n", i);
		}
	}

	printf("Sum of the only %d primes that are both truncatable from left to right and right to left is: %d\n", count, sum);
	
}

void SieveOfEratosthenes (bool array[], unsigned long long range) {
	
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

int numDigits (int n, int base) {
	int temp = n;
	int digits = 1;
	while (temp/=base) {
		digits++;
	}
	return digits;
}

bool isTruncatablePrime (int n, bool array[]) {
	// use division to truncate from right
	// use modulos to truncate from left
	if (numDigits(n) < 2) {
		printf("%d only has 1 digit\n", n);
		return false;
	}
	int div_mod = 10;
	while (div_mod <= n) {
		if (!array[n/div_mod] || !array[n%div_mod]) {
		//	printf("%d or %d is not truncatable prime\n", n/div_mod, n%div_mod);
			return false;
		}
		div_mod *= 10;
	}
	return true;
}