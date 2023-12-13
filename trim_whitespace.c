#include "shell.h"
#include <ctype.h>
#include <string.h>

/**
* trim_whitespace - Trim leading and trailing whitespace
* @str: String to trim
*
* Return: Trimmed string
*/
char *trim_whitespace(char *str)
{
char *end;

/* Trim leading space */
while (isspace((unsigned char)*str))
str++;

if (*str == 0)  /* All spaces? */
return (str);

/* Trim trailing space */
end = str + strlen(str) - 1;
while (end > str && isspace((unsigned char)*end))
end--;

/* Write new null terminator character */
end[1] = '\0';

return (str);
}
