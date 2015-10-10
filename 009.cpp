/* Project Euler Problem 9 - https://projecteuler.net/problem=9
 * Special Pythagorean triplet
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 * 
 * Created by Harvey Chen on 08/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <math.h>

int main () {
	for (int A = 1; A < 999; A++) {
		for (int B = 1; (A + B < 1000 && B < 999); B++) {
			int C = 1000 - A - B;
			if ((A*A + B*B) == (C*C)) {
				printf("Found a triple!\n");
				printf("A: %d, B: %d, C:%d\n", A, B, C);
				printf("Product: %d\n", A*B*C);
				return 0;
			}
		}
	}
}