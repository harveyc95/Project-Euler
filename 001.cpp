/* Project Euler Problem 1 - https://projecteuler.net/problem=1
 * Multiples of 3 and 5
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
 * The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Created by Harvey Chen on 08/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>

 int main () {
 	int N = 1000;
 	int sum = 0;
 	for (int i = 1; i < N; i++) {
 		if ( (i % 3) == 0 || (i % 5) == 0 ) {
 			sum += i;
 		}
 	}
 	printf("%d\n",sum);
 	return sum;
 }
