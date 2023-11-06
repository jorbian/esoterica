#include <stdio.h>
#include <stdint.h>
#include <math.h>

/**
 * first_n_digits - calculate the first n digits of an exponent
 * @base: the base number
 * @exp: number base is being raised to
 * @digits: number of digits from the left of answer to return
 * 
 * Return: Truncated version of the answer to the exponent.
*/
uint64_t first_n_digits(uint64_t base, uint64_t exp, uint64_t digits)
{
       double base_answer = base * log10(exp);

       return (
            (uint64_t)floor(pow(10, base_answer - floor(base_answer) + digits - 1))
        );
}
