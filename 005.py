''' Project Euler Problem 5 - https://projecteuler.net/problem=5
 * Smallest Multiple
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *
 * Created by Harvey Chen on 11/10/2015.
 * Copyright (c) 2015 Harvey Chen. All rights reserved.
'''

num = 2520
allDivisible = 0
while (allDivisible == 0):
    for i in range (1, 21):
        if (num % i == 0):
            allDivisible = 1
        else:
            allDivisible = 0
            break
    if (allDivisible == 1):
        break
    num += 20
print(num)
        
#Ans: 232792560
