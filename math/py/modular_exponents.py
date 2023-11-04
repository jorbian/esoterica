#!/usr/bin/python3

def modular_exponent(base, exp, mod):
    """PERFORM MODULAR EXPONENTIANTION"""
    last_value = base
    binary_digits = (int(x) for x in "{0:b}".format(exp)[1:])

    for digit in binary_digits:
        last_value = (last_value ** 2) % mod
        if (digit == 1):
            last_value = (last_value * base) % mod

    return (last_value)
