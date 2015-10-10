// Sieve of Eratosthenes
// Pass in a bool array of size range + 1 (ie. bool array[range + 1])
// since bool array doesn't use array[0]. thus range becomes a[1] ~ a[range]
// to print the prime numbers, simply loop through it, if array[i] is true, i is a prime number
// exmaple: 
//  for (int i = 0; i <= MAX; i++) {
// 		if (array[i]) {
// 			printf("%d\n", i);
// 		}
// 	}
// 	
// 	Created by Harvey Chen on 08/10/2015.
//  Copyright (c) 2015 Harvey Chen. All rights reserved.

void SieveOfEratosthenes (bool array[], int range) {
	
	array[0] = 0;
	array[1] = 0;
	for (int i = 2; i <= range; i++) { // set all to true
		array[i] = 1;
	}
	int upperBound = ceil(sqrt(range));
	for (int i = 2; i <= upperBound; i++) {
		if (array[i]) {
			for (int j = i*i; j <= range; j += i) {
				array[j] = 0;
			}
		}
	}
	return;
}