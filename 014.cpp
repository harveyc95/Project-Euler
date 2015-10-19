/* Project Euler Problem 14 - https://projecteuler.net/problem=14
 * Longest Collatz sequence
 *
 * The following iterative sequence is defined for the set of positive 
 * integers:
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * It can be seen that this sequence (starting at 13 and finishing at 1) 
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), 
 * it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain? 
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 * 
 * Created by Harvey Chen on 14/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <assert.h>

typedef long long NUM;

int collatzSequenceLength(unsigned long long n) {
	int count = 1;
	while (n != 1) {
		count ++;
		if (n % 2 == 0) n = n/2;
		else n = 3*n + 1;
		assert(n > 0);
	}
	return count;
}

int main  () {
	NUM longestSequence = 0;
	NUM temp = 0;
	int index;
	for (unsigned long long i = 2; i <= 1000000; i++) {
		temp = collatzSequenceLength(i);
		// printf("%llu th collatzSquence is: %llu\n", i, temp);
		if (temp > longestSequence) {
			longestSequence = temp;
			index = i;
		}
	}
	
	printf ("Longest Sequence is: %llu at %dth sequence\n", longestSequence, index);
}