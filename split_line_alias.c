#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
* split_line - Split a line into separate commands
* @line: The line to split
* @delim: The delimiter to split by
*
* Return: Null-terminated array of commands
*/
char **split_line(char *line, char *delim)
{
int bufsize = MAX_COMMANDS, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token_start = line;
char *token_end;
if (!tokens)
perror("allocation error");
exit(EXIT_FAILURE);
while (1)
{
if (strcmp(line, "") == 0)
{
free(line);
continue;
}
token_end = strchr(token_start, *delim);
if (token_end == NULL)
{
tokens[position] = trim_whitespace(strdup(token_start));
position++;
break;
}
else
{
*token_end = '\0';
tokens[position] = trim_whitespace(strdup(token_start));
position++;
token_start = token_end + 1;
}

if (position >= bufsize)
{
bufsize += MAX_COMMANDS;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
perror("allocation error");
exit(EXIT_FAILURE);
}
}
tokens[position] = NULL;
return (tokens);
}
alias_t alias_table[MAX_ALIAS_NUM];
int alias_count = 0;

/**
* print_aliases - Print all aliases
*/
void print_aliases(void)
{
int i;

for (i = 0; i < alias_count; i++)
{
printf("%s='%s'\n", alias_table[i].name, alias_table[i].value);
}
}

/**
* print_alias - Print the value of an alias
* @arg: The name of the alias
*/
void print_alias(char *arg)
{
int j;

for (j = 0; j < alias_count; j++)
{
if (strcmp(alias_table[j].name, arg) == 0)
{
printf("%s='%s'\n", alias_table[j].name, alias_table[j].value);
break;
}
}
}

/**
* set_alias - Set the value of an alias
* @arg: The argument in the form name=value
*/
void set_alias(char *arg)
{
char *equal_sign = strchr(arg, '=');
char *name = arg;
char *value = equal_sign + 1;
int j;

*equal_sign = '\0';

for (j = 0; j < alias_count; j++)
{
if (strcmp(alias_table[j].name, name) == 0)
{
strncpy(alias_table[j].value, value, MAX_ALIAS_VALUE - 1);
alias_table[j].value[MAX_ALIAS_VALUE - 1] = '\0';
break;
}
}

if (j == alias_count && alias_count < MAX_ALIAS_NUM)
{
strncpy(alias_table[j].name, name, MAX_ALIAS_NAME - 1);
alias_table[j].name[MAX_ALIAS_NAME - 1] = '\0';
strncpy(alias_table[j].value, value, MAX_ALIAS_VALUE - 1);
alias_table[j].value[MAX_ALIAS_VALUE - 1] = '\0';
alias_count++;
}
}
/**
* handle_alias - Handle the alias command
* @args: Null-terminated list of arguments
*
* Return: 1 if the shell should continue running, 0 if it should terminate
*/
int handle_alias(char **args)
{
char *equal_sign;
if (args[1] == NULL)
{
print_aliases();
return (1);
}

equal_sign = strchr(args[1], '=');

if (equal_sign)
{
set_alias(args[1]);
return (1);
}
else
{
print_alias(args[1]);
return (1);
}
}
