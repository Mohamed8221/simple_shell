#include "shell.h"
/**
* copy_str - Source To Destination Char
* @dest:Destination
* @src:Source
* Return: Copie Of Char
*/
char *copy_str(char *dest, char *src)
{
int i;

i = 0;
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}

/**
* concat_str - Two String
* @str1:First String
* @str2:Second String
* Return:First String + Second String Char
*/
char *concat_str(char *str1, char *str2)
{
char *new_str = str1;

while (*str1 != '\0')
{
str1++;
}

while (*str2 != '\0')
{
*str1 = *str2;
str1++;
str2++;
}
*str1 = '\0';
return (new_str);
}

/**
* find_ch - Locate Character In String
* @str:String Search In
* @ch:Char To Search For
* Return: Pointer To Char*
*/
char *find_ch(char *str, char ch)
{

do {

if (*str == ch)
{
break;
}
}	while (*str++);
return (str);
}

/**
* compare_str_n - Compare Amount Strings
* @str1: String
* @str2: String
* @len: Amount Of Characters
*
* Return: 1 If The Strings Don't Match Otherwise 0
*/
int compare_str_n(const char *str1, const char *str2, size_t len)
{
size_t i;

if (str1 == NULL)
return (-1);
for (i = 0; i < len && str2[i]; i++)
{
if (str1[i] != str2[i])
{
return (1);
}
}
return (0);
}
/**
* dupli_str - Duplicate A String
* @str:String
* Return: Null
*/
char *dupli_str(char *str)
{
size_t len, index;
char *new_str;

len = string_long(str);
new_str = malloc(sizeof(char) * (len + 1));
if (!new_str)
{
return (NULL);
}

for (index = 0; index <= len; index++)
{
new_str[index] = str[index];
}

return (new_str);
}
