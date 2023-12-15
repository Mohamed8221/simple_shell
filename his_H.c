#include "shell.h"

/**
* rec_history - Fill File By User Input
* @input: User Input
* Return: -1 Fail 0 Success
*/
int rec_history(char *input)
{
char *filename = ".simple_shell_history";
ssize_t file, write_status;
int length = 0;

if (!filename)
return (-1);
file = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
if (file < 0)
return (-1);
if (input)
{
while (input[length])
length++;
write_status = write(file, input, length);
if (write_status < 0)
return (-1);
}
return (1);
}
