#!/usr/bin/python3

import math

def find_primes(limit): 
    """CREATE A GENERATOR YIELDING PRIME NUMBERS"""
    seive = list(range(3, (limit + 1), 2))
    mroot = math.floor(math.sqrt(limit))
    half = (limit + 1) /2 - 1
    i=0
    m=3

    while (m <= mroot):
        if seive[i]:
            j= int((m * m-3) / 2)
            seive[j]=0
            while j<half:
                seive[j]=0
                j+=m
        i = i + 1
        m = 2 * i + 3

    return (
        x for x in ([2]+[x for x in seive if x])
    )
