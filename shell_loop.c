#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
* shell_loop - Main shell loop
*
* Return: Always 0 (Success)
*/
int shell_loop(void)
{
char *line;
char **args;
int status = 1;
int i;
char *comment;
char status_str[12];
char pid_str[12];
char *path_str;
char **commands;

do {
printf("$ ");
line = get_line();
comment = strchr(line, '#');
if (strcmp(line, "") == 0)
{
free(line);
continue;
}
if (comment)
*comment = '\0';
/* Handle variable replacement */
sprintf(status_str, "%d", status);  /* Convert status to a string */
line = replace_str(line, "$?", status_str);
sprintf(pid_str, "%d", getpid());  /* Convert pid to a string */
line = replace_str(line, "$$", pid_str);
path_str = _getenv("PATH");  /* Get PATH as a string */
line = replace_str(line, "$PATH", path_str);
commands = split_line(line, "&&||");
for (i = 0; commands[i] != NULL; i++)
{
args = split_line(commands[i], " \t\r\n\a");
if (strstr(line, "&&") && status != 0)
break;

if (strstr(line, "||") && status == 0)
break;

status = execute_command(args);
free(args);
}
free(commands);
free(line);
} while (status);
return (EXIT_SUCCESS);
}
