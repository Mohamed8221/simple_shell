#include "shell.h"

/**
* parse_input - Parsed Line
* @input:User Input
* Return: Parsed
*/
char **par_input(char *input)
{
char **tokens;
char *token;
int index, buffer = BUFFER_SIZE;

if (input == NULL)
return (NULL);
tokens = malloc(sizeof(char *) * buffer);
if (!tokens)
{
perror("error");
return (NULL);
}

token = str_tokenizer(input, "\n ");
for (index = 0; token; index++)
{
tokens[index] = token;
token = str_tokenizer(NULL, "\n ");
}
tokens[index] = NULL;

return (tokens);
}
