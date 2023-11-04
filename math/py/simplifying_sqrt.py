#!/usr/bin/python3

from math import sqrt, floor

number = 125

def find_perfect_square_factor(num):
    factors = [
        x for x in [
            x ** 2 for x in range(2, floor(sqrt(number)))
        ] if number % x == 0
    ]
    if factors:
        return (factors[0])
    
    return (None)

print(find_perfect_square_factor(number))