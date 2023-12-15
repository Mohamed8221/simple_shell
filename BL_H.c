#include "shell.h"

/**
* exit_command - Exit status shell
* @cmd: Parsed command
* @input: User input
* @args:Program name
* @count:Execute count
* Return: Void
*/
void  exit_command(char **cmd, char *input, char **args, int count)
{
int status, index = 0;

if (cmd[1] == NULL)
{
free(input);
free(cmd);
exit(EXIT_SUCCESS);
}
while (cmd[1][index])
{
if (is_alpha_betic(cmd[1][index++]) != 0)
{
show_error(input, count, args);
break;
}
status = convert_to_integer(cmd[1]);
free(input);
free(cmd);
exit(status);
}
}


/**
* ch_dir - Change directories
* @cmd: Parsed command
* @status: Status last command executed
* Return: 0 Success 1 Failed (For Old Pwd Always 0 Case No Old PWD)
*/
int ch_dir(char **cmd, __attribute__((unused))int status)
{
int index = -1;
char path[PATH_MAX];
char *oldpwd = getenv("PWD");

if (cmd[1] == NULL)
index = chdir(getenv("HOME"));
else if (compare_strs(cmd[1], "-") == 0)
{
if (getenv("OLDPWD") != NULL)
{
printf("%s\n", getenv("OLDPWD"));
index = chdir(getenv("OLDPWD"));
}
else
{
printf("hsh: cd: OLDPWD not set\n");
return (0);
}
}
else
index = chdir(cmd[1]);

if (index != -1)
{
getcwd(path, sizeof(path));
setenv("OLDPWD", oldpwd, 1);
setenv("PWD", path, 1);
}
else
{
perror("hsh");
return (-1);
}

return (0);
}

/**
* exe_env - Display environment variable
* @cmd:Parsed command
* @status:Status of last command executed
* Return:Always 0
*/
int exe_env(__attribute__((unused)) char **cmd,
__attribute__((unused)) int status)
{
size_t size;
int index;

for (size = 0; environ[size] != NULL; size++)
{
index = string_long(environ[size]);
write(1, environ[size], index);
write(STDOUT_FILENO, "\n", 1);
}
return (0);
}

/**
* dis_help - Displaying help for builtin
* @cmd:Parsed command
* @status: Status of last command executed
* Return: 0 Success -1 Fail
*/
int dis_help(char **cmd, __attribute__((unused))int status)
{
int file, write_status, read_status = 1;
char character;

file = open(cmd[1], O_RDONLY);
if (file < 0)
{
perror("Error");
return (0);
}
while (read_status > 0)
{
read_status = read(file, &character, 1);
write_status = write(STDOUT_FILENO, &character, read_status);
if (write_status < 0)
{
return (-1);
}
}
putchar('\n');
return (0);
}
/**
* exe_echo - Execute echo cases
* @status: Status of last command executed
* @cmd: Parsed command
* Return: Always 0 Or Execute normal echo
*/
int exe_echo(char **cmd, int status)
{
char *path;
unsigned int  process_id = getppid();

if (compare_strs(cmd[1], "$?") == 0)
{
pr_num(status);
PRINT("\n");
}
else if (compare_strs(cmd[1], "$$") == 0)
{
pr_num(process_id);
PRINT("\n");

}
else if (compare_strs(cmd[1], "$PATH") == 0)
{
path = getenv("PATH");
PRINT(path);
PRINT("\n");
free(path);

}
else
return (exe_echo(cmd, status));

return (1);
}
