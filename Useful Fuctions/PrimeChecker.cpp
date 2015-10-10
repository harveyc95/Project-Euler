// Prime checker
// returns true if prime, false otherwise
// 
// Created by Harvey Chen on 08/10/2015.
// Copyright (c) 2015 Harvey Chen. All rights reserved.

bool isPrime (int n) {
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n%2 == 0)
		return false;
	int m = sqrt(n);

	for (int i = 3; i <= m; i++) {
		if (n%i == 0)
			return false;
	}

	return true;
}