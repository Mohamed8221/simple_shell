#include "shell.h"

/**
* print_custom_error - Print Custom Error
* @argv:Program
* @count:Count
* @command:Command
* Return: Void
*/
void print_custom_error(char **argv, int count, char **command)
{
char *num;

PRINT(argv[0]);
PRINT(": ");
num = integer_to_string(count);
PRINT(num);
free(num);
PRINT(": ");
PRINT(command[0]);
PRINT(": Illegal number: ");
PRINT(command[1]);
PRINT("\n");
}
