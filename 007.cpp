/* Project Euler Problem 7 - https://projecteuler.net/problem=7
 * 10001st prime
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 * 
 * Created by Harvey Chen on 08/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <math.h>

bool isPrime (int n);

int main () {
	bool notFound = true;
	int i = 2;
	int key = 10001;
	int counter = 0;
	while (true) {
		if (isPrime(i)) {
			// printf("prime: %d\n", i);
			counter++;
		}
		if (counter >= key) {
			break;
		}
		i++;
	}
	printf("%d\n", i);
}

bool isPrime (int n) {
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n%2 == 0)
		return false;
	int m = sqrt(n);

	for (int i = 3; i <= m; i++) {
		if (n%i == 0)
			return false;
	}

	return true;
}