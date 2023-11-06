#include <stdio.h>
#include <stdint.h>

uint64_t modular_exponent(uint64_t base, uint64_t exp, uint64_t mod)
{
	int result = 1;

	while (exp > 0)
	{
		if (exp % 2 == 1)
			result = (result * base) % mod;

		exp = exp >> 1;
		base = (base * base) % mod;
	}
	return (result % mod);
}
