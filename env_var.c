#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* create_env_var - Create or modify an environment variable
* @var: The variable
* @value: The value
*
* Return: 0 if successful, -1 otherwise
*/
int create_env_var(char *var, char *value)
{
if (setenv(var, value, 1) == -1)
{
perror("Error setting environment variable");
return (-1);
}

return (0);
}

/**
* remove_env_var - Remove an environment variable
* @var: The variable
*
* Return: 0 if successful, -1 otherwise
*/
int remove_env_var(char *var)
{
if (unsetenv(var) == -1)
{
perror("Error unsetting environment variable");
return (-1);
}

return (0);
}

/**
* print_env - Print environment variables
*
* Return: 1 if successful, 0 otherwise
*/
int print_env(void)
{
int i = 0;

while (environ[i] != NULL)
{
printf("%s\n", environ[i]);
i++;
}

return (1);
}

/**
* handle_cd - Handle the cd command
* @args: Null-terminated list of arguments
*
* Return: 1 if the shell should continue running, 0 if it should terminate
*/
int handle_cd(char **args)
{
char *home_dir = _getenv("HOME");
char *old_dir = _getenv("OLDPWD");
char *new_dir;
char cwd[1024];

if (args[1] == NULL || strcmp(args[1], "~") == 0)
{
new_dir = home_dir;
}
else if (strcmp(args[1], "-") == 0)
{
new_dir = old_dir;
}
else
{
new_dir = args[1];
}

if (chdir(new_dir) != 0)
{
perror("Error changing directory");
return (1);
}
if (getcwd(cwd, sizeof(cwd)) != NULL)
{
setenv("PWD", cwd, 1);
}
else
{
perror("Error getting current directory");
return (1);
}

return (1);
}
