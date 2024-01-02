#include "shell.h"

/**
* path_H -  Search in $PATH for executable command
* @cmd: Parsed Input
* Return: 1  Failure  0  Success.
*/
int path_H(char **cmd)
{
char *path, *dir, *full_path;
struct stat buf;

path = take_environment("PATH");
dir = strtok(path, ":");

while (dir != NULL)
{
full_path = b_command(*cmd, dir);
if (stat(full_path, &buf) == 0)
{
free(*cmd);
*cmd = full_path;
free(path);
return (0);
}
free(full_path);
dir = strtok(NULL, ":");
}
free(path);
return (1);
}

/**
* b_command - Build Command
* @cmd: Executable Command
* @dir: Directory Containing Command
*
* Return: Parsed Full Path Of Command Or NULL Case Failed
*/
char *b_command(char *cmd, char *dir)
{
char *command;
size_t len;

len = strlen(dir) + strlen(cmd) + 2;
command = malloc(sizeof(char) * len);
if (command == NULL)
{
return (NULL);
}

strcpy(command, dir);
strcat(command, "/");
strcat(command, cmd);

return (command);
}

/**
* take_environment - Gets The Value Of Environment Variable By Name
* @name: Environment Variable Name
* Return: The Value of the Environment Variable Else NULL.
*/
char *take_environment(char *name)
{
char *value;
int i;

for (i = 0 ; environ[i]; i++)
{
if (strncmp(name, environ[i], strlen(name)) == 0)
{
value = strdup(&environ[i][strlen(name) + 1]);
if (!value)
{
perror("unable to allocate");
return (NULL);
}
return (value);
}
}
return (NULL);
}
