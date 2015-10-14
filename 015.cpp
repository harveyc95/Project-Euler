/* Project Euler Problem 15 - https://projecteuler.net/problem=15
 * Lattice paths
 * Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, 
 * there are exactly 6 routes to the bottom right corner.
 * How many such routes are there through a 20×20 grid?
 * 
 * Created by Harvey Chen on 13/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
 */

#include <stdio.h>
#include <math.h>

 	// printing the lattice. useful for debugging
	// for (int i = 0; i <= m; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		printf("%llu\t",lattice[i][j]);
	// 	}
	// 	printf("\n");
	// }

int main  () {
	int m = 20, n = 20;
	unsigned long long lattice[m+1][n+1];

	// initialize all to 0
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			lattice[i][j] = 0;
		}
	}

	// make 0th row and colum all 1
	for (int i = 0; i <= m; i++)
		lattice[i][0] = 1;
	for (int i = 0; i <= n; i++)
		lattice[0][i] = 1;

	// add up the paths
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			lattice[i][j] = lattice[i][j-1] + lattice[i-1][j];
		}
	}

	printf("%llu\n", lattice[m][n]);
}