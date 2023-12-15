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
dir = str_tokenizer(path, ":");
while (dir != NULL)
{
full_path = b_command(*cmd, dir);
if (stat(full_path, &buf) == 0)
{
*cmd = dupli_str(full_path);
free(full_path);
free(path);
return (0);
}
free(full_path);
dir = str_tokenizer(NULL, ":");
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

len = string_long(dir) + string_long(cmd) + 2;
command = malloc(sizeof(char) * len);
if (command == NULL)
{
return (NULL);
}

memset(command, 0, len);

command = concat_str(command, dir);
command = concat_str(command, "/");
command = concat_str(command, cmd);

return (command);
}
/**
* take_environment - Gets The Value Of Environment Variable By Name
* @name: Environment Variable Name
* Return: The Value of the Environment Variable Else NULL.
*/
char *take_environment(char *name)
{
size_t name_len, value_len;
char *value;
int i, j, k;

name_len = string_long(name);
for (i = 0 ; environ[i]; i++)
{
if (compare_str_n(name, environ[i], name_len) == 0)
{
value_len = string_long(environ[i]) - name_len;
value = malloc(sizeof(char) * value_len);
if (!value)
{
free(value);
perror("unable to allocate");
return (NULL);
}

k = 0;
for (j = name_len + 1; environ[i][j]; j++, k++)
{
value[k] = environ[i][j];
}
value[k] = '\0';

return (value);
}
}

return (NULL);
}
