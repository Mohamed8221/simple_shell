#include "shell.h"

/**
* is_delim - Checks there is another char* match
* @ch: Character
* @check: Checker
* Return: 1 Success, 0 Failed
*/
unsigned int del_check(char ch, const char *check)
{
unsigned int index;

for (index = 0; check[index] != '\0'; index++)
{
if (ch == check[index])
return (1);
}
return (0);
}

/**
* string_tokenizer - My own strtrok
* @str: String Character
* @del: Delimiter
* Return: Pointer To The Next Token Or NULL
*/
char *str_tokenizer(char *str, const char *del)
{
static char *start;
static char *next;
unsigned int index;

if (str != NULL)
next = str;
start = next;
if (start == NULL)
return (NULL);
for (index = 0; start[index] != '\0'; index++)
{
if (del_check(start[index], del) == 0)
break;
}
if (next[index] == '\0' || next[index] == '#')
{
next = NULL;
return (NULL);
}
start = next + index;
next = start;
for (index = 0; next[index] != '\0'; index++)
{
if (del_check(next[index], del) == 1)
break;
}
if (next[index] == '\0')
next = NULL;
else
{
next[index] = '\0';
next = next + index + 1;
if (*next == '\0')
next = NULL;
}
return (start);
}
