#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
* replace_str - Replace a substring with another string in a string
* @str: The original string
* @old: The substring to be replaced
* @new: The string to replace the substring
*
* Return: The new string
*/
char *replace_str(char *str, char *old, char *new)
{
char *result;
int i, count = 0;
int newlen = new ? strlen(new) : 0;
int oldlen = strlen(old);

for (i = 0; str[i] != '\0'; i++)
{
if (strstr(&str[i], old) == &str[i])
{
count++;
i += oldlen - 1;
}
}

result = (char *)malloc(i + count * (newlen - oldlen) + 1);

i = 0;
while (*str)
{
if (strstr(str, old) == str)
{
strcpy(&result[i], new);
i += newlen;
str += oldlen;
}
else
{
result[i++] = *str++;
}
}

result[i] = '\0';
return (result);
}
