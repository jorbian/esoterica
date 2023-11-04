#!/usr/bin/python3

from math import factorial, sqrt


def perform_prime_factorization(num):
    """RETURNS LIST OF PRIME FACTORS OF 'num' -- INCLUDING DUPLICATES"""
    factors = [num, 1]

    def is_prime(x):
        """Slower other methods but just a single line -- using Wilson's theorem"""
        return (factorial(x - 1) % x == x - 1)

    def generate_prime_numbers(limit, start = 2):
        """GENERATES PRIME NUMBERS UP TO THE GIVEN LIMIT"""
        if (start == 2):
            start = start + 1
            yield (2)

        for i in range(start, int(sqrt(limit)) + 1, 2):
            if (is_prime(i)):
                yield (i)

    if (is_prime(num)):
        return (factors)

    primes = generate_prime_numbers(num)

    while (True):
        divisor = next(primes)
        while (num % divisor == 0):
            factors.append(divisor)
            num /= divisor

        if is_prime(int(num)):
            if (int(num) not in set(factors)):
                factors.append(int(num))
            break

    factors.sort()

    return (factors)

print(perform_prime_factorization(16))