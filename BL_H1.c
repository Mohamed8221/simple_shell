#include "shell.h"

/**
* dis_history - Display History Of User Input
* @cmd:Parsed Command
* @status:Status Of Last Execute
* Return: 0 Success -1 Fail
*/
int dis_history(__attribute__((unused))
char **cmd, __attribute__((unused))int status)
{
char *file_name = ".simple_shell_history";
FILE *file;
char *line = NULL;
size_t n = 0;
int i = 0;
char *result;

file = fopen(file_name, "r");
if (file == NULL)
{
return (-1);
}
while ((getline(&line, &n, file)) != -1)
{
i++;
result = integer_to_string(i);
PRINT(result);
free(result);
PRINT(" ");
PRINT(line);

}
if (line)
free(line);
fclose(file);
return (0);
}
/**
* echo_viewer - execute Normal Echo
* @cmd: Parsed Command
* Return: 0 Success -1 Fail
*/
int echo_viewer(char **cmd, int status)
{
pid_t pid;

pid = fork();
if (pid == 0)
{
if (execve("/bin/echo", cmd, environ) == -1)
{
return (-1);
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
return (-1);
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
