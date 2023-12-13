#include "shell.h"

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"

/**
* parse_input - Split input into words
* @line: The input
*
* Return: Null-terminated array of words
*/
char **parse_input(char *line)
{
int bufsize = TOKEN_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token, *token_end;
if (!tokens)
perror("allocation error");
exit(EXIT_FAILURE);

token = line;
while (1)
{
while (*token == ' ')
token++;

if (*token == '\0')
break;
token_end = token;
while (*token_end != ' ' && *token_end != '\0')
{
token_end++;
}
if (*token_end == ' ')
{
*token_end = '\0';
token_end++;
}
tokens[position] = token;
position++;
if (position >= bufsize)
{
bufsize += TOKEN_BUFSIZE;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
perror("allocation error");
exit(EXIT_FAILURE);

}
token = token_end;
}
tokens[position] = NULL;
return (tokens);
}
