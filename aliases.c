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
temp = *alias_list;
while (temp != NULL)
{
printf("%s='%s'\n", temp->name, temp->value);
temp = temp->next;
}
}
else if (strchr(args[1], '=') != NULL)
{
/* If argument contains '=', add new alias */
new_alias = malloc(sizeof(alias_t));
new_alias->name = strtok(args[1], "=");
new_alias->value = strtok(NULL, "=");
new_alias->next = *alias_list;
*alias_list = new_alias;
}
else
{
/* If argument doesn't contain '=', print the value of the alias */
temp = *alias_list;
while (temp != NULL)
{
if (strcmp(temp->name, args[1]) == 0)
{
printf("%s='%s'\n", temp->name, temp->value);
break;
}
temp = temp->next;
}
}
return (1);
}
