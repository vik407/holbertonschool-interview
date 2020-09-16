#include "palindrome.h"

/**
 * is_palindrome - a function that checks whether or not a given unsigned integer
 * is a palindrome.
 * @n: the number to be checked.
 * Return: return 1 if n is a palindrome, and 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
    unsigned int res = 0;

    if (n && !(n % 10))
        return (0);
    for (; n > res; n /= 10)
        res = (res * 10) + n % 10;

    return (n == res || n == (res / 10));
}
