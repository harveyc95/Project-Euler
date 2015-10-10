/* Project Euler Problem 6 - https://projecteuler.net/problem=6
 * Sum square difference
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 * 
 * Created by Harvey Chen on 08/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <math.h>

int main () {
	double sumOfSquare;
	double squareOfSum;
	int numToSum = 100;
	for (int i = 1; i <= numToSum; i++) {
		sumOfSquare += pow(i, 2);
	}
	for (int i = 1; i <= numToSum; i++) {
		squareOfSum +=i;
	}
	squareOfSum = pow(squareOfSum , 2);
	printf("%d\n", (int)(squareOfSum - sumOfSquare));
}