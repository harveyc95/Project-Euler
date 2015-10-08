/* Project Euler Problem 4 - https://projecteuler.net/problem=4
 * Largest palindrome product
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <math.h>

bool isPalindrome (int n);
int fetchDigit (int n, int ith);

int main () {
	int max = 0;
	for (int j = 999; j > 100; j--) {
		for (int i = 999; i > 100; i--) {
				if (isPalindrome(i*j)) {
				max = (i*j > max) ? i*j : max;
			}
		}
	}
	printf("%d\n", max);
}

bool isPalindrome (int n) {
	int temp = n;
	int digits = 1;
	while (temp/=10) {
		digits++;
	}
	for (int i = 0; i <= floor(digits)/2; i++) {
		if (fetchDigit(n, digits - i - 1) != fetchDigit(n, i)) {
			return false;
		}
	}
	// printf("%d is palindrome\n", n);
	return true;
}

int fetchDigit (int n, int ith) {
	while(ith--) {
		n /= 10;
	}
	return (n % 10);
}