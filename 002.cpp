/* Project Euler Problem 2 - https://projecteuler.net/problem=2
 * Even Fibonacci numbers
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
 * By starting with 1 and 2, the first 10 terms will be:
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 *
 * Created by Harvey Chen on 08/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>

 #define MAX 4000000

int main () {

	int f1 = 2, f2 = 1, f = 0;
	int evenSum = 2;

	while (f < MAX) {
		if (f%2 == 0)
			evenSum += f;
		f = f1 + f2;
		f2 = f1;
		f1 = f;
	}
	printf("%d\n", evenSum);
	return evenSum;
}