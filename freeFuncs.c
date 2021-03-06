#include "monty.h"

/**
* freeArr - frees an array of chars.
* @arrs: the array to be freed.
* Return: void
**/
void freeArr(char **arrs)
{
int i;
int len = globaldata->linecount;
if (*arrs == NULL)
return;
for (i = 0; i < len; i++)
{
if (arrs[i] != NULL)
free(arrs[i]);
}
free(arrs);
arrs = NULL;
}

/**
* freeGlobal - frees all global data.
* Return: void
**/
void freeGlobal(void)
{
if (strcmp(globaldata->filepath, "") != 0)
free(globaldata->filepath);
if (strcmp(globaldata->number, "") != 0)
free(globaldata->number);
}

/**
* freeStack - frees the stack.
* Return: void
**/
void freeStack(void)
{
stack_t *stack;
if (!globaldata->top)
return;
while (globaldata->top)
{
stack = globaldata->top;
globaldata->top = globaldata->top->prev;
free(stack);
}
}
