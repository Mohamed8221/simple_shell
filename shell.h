#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>


/**
* struct builtin - contain builtin to handle and function
* @command:pointer to char
* @fun:fun to execute when builtin true
*/

typedef struct  builtin
{
char *command;
int (*fun)(char **line, int error);
} builtin_t;

/**
* struct alias - Struct for storing shell aliases
* @name: Name of the alias
* @value: Value of the alias
* @next: Pointer to the next alias
*
* Description: This struct is used for storing aliases in the shell.
*/
typedef struct alias
{
char *name;
char *value;
struct alias *next;
} alias_t;
extern alias_t *alias_list;

#define BUFFER_SIZE 1024
#define DELIMITER " \t\r\n\a"
#define PRINT(c) (write(STDOUT_FILENO, c, string_long(c)))


extern char **environ;

char *str_tokenizer(char *str, const char *del);
unsigned int del_check(char ch, const char *check);
char *copy_string_n(char *dest, char *src, int len);
int string_long(char *str);
int print_ch(char ch);
int convert_to_integer(char *str);
void print_string(char *str);
int compare_strs(char *str1, char *str2);
int is_alpha_betic(int ch);
void rev_str(char *str, int len);
int integer_long(int num);
char *integer_to_string(unsigned int num);
char *concat_str(char *str1, char *str2);
char *copy_str(char *dest, char *src);
char *find_char(char *str, char ch);
int compare_str_n(const char *str1, const char *str2, size_t len);
char *dupli_str(char *str);


void free_environment(char **env);
void *fill_mem(void *mem, int val, unsigned int len);
char *copy_mem(char *dest, char *src, unsigned int size);
void *allocate_mem(unsigned int size);
void *reallocate_mem(void *ptr, unsigned int old_size,
unsigned int new_size);
void free_mem(char **cmd, char *str);


void dis_pr(void);
void signal_h(int signal);
char *take_input(void);
int path_H(char **cmd);
char *take_environment(char *name);
char **par_input(char *input);
int exe_blin(char **cmd, int status);
void r_file(char *filename, char **args);
char *b_command(char *cmd, char *dir);
int bltin_check(char **cmd);
void st_env(char **env);
int exe_comm_and(char **cmd, char *input, int count, char **args);
void process_input(char *line, int count, FILE *file, char **args);
void exit_from_file(char **cmd, char *line, FILE *file);


void rem_hash(char *buf);
int rec_history(char *input);
int dis_history(char **cmd, int status);
int exe_env(char **cmd, int status);
int ch_dir(char **cmd, int status);
int dis_help(char **cmd, int status);
int exe_echo(char **cmd, int status);
void exit_command(char **cmd, char *input, char **args, int count);
int echo_viewer(char **cmd, int status);
int handle_alias(char **args, alias_t **alias_list);

void pr_num(unsigned int num);
void pt_int(int num);
void show_error(char *input, int count, char **argv);
void print_custom_error(char **argv, int count, char **command);

#endif
