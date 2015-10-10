// Palindrome number checker
// call isPalindrome(int n) to check
// 
// Created by Harvey Chen on 08/10/2015.
// Copyright (c) 2015 Harvey Chen. All rights reserved.

bool isPalindrome (int n) {
	int temp = n;
	int digits = 1;
	while (temp/=10) {
		digits++;
	}
	for (int i = 0; i <= floor(digits)/2; i++) {
		if (fetchDigit(n, digits - i - 1) != fetchDigit(n, i)) {
			return false;
		}
	}
	// printf("%d is palindrome\n", n);
	return true;
}

int fetchDigit (int n, int ith) {
	while(ith--) {
		n /= 10;
	}
	return (n % 10);
}