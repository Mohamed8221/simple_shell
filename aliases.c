#include "shell.h"

/**
* handle_alias - Handles the alias command
* @args: Arguments
* @alias_list: List of aliases
*
* Return: 1 on success
*/
int handle_alias(char **args, alias_t **alias_list)
{
alias_t *new_alias, *temp;

if (args[1] == NULL)
{
/* If no arguments, print all aliases */
for (temp = *alias_list; temp != NULL; temp = temp->next)
{
printf("%s='%s'\n", temp->name, temp->value);
}
}
else
{
char *name = strtok(args[1], "=");
char *value = strtok(NULL, "=");

if (value != NULL)
{
/* If argument contains '=', add new alias or update existing one */
for (temp = *alias_list; temp != NULL; temp = temp->next)
{
if (strcmp(temp->name, name) == 0)
{
/* Update existing alias */
free(temp->value);
temp->value = strdup(value);
return (1);
}
}

/* Add new alias */
new_alias = malloc(sizeof(alias_t));
new_alias->name = strdup(name);
new_alias->value = strdup(value);
new_alias->next = *alias_list;
*alias_list = new_alias;
}
else
{
/* If argument doesn't contain '=', print the value of the alias */
for (temp = *alias_list; temp != NULL; temp = temp->next)
{
if (strcmp(temp->name, name) == 0)
{
printf("%s='%s'\n", temp->name, temp->value);
break;
}
}
}
}
return (1);
}
