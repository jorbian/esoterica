#include <stdlib.h>
#include <math.h>

#define NUM_BIN_DIGITS(num) (int)(floor(log(num) / log(2)) + 1)
#define BIT_SET(num, bit) ((int)(floor(num / pow(2, bit))) % 2)

/**
 * binary_string - generate little endian string of int in binary
 * @num: an int to be represented in binary
 *
 * Return: Either a string of '1's and '0's or NULL --
*/
char *binary_string(int num)
{
	char *in_binary = NULL;

	int i, str_len = NUM_BIN_DIGITS(num);

	in_binary = malloc(str_len * sizeof(char));
	if (in_binary == NULL)
		return (NULL);

	for (i = 0; i < str_len; i++)
		in_binary[i] = (char)(BIT_SET(num, i) + 48);

	in_binary[i] = '\0';

	return (in_binary);
}
