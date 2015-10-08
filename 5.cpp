/* Project Euler Problem 5 - https://projecteuler.net/problem=5
 * Smallest Multiple
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>

int main () {
	unsigned long long num = 2520;
	bool allDivisible = false;
	while (!allDivisible) {
		for (int i = 1; i <= 20; i++) {
			if (num%i == 0) {
				allDivisible = true;
			} else {
				allDivisible = false;
				break;
			}
		}
		if (allDivisible) {
			printf("%llu\n",num);
			return num;
		}
		num++;
	}
	return 0;
}