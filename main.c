#include "shell.h"

/**
* main - Simple Shell
* @argc: Argument Count
* @argv:Argument Value
* Return: Exit Value
*/

int main(__attribute__((unused))
int argc, char **argv)
{
char *input, **command;
int counter = 0, status = 1, last_status = 0;

if (argv[1] != NULL)
r_file(argv[1], argv);
signal(SIGINT, signal_h);
while (status)
{
counter++;
if (isatty(STDIN_FILENO))
dis_pr();
input = take_input();
if (input[0] == '\0')
{
continue;
}
rec_history(input);
command = par_input(input);
if (compare_strs(command[0], "exit") == 0)
{
exit_command(command, input, argv, counter);
}
else if (bltin_check(command) == 0)
{
last_status = exe_blin(command, last_status);
free_mem(command, input);
continue;
}
else
{
last_status = exe_comm_and(command, input, counter, argv);

}
free_mem(command, input);
}
return (status);
}
/**
* bltin_check - check builtin
* @cmd:command
* Return: 0 Success -1 Fail
*/
int bltin_check(char **cmd)
{
builtin_t builtin[] = {
{"cd", NULL},
{"help", NULL},
{"echo", NULL},
{"history", NULL},
{NULL, NULL}
};
int index = 0;
if (*cmd == NULL)
{
return (-1);
}

while ((builtin + index)->command)
{
if (compare_strs(cmd[0], (builtin + index)->command) == 0)
return (0);
index++;
}
return (-1);
}

/**
* st_env - Setup Environment Variable
* @env: Environment Variable
* Return: Void
*/
void st_env(char **env)
{
int i;

for (i = 0; environ[i]; i++)
env[i] = dupli_str(environ[i]);
env[i] = NULL;
}
