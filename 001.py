""" Project Euler Problem 1 - https://projecteuler.net/problem=1
 * Multiples of 3 and 5
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
 * The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Created by Harvey Chen on 10/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
"""

sum = 0
for num in range(1000):
        if (num % 3 == 0 or num % 5 == 0):
                sum += num
print(sum)

#Ans: 233168
