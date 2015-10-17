/* Project Euler Problem 36 - https://projecteuler.net/problem=36
 * Double-base palindromes
 * The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 *
 * Created by Harvey Chen on 16/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <math.h>
#include <string>

bool isPalindrome (int n, int base);
int fetchDigit (int n, int ith, int base);

int main () {

	int sum = 0;

	for (int i = 0; i < 1000000; i++) {
		if (isPalindrome(i, 10)) {
			if (isPalindrome(i, 2))
				sum += i;
		}
	}

	printf("%d\n", sum);
}

bool isPalindrome (int n, int base) {
	int temp = n;
	int digits = 1;
	while (temp/=base) {
		digits++;
	}
	for (int i = 0; i <= floor(digits)/2; i++) {
		if (fetchDigit(n, digits - i - 1, base) != fetchDigit(n, i, base)) {
			return false;
		}
	}
	return true;
}

int fetchDigit (int n, int ith, int base) {
	while(ith--) {
		n /= base;
	}
	return (n % base);
}