#include "shell.h"

/**
* main - Entry point
* @argc: Argument count
* @argv: Argument vector
*
* Return: Always 0 (Success)
*/
int main(int argc, char **argv)
{
if (argc > 1)
{
FILE *file = fopen(argv[1], "r");
char *line;

if (!file)
{
perror("Error opening file");
return (EXIT_FAILURE);
}

while ((line = get_line_from_file(file)) != NULL)
{
free(line);
}

fclose(file);
}
else
{
return (shell_loop());
}

return (EXIT_SUCCESS);
}
