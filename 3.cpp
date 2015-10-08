/* Project Euler Problem 3 - https://projecteuler.net/problem=3
 * Largest Prime Factor
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <math.h>

 #define num 600851475143

bool isPrime (int n);

int main () {
	int upperbound = sqrt(num);
	for (int i = 3; i < upperbound; i++) {
		if (num%i == 0 && isPrime(i))
			printf("%d\n",i);
	}
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