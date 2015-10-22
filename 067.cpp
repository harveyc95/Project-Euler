/* Project Euler Problem 67 - https://projecteuler.net/problem=67
 * Maximum path sum II
 * 
 * Created by Harvey Chen on 22/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <fstream>

unsigned long long getMaxPath(unsigned long long array[][101], int m, int n) {
	if (array[m-1][n-1] > array[m-1][n])
		return array[m-1][n-1];
	else
		return array[m-1][n];
}

using namespace std;

int main  () {

	unsigned long long array[101][101];	// row + 1 for padding
	// set array to all 0
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			array[i][j] = 0;
		}
	}

	ifstream input_file("067_triangle.txt");	// open the input file
	if (!input_file.is_open()) {				// check for successful opening
		printf("Input file could not be opened. Terminating\n");
		return 0;
	}

	// read as long as the stream is good - any problem, just quit.
	int input;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= i; j++) {
			input_file >> input;
			printf("%d ", input);
			array[i][j] = input;
		}
		printf("\n");
	}


	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d ", array[i][j]);
			array[i][j] += getMaxPath(array, i, j);
			//printf("i: %d, j: %d is: %llu max is: %llu\n", i ,j,  lattice[i][j], getMaxPath(lattice, i, j));
		}
		printf("\n");
	}

	int max = 0;
	for (int j = 0; j < 101; j++) {
		max = max < array[100][j] ? array[100][j] : max;
	}
	printf("%d\n", max);
}