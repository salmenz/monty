#include "monty.h"

/**
* fileHandle - handles Monty file
* @path: path of file
* Return: the file lines in an array
*/
char **fileHandle(const char *path)
{
char *linestr = NULL, *token, **instruct;
size_t linestrsize = 0;
int linesize;
globaldata->fileadress = fopen(path, "r");
debugFile(globaldata->fileadress, path);
globaldata->linecount = 0;
linesize = getline(&linestr, &linestrsize, globaldata->fileadress);
while (linesize >= 0)
{
globaldata->linecount++;
linesize = getline(&linestr, &linestrsize, globaldata->fileadress);
}
instruct = malloc(sizeof(char *) * globaldata->linecount);
debugMemArr(instruct);
rewind(globaldata->fileadress);
linesize = getline(&linestr, &linestrsize, globaldata->fileadress);
token = strtok(linestr, "\n");
globaldata->linecount = 0;
while (linesize >= 0)
{
instruct[globaldata->linecount] = malloc(sizeof(char) * linesize - 1);
debugMem(instruct[globaldata->linecount]);
strcpy(instruct[globaldata->linecount], token);
globaldata->linecount++;
linesize = getline(&linestr, &linestrsize, globaldata->fileadress);
token = strtok(linestr, "\n");
}
free(linestr);
linestr = NULL;
fclose(globaldata->fileadress);
return (instruct);
}
