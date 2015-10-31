/* Project Euler Problem 92 - https://projecteuler.net/problem=92
 * Square Digit Chains
 * A number chain is created by continuously adding the square of the digits 
 * in a number to form a new number until it has been seen before.
 * For example,
 * 44 → 32 → 13 → 10 → 1 → 1
 * 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
 * Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. 
 * What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.
 * How many starting numbers below ten million will arrive at 89?
 *
 * Created by Harvey Chen on 30/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <math.h>
#include <string>

int computeDestination (int *destination, int start);
int squareDigitSum (int n);
int fetchDigit (int n, int ith, int base = 10);

int main () {

	int destination [568];
	for (int i = 0; i <= 568; i++)
		destination[i] = 0;
	destination[1] = 1;
	destination[89] = 89;

	for (int i = 2; i < 568; i++)
		computeDestination(destination, i);

	int count = 0;
	for (int i = 1; i <= 10000000; i++) {
		if(destination[squareDigitSum(i)] == 89)	count++;
	}

	printf("There are %d square digit chains\n", count);

}

int computeDestination (int *destination, int start) {
	if (!destination[start])	destination[start] = computeDestination(destination, squareDigitSum(start));
	return destination[start];
}

int squareDigitSum (int n) {
	int sum = 0;
	int temp;
	for (int i = 0; i <= floor(log10(n)); i++) {
		temp = fetchDigit(n, i);
		sum += temp*temp;
	}
	return sum;
}

int fetchDigit (int n, int ith, int base) {
	while(ith--)	n /= base;
	return (n % base);
}