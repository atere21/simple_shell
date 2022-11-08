#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
int i, j, k, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
 (NULL);
=  ;
for (i = 0; str[i] != '\0'; i++)
umwords++;

if (numwords == 0)
 (NULL);
s = malloc((1 + numwords) * sizeof(char *));
 (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
(is_delim(str[i], d))
= 0;
= malloc((k + 1) * sizeof(char));
(k = 0; k < j; k++)
 (NULL);
(m = 0; m < k; m++)
= str[i++];
= 0;
}
s[j] = NULL;
return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
int i, j, k, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
 (NULL);
for (i = 0; str[i] != '\0'; i++)
((str[i] != d && str[i + 1] == d) ||
umwords++;
if (numwords == 0)
 (NULL);
s = malloc((1 + numwords) * sizeof(char *));
 (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
(str[i] == d && str[i] != d)
= 0;
(str[i + k] != d && str[i + k] && str[i + k] != d)
= malloc((k + 1) * sizeof(char));
(k = 0; k < j; k++)
 (NULL);
(m = 0; m < k; m++)
= str[i++];
= 0;
}
s[j] = NULL;
return (s);
}