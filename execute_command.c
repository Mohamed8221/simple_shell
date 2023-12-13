#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
* execute_command - Execute shell command
* @args: Null-terminated list of arguments
*
* Return: 1 if the shell should continue running,
*         0 if it should terminate
*/
int execute_command(char **args)
{
if (args[0] == NULL)
{
return (1);
}

if (strcmp(args[0], "exit") == 0)
return (handle_exit(args));

if (strcmp(args[0], "cd") == 0)
return (handle_cd(args));

if (strcmp(args[0], "env") == 0)
return (print_env());

if (strcmp(args[0], "setenv") == 0)
return (handle_setenv(args));

if (strcmp(args[0], "alias") == 0)
return (handle_alias(args));

if (strcmp(args[0], "unsetenv") == 0)
return (handle_unsetenv(args));

return (execute_external_command(args));
}

/**
* handle_exit - Handle the exit command
* @args: Null-terminated list of arguments
*
* Return: The exit status
*/
int handle_exit(char **args)
{
int status = 0;

if (args[1] != NULL)
{
status = atoi(args[1]);
}

exit(status);
}

/**
* handle_setenv - Handle the setenv command
* @args: Null-terminated list of arguments
*
* Return: 1 if successful, 0 otherwise
*/
int handle_setenv(char **args)
{
if (args[1] != NULL && args[2] != NULL)
{
return (create_env_var(args[1], args[2]));
}
else
{
fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
return (1);
}
}

/**
* handle_unsetenv - Handle the unsetenv command
* @args: Null-terminated list of arguments
*
* Return: 1 if successful, 0 otherwise
*/
int handle_unsetenv(char **args)
{
if (args[1] != NULL)
{
return (remove_env_var(args[1]));
}
else
{
fprintf(stderr, "Usage: unsetenv VARIABLE\n");
return (1);
}
}

/**
* execute_external_command - Execute an external command
* @args: Null-terminated list of arguments
*
* Return: 1 if the shell should continue running,
*         0 if it should terminate
*/
int execute_external_command(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("lsh");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("lsh");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (1);
}
