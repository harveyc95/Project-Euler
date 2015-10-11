''' Project Euler Problem 4 - https://projecteuler.net/problem=4
 * Largest palindrome product
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * Created by Harvey Chen on 11/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
'''

import math

maxProduct = 0
for i in range (999, 100, -1):
    for j in range (999, 100, -1):
        if(str(i*j) == str(i*j)[::-1] and i*j > maxProduct):
            maxProduct = i*j
print(maxProduct)

#Ans: 906609
