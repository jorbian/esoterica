#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

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

uint64_t first_n_digits(uint64_t a, uint64_t b, uint64_t n) {
       int a = 12;
       int b = 13;
       int n = 4;
       double x, y;

       x = b * log10(a);
       y = floor(pow(10, x - floor(x) + n - 1));
       printf("Result: %d\n", (int)y);

       return EXIT_SUCCESS;
}

int main(void)
{
	printf("%ld\n", modular_exponent(2,1280,1000));
}