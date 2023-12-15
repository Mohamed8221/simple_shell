#include "shell.h"

/**
* compare_strs - Compare Strings
* @str1:First String
* @str2:Second String
* Return: Difference
*/
int compare_strs(char *str1, char *str2)
{
int diff = 0, index, len1, len2;

len1 = string_long(str1);
len2 = string_long(str2);

if (str1 == NULL || str2 == NULL)
return (1);
if (len1 != len2)
return (1);
for (index = 0; str1[index]; index++)
{
if (str1[index] != str2[index])
{
diff = str1[index] - str2[index];
break;
}
else
continue;
}
return (diff);
}

/**
* is_alpha_betic - Check if Alphabetic
*@ch: Character
* Return: 1 If True 0 If Not
*/
int is_alpha_betic(int ch)
{
if (((ch >= 97) && (ch <= 122)) || ((ch >= 65) && (ch <= 90)))
{
return (1);
}
else
{
return (0);
}
}

/**
* integer_to_string - Convert Integer To Char
* @num: Integer
* Return: Char Pointer
*/
char *integer_to_string(unsigned int num)
{
int len = 0, index = 0;
char *str;

len = integer_long(num);
str = malloc(len + 1);
if (!str)
return (NULL);
*str = '\0';
while (num / 10)
{
str[index] = (num % 10) + '0';
num /= 10;
index++;
}
str[index] = (num % 10) + '0';
rev_str(str, len);
str[index + 1] = '\0';
return (str);
}

/**
* rev_str - Reverse Array
* @str:Array To Reverse
* @len:Length Of Array
* Return: Void(Reverse Array)
*/
void rev_str(char *str, int len)
{
int index;
char temp;

for (index = 0; index < (len / 2); index++)
{
temp = str[index];
str[index] = str[(len - 1) - index];
str[(len - 1) - index] = temp;
}
}

/**
* integer_long - Determine Length
* @num: Number
* Return: Length
*/
int integer_long(int num)
{
int len = 0;

while (num != 0)
{
len++;
num /= 10;
}
return (len);
}
