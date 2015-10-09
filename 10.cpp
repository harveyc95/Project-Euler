/* Project Euler Problem 10 - https://projecteuler.net/problem=10
 * Summation of primes
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <math.h>

// Sieve of Eratosthenes
// Pass in a bool array of size range + 1 (ie. bool array[range + 1])
// since bool array doesn't use array[0]. thus range becomes a[1] ~ a[range]
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

int main () {
	int Max = 3;
	bool array[Max+1];
	SieveOfEratosthenes(array, Max);
	int sum = 0;
	for (int i = 0; i <= Max; i++) {
		if (array[i]) {
			// printf("LOL\n");
			// printf("%d is a prime\n", i);
			sum += i;
		}
	}
	printf("%d\n", sum);
}