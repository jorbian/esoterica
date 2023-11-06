#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * r_pow - recursive function to calculate exponents
 * @base: the base of the exponent
 * @pow: power that it's being raised to
 * @result: value where the answer is stored
 * 
 * Return: The base raised to the whatever power.
*/
uint64_t r_pow(uint64_t base, uint64_t pow, uint64_t result)
{
    if (pow == 0)
        return (result);

    return (r_pow(base, (pow - 1), (result * base)));
}

int main(void)
{
    printf("%ld\n", r_pow(2, 0, 1));
    printf("%ld\n", r_pow(3, 3, 1));
}
