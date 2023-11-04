#!/usr/bin/python3

from math import sqrt
from pathlib import Path

OUTFILE_NAME = "known_primes.txt"

def find_primes(counter, known_primes = [2], num = 3):
    """RECURSIVE FUNCTION RETURNING THE FIRST X NUMBER OF PRIME NUMBERS"""
    square_root = sqrt(num)
    is_prime = True

    if (counter == 0):
        return (known_primes)

    for prime_num in known_primes:
        if (num % prime_num == 0):
            is_prime = False
            break
        if prime_num > square_root:
            break

    if is_prime == 1:
        known_primes.append(num)

    return (find_primes(counter - 1, known_primes, num + 2))


def generate_cache(limit = 100, outpath = OUTFILE_NAME):
    """CREATES A TEXT FILE TO STORE THE THE OUTPUT OF FIRST FUNCTION"""
    output_obj = Path(outpath)
    if not output_obj.exists():
        prime_list = str(find_primes(limit))
        output_obj.write_text(prime_list[1:-1])


if __name__ == "__main__":
    generate_cache()