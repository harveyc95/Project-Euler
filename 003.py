""" Project Euler Problem 3 - https://projecteuler.net/problem=3
 * Largest Prime Factor
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 *
 * Created by Harvey Chen on 10/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
"""

import math

num = 600851475143
x = 2
while (x < math.sqrt(num)):
    while (num % x == 0):
        num /= x
    x += 1

print(num)

#Ans: 6857
