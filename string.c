#include "shell.h"

/**
 * _str_dup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: pointer to a string
 * Return: pointer to a string
 */
char *_str_dup(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];
	return (new);
}

/**
 * _str_cnct - concatenates 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *_str_cnct(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * _strtoint - converts a string into an integer
 * @s: pointer to a string
 * Return: the integer
 */
int _strtoint(char *s)
{
	int i, intgr, sign = 1;

	i = 0;
	intgr = 0;
	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		intgr = (intgr * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (intgr);
}

/**
 * _strlen - prints the length of a string
 * @s: pointer to the string
 * Return: the length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - prints the character c to standard output
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string to the standard output
 * @str: pointer to string
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
