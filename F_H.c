#include "shell.h"

/**
* print_ch - writes the character c to stdout
* @ch: The character to print
* Return: On success 1. On error, -1 is returned
*/
int print_ch(char ch)
{
return (write(1, &ch, 1));
}

/**
* copy_string_n - copy a string
* @dest:destination
*  @src:source
* @len:length
* Return:char
*/
char *copy_string_n(char *dest, char *src, int len)
{
int index;

index = 0;
while (index < len && *(src + index))
{
*(dest + index) = *(src + index);
index++;
}
while (index < len)
{
*(dest + index) = '\0';
index++;
}
return (dest);
}

/**
* string_long - string length
* @str:character
* Return: integer i
*/

int string_long(char *str)
{
int index;

for (index = 0; str[index] != '\0'; index++)
{
continue;
}
return (index);
}

/**
* convert_to_integer - convert to integer
* @str:string character
* Return:integer
*/
int convert_to_integer(char *str)
{
int index, j, num, sign;

index = num = 0;
sign = 1;
while ((str[index] < '0' || str[index] > '9') && (str[index] != '\0'))
{
if (str[index] == '-')
sign *= -1;
index++;
}
j = index;
while ((str[j] >= '0') && (str[j] <= '9'))
{
num = (num * 10) + sign * ((str[j]) - '0');
j++;
}
return (num);
}
/**
* print_string - get a string
* @str:pointer character
* return:void
*/
void print_string(char *str)
{
int index;

for (index = 0; str[index] != '\0'; index++)
{
print_ch(str[index]);
}
print_ch('\n');
return;
}
