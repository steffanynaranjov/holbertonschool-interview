#!/usr/bin/python3
""" module that finds the minimun operations needed"""

from math import sqrt


def minOperations(n):
    """ checks minimun operations required """
    min_operations = 0
    if n <= 1:
        return 0
    for i in range(2, int(sqrt(n) + 1)):
        while n % i == 0:
            min_operations = min_operations + i
            n = n / i
            if n <= 1:
                break
    if n > 1:
        min_operations = min_operations + int(n)
    return min_operations