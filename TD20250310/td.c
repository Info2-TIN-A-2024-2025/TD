#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 5

int main(int argc, const char *argv[])
{
	const char *filename = "./data/data.txt"; // rel
	const char *mode = "r";					  // r = read
	FILE *f = NULL;

	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error while opening %s\n", filename);
		return 1;
	}

	char s[MAX_STRING_SIZE];
	char *tmp;

	do
	{
		tmp = fgets(s, MAX_STRING_SIZE, f);
		if (NULL != tmp)
		{
			// cleanup the \n using strlen
			if('\n'==s[strlen(s)-1]) {
				s[strlen(s)-1]='\0';
			}
			printf("[%s]\n", s);
		}

	} while ( !feof(f));

	if (0 != fclose(f))
	{
		printf("Error while closing %s\n", filename);
		return 2;
	}

	return 0;
}
