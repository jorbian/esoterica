from math import factorial, sqrt

def is_prime(x):
    """Slower other methods but just a single line -- using Wilson's theorem"""
    return (factorial(x - 1) % x == x - 1)


def generate_prime_numbers(limit, start = 2):
    """GENERATES PRIME NUMBERS UP TO THE GIVEN LIMIT"""
    if ((start % 2 == 0) and (start != 2)):
        raise StopIteration(
            "{}".format("GENERATOR MUST BEGIN WITH ODD NUMBER!")
        )
    if (start == 2):
        start = start + 1
        yield (2)

    for i in range(start, int(sqrt(limit)) + 1, 2):
        if (is_prime(i)):
            yield (i)
