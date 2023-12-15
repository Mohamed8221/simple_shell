#include "shell.h"

/**
**reallocate_mem -  Reallocates a memory block
*@ptr: Pointer
*@old_size: Old Size
*@new_size: New Size
*Return: Void
*/
void *reallocate_mem(void *ptr, unsigned int old_size,
unsigned int new_size)
{
void *new_ptr;

if (new_size == old_size)
return (ptr);
if (new_size == 0 && ptr)
{
free(ptr);
return (NULL);
}
new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);
if (ptr == NULL)
{
fill_mem(new_ptr, '\0', new_size);
free(ptr);
}
else
{
copy_mem(new_ptr, ptr, old_size);
free(ptr);
}
return (new_ptr);

}
/**
* free_mem - Free array of char pointer and char pointer
* @cmd:Array Pointer
* @str:Char Pointer
* Return: Void
*/
void free_mem(char **cmd, char *str)
{
free(cmd);
free(str);
cmd = NULL;
str = NULL;
}

/**
* copy_mem - Copy byte from source to destination
* @dest: Destination Pointer
* @src: Source Pointer
* @size: Size (How much you will copy)
*Return: Void Pointer
*/
char *copy_mem(char *dest, char *src, unsigned int size)
{
unsigned int i;

for (i = 0; i < size; i++)
{
dest[i] = src[i];
}
return (dest);
}
/**
* fill_mem - Fill an array by constant byte
* @arr:Void Pointer
* @val: Int
* @len:Length Int
*Return: Void Pointer
*/
void *fill_mem(void *mem, int val, unsigned int len)
{
char *ch = mem;
unsigned int i = 0;

while (i < len)
{
*ch = val;
ch++;
i++;
}
return (mem);
}
/**
* allocate_mem -  Allocates memory for an array, using malloc.
* @size: Size
* Return: Void Pointer
*/
void *allocate_mem(unsigned int size)
{
char *ch;
unsigned int i;

if (size == 0)
return (NULL);
ch = malloc(size);
if (ch == NULL)
return (NULL);
for (i = 0; i < size; i++)
{
ch[i] = '\0';
}
return (ch);
}
