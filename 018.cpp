/* Project Euler Problem 18 - https://projecteuler.net/problem=18
 * Maximum path sum I
 * 
 * Created by Harvey Chen on 14/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <math.h>
#include <algorithm>

unsigned long long getMaxPath(unsigned long long array[][17], int m, int n) {
	if (array[m-1][n-1] > array[m-1][n])
		return array[m-1][n-1];
	else
		return array[m-1][n];
}

int main  () {	

	unsigned long long lattice[16][17] = {
		{0},
		{0, 75},
		{0, 95, 64},
		{0, 17, 47, 82},
		{0, 18, 35, 87, 10},
		{0, 20, 4, 82, 47, 65},
		{0, 19, 1, 23, 75, 3, 34},
		{0, 88, 2, 77, 73, 07, 63, 67},
		{0, 99, 65, 4, 28, 6, 16, 70, 92},
		{0, 41, 41, 26, 56, 83, 40, 80, 70, 33},
		{0, 41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
		{0, 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
		{0, 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
		{0, 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
		{0, 63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
		{0, 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
	};

	for (int i = 1; i < 16; i++) {
		for (int j = 1; j <= i; j++) {
			lattice[i][j] += getMaxPath(lattice, i, j);
			//printf("i: %d, j: %d is: %llu max is: %llu\n", i ,j,  lattice[i][j], getMaxPath(lattice, i, j));
		}
	}

	int max = 0;
	for (int j = 0; j < 17; j++) {
		max = max < lattice[15][j] ? lattice[15][j] : max;
	}
	printf("%d\n", max);
}