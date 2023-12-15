#include "shell.h"

/**
* dis_pr - Display Shell Prompt
*/
void dis_pr(void)
{
PRINT("$ ");
}

/**
* show_error - Display Error
* @input:Input
* @count:Count Loop
* @argv:Program
* Return: Void
*/
void show_error(char *input, int count, char **argv)
{
char *num;

PRINT(argv[0]);
PRINT(": ");
num = integer_to_string(count);
PRINT(num);
free(num);
PRINT(": ");
PRINT(input);
PRINT(": missing\n");
}
