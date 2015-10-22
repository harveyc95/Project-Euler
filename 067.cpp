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

	ifstream input_file("067_triangle.txt");	// open the input file
	if (!input_file.is_open()) {				// check for successful opening
		printf("Input file could not be opened. Terminating\n");
		return 0;
	}

	int input, max;
	for (int i = 0; i <= 100; i++) {
		array[i][0] = 0;
		if(i != 100) array[i][i + 1] = 0;
		// 0 x x x x x x x x 0<-This one
		//  \|\|\|\|\|\|\|\|\|
		// 0 x x x x x x x x x ...
		for (int j = 1; j <= i; j++) {
			input_file >> input;
			array[i][j] = input;
			array[i][j] += getMaxPath(array, i, j);
			if (i == 100)	max = max < array[100][j] ? array[100][j] : max;
		}
	}

	printf("%d\n", max);
}