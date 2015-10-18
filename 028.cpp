/* Project Euler Problem 28 - https://projecteuler.net/problem=28
 * Number spiral diagonals
 * Starting with the number 1 and moving to the right in a 
 * clockwise direction a 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 * It can be verified that the sum of the numbers on the diagonals is 101.
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 
 * spiral formed in the same way?
 * 
 * Created by Harvey Chen on 18/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>

int main () {
	unsigned long long diagonalSum = 1;
	for (int i = 3; i <= 1001; i++) {
		if (i % 2 == 0)	continue;
		for (int j = 0; j < 4; j++)
			diagonalSum += (i*i - (i-1)*j);
	}

	printf("%llu\n", diagonalSum);
}

