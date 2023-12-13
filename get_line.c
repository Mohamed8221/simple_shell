#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define READ_LINE_BUFSIZE 1024

/**
* get_line - Read line from stdin
*
* Return: The line from stdin
*/
char *get_line(void)
{
int bufsize = READ_LINE_BUFSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;

if (!buffer)
{
perror("allocation error");
exit(EXIT_FAILURE);
}

while (1)
{
c = getchar();

if (c == EOF || c == '\n')
{
buffer[position] = '\0';
return (buffer);
}
else
{
buffer[position] = c;
}

position++;

if (position >= bufsize)
{
bufsize += READ_LINE_BUFSIZE;
buffer = realloc(buffer, bufsize);
if (!buffer)
{
perror("allocation error");
exit(EXIT_FAILURE);
}
}
}
}

/**
* get_line_from_file - Read a line from a file
* @file: The file to read from
*
* Return: The line read from the file
*/
char *get_line_from_file(FILE *file)
{
int bufsize = READ_LINE_BUFSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;

if (!buffer)
{
perror("allocation error");
exit(EXIT_FAILURE);
}

while (1)
{
c = fgetc(file);

if (c == EOF || c == '\n')
{
buffer[position] = '\0';
return (buffer);
}
else
{
buffer[position] = c;
}

position++;

if (position >= bufsize)
{
bufsize += READ_LINE_BUFSIZE;
buffer = realloc(buffer, bufsize);
if (!buffer)
{
perror("allocation error");
exit(EXIT_FAILURE);
}
}
}
}

/**
* _getenv - Get the value of an environment variable
* @name: The name of the variable to get
*
* Return: The value of the variable, or NULL if the variable does not exist
*/
char *_getenv(const char *name)
{
int i = 0;
int len = strlen(name);

while (environ[i] != NULL)
{
if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
{
return (&environ[i][len + 1]);
}
i++;
}
return (NULL);
}
