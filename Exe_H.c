#include "shell.h"
/**
* process_input - PARSE Check Command Fork Wait Execute in Line of File
* @line: Line From A File
* @count:Error Counter
* @file:File Descriptor
* @args:Program Name
* Return : Execute A line void
*/
void process_input(char *line, int count, FILE *file, char **args)
{
char **cmd;
int status = 0;

cmd = par_input(line);

if (compare_str_n(cmd[0], "exit", 4) == 0)
{
exit_from_file(cmd, line, file);
}
else if (bltin_check(cmd) == 0)
{
status = exe_blin(cmd, status);
free(cmd);
}
else
{
status = exe_comm_and(cmd, line, count, args);
free(cmd);
}
}

/**
* signal_h - Handle
* @signal:Captured Signal
* Return: Void
*/
void signal_h(int signal)
{
if (signal == SIGINT)
{
PRINT("\n$ ");
}
}
/**
* exit_from_file - Exit Shell Case Of File
* @line: Line From A File
* @cmd: Parsed Command
* @file:File Descriptor
* Return : Case Of Exit in A File Line
*/
void exit_from_file(char **cmd, char *line, FILE *file)
{
int status, index = 0;

if (cmd[1] == NULL)
{
free(line);
free(cmd);
fclose(file);
exit(errno);
}
while (cmd[1][index])
{
if (is_alpha_betic(cmd[1][index++]) < 0)
{
perror("illegal number");
}
}
status = convert_to_integer(cmd[1]);
free(line);
free(cmd);
fclose(file);
exit(status);
}
