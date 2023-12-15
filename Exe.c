#include "shell.h"

/**
* handle_builtin - Handle Builtin Command
* @cmd: Parsed Command
* @status:status of last Execute
* Return: -1 Fail 0 Success (Return :Execute Builtin)
*/

int exe_blin(char **cmd, int status)
{
builtin_t bi[] = {
{"cd", ch_dir},
{"env", exe_env},
{"help", dis_help},
{"echo", exe_echo},
{"history", dis_history},
{NULL, NULL}
};
int index = 0;

while ((bi + index)->command)
{
if (compare_strs(cmd[0], (bi + index)->command) == 0)
{
return ((bi + index)->fun(cmd, status));
}
index++;
}
return (-1);
}
/**
* exe_comm_and - Execute Simple Shell Command (Fork,Wait,Execute)
* @cmd:Parsed Command
* @input: User Input
* @count:Shell Execution Time Case of Command Not Found
* @args:Program Name
* Return: 1 Case Command Null -1 Wrong Command 0 Command Executed
*/
int exe_comm_and(char **cmd, char *input, int count, char **args)
{
int status;
pid_t pid;

if (*cmd == NULL)
{
return (-1);
}

pid = fork();
if (pid == -1)
{
perror("Error");
return (-1);
}

if (pid == 0)
{
if (compare_str_n(*cmd, "./", 2) != 0 && compare_str_n(*cmd, "/", 1) != 0)
{
path_H(cmd);
}

if (execve(*cmd, cmd, environ) == -1)
{
show_error(cmd[0], count, args);
free(input);
free(cmd);
exit(EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}
wait(&status);
return (0);
}

/**
* read_command - Read Command From File
* @filename:Filename
* @args:Program Name
* Return: -1 or  0
*/

void r_file(char *filename, char **args)
{
FILE *file;
char *line = NULL;
size_t len = 0;
int counter = 0;

file = fopen(filename, "r");
if (file == NULL)
{
exit(EXIT_FAILURE);
}
while ((getline(&line, &len, file)) != -1)
{
counter++;
process_input(line, counter, file, args);

}
if (line)
free(line);
fclose(file);
exit(0);
}
