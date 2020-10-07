#include "menger.h"

/**
 * menger - A function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int c, r, size;

	if (level >= 0)
	{
		size = pow(3, level);
		for (c = 0; c < size; c++)
		{
			for (r = 0; r < size; r++)
				printf("%c", _putchar(c, r));
			printf("\n");
		}
	}
}

/**
 * _putchar - render the character on the sponge
 * @c: column
 * @r: row
 * Return: '#' or ' '
 */
char _putchar(int c, int r)
{
	for (; c && r; c /= 3, r /= 3)
	{
		if (c % 3 == 1 && r % 3 == 1)
			return (' ');
	}
	return ('#');
}
