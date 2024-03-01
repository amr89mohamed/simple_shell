#include "shell.h"
/*
 *to comper  the strings
 */int (compare(const void *a, const void *b))
{
return strcmp(*(const char **)a, *(const char **)b);
}

/*
 * list and sort the directories
 */void listAndSortDirectory(const char *dirname)
{
DIR *dir;
struct dirent *entry;
char *filenames[100];
int count = 0;
int i;
dir = opendir(dirname);
if (dir == NULL)
{
perror("opendir");
return;
}
while ((entry = readdir(dir)) != NULL)
{
if (entry->d_name[0] != '.' && strcmp(entry->d_name, "core") != 0)
{
filenames[count] = strdup(entry->d_name);
count++;
}
}
closedir(dir);
qsort(filenames, count, sizeof(char *), compare);
for (i = 0; i < count; i++)
{
printf("%s\n", filenames[i]);
free(filenames[i]);
}
}

