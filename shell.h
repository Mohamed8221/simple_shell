#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMANDS 100
#define MAX_ALIAS_NUM 100
#define MAX_ALIAS_NAME 100
#define MAX_ALIAS_VALUE 1000

extern char **environ;

/**
* struct s_node - linked list for line chunks
* @data: line chunk
* @next: next node
*/
typedef struct s_node
{
char *data;
struct s_node *next;
} t_node;

/**
* struct alias - alias structure
* @name: alias name
* @value: alias value
*/
typedef struct alias
{
char name[MAX_ALIAS_NAME];
char value[MAX_ALIAS_VALUE];
} alias_t;

extern alias_t alias_table[MAX_ALIAS_NUM];
extern int alias_count;

void print_aliases(void);
void print_alias(char *arg);
void set_alias(char *arg);
int handle_alias(char **args);
char *get_line(void);
char *replace_str(char *str, char *old, char *new);
char **parse_input(char *line);
int execute_command(char **args);
int create_env_var(char *var, char *value);
int remove_env_var(char *var);
int execute_external_command(char **args);
int handle_unsetenv(char **args);
char *_getenv(const char *name);
int handle_setenv(char **args);
int handle_exit(char **args);
int shell_loop(void);
char *trim_whitespace(char *str);
int print_env(void);
char *get_line_from_file(FILE *file);
int handle_cd(char **args);
int separator(char *line);
char **split_line(char *line, char *delim);

#endif /* SHELL_H */
