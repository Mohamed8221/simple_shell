#include "shell.h"

/**
* take_input - Read The Input By User From Stdin
* Return: Input
*/
char *take_input(void)
{
int index, buffer_size = BUFSIZ, read_status;
char ch = 0;
char *buffer = malloc(buffer_size);

if (buffer == NULL)
{
free(buffer);
return (NULL);
}

for (index = 0; ch != EOF && ch != '\n'; index++)
{
fflush(stdin);
read_status = read(STDIN_FILENO, &ch, 1);
if (read_status == 0)
{
free(buffer);
exit(EXIT_SUCCESS);
}
buffer[index] = ch;
if (buffer[0] == '\n')
{
free(buffer);
return ("\0");
}
if (index >= buffer_size)
{
buffer = reallocate_mem(buffer, buffer_size, buffer_size + 1);
if (buffer == NULL)
{
return (NULL);
}
}
}
buffer[index] = '\0';
rem_hash(buffer);
return (buffer);
}
/**
* rem_hash - remove everything after #
* @buf: input;
* Return:void
*/
void rem_hash(char *buf)
{
int index;

for (index = 0; buf[index] != '\0'; index++)
{
if (buf[index] == '#')
{
buf[index] = '\0';
break;
}
}
}
