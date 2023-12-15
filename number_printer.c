#include "shell.h"

/**
* pr_num -Print Unsigned Int Putchar
* @num: Unisigned Integer
* Return: Void
*/
void pr_num(unsigned int num)
{
unsigned int temp;

temp = num;

if ((temp / 10) > 0)
pr_num(temp / 10);

putchar(temp % 10 + '0');
}

/**
* pr_int -Print Number Putchar
* @num: Integer
* Return: void
*/
void pr_int(int num)
{
unsigned int temp = num;

if (num < 0)
{
putchar('-');
temp = -temp;
}
if ((temp / 10) > 0)
pr_num(temp / 10);

putchar(temp % 10 + '0');
}
