#include "shell.h"
/*
 * Duplicate a string
 */char *_strdup(char *str)
{
int i, l;
char *new;
if (!str)
{
return (NULL);
}
/*
 * Calculate the length of the string
 */for (l = 0; str[l] != '\0';)
{
l++;
}
/*
 * Allocate memory for the new string
 */new = malloc(sizeof(char) * l + 1);
if (!new)
{
return (NULL);
}
/*
 * Copy the characters from the
 * original string to the new string
 */for (i = 0; i < l; i++)
{
new[i] = str[i];
}
new[l] = str[l];
return (new);
}
/*
 * Concatenate three strings
 */char *concat_all(char *name, char *sep, char *value)
{
char *result;
int l1, l2, l3, i, k;
/*
 * Calculate the lengths of the strings
 */l1 = _strlen(name);
l2 = _strlen(sep);
l3 = _strlen(value);
/*
 * Allocate memory for the result string
 */result = malloc(l1 + l2 + l3 + 1);
if (!result)
return (NULL);
/*
 * Copy the first string to the result
 */for (i = 0; name[i]; i++)
result[i] = name[i];
k = i;
/*
 * Copy the second string to the result
 */for (i = 0; sep[i]; i++)
result[k + i] = sep[i];
k = k + i;
/*
 * Copy the third string to the result
 */for (i = 0; value[i]; i++)
result[k + i] = value[i];
k = k + i;
result[k] = '\0';
return (result);
}
/*
 * Calculate the length of a string
 */int _strlen(char *s)
{
int i = 0;
while (*(s + i) != '\0')
{
i++;
}
return (i);
}
/*
 * Write a character to stdout
 */int _putchar(char c)
{
return (write(1, &c, 1));
}
/*
 * Print a string to stdout
 */void _puts(char *str)
{
int i = 0;
while (str[i])
{
_putchar(str[i]);
i++;
}
}

