#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 1002

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

	size_t num_lines = 0;
	int c=0;
	do {
		c=fgetc(f);
		num_lines += c=='\n' || c==EOF;
	} while (c!=EOF);
	printf("num lines : %lu\n", num_lines);
	// TODO: check if no line in file 
	// FIXME: remove this f***g bug
	
	char s[MAX_STRING_SIZE];

	rewind(f); // read index back to the begining

	size_t line_index=0;
	for(line_index=0; line_index<num_lines; line_index++) {
		fgets(s,MAX_STRING_SIZE,f);
		char *tmp = strchr(s,'\n');
		if(NULL!=tmp) {
			*tmp='\0'; // substitute \n by \0
		}
		else {
			if(strlen(s)>=(MAX_STRING_SIZE-1)) {
				printf("string too long.\n");
			}
		}
		printf("[%s]\n", s);
	
	}

#if 0
	fgets(s,MAX_STRING_SIZE,f);
	printf("original [%s]\n", s);


	char *tmp = strchr(s,'\n');
	if(NULL!=tmp) {
		*tmp='\0'; // substitute \n by \0
	}
	else {
		printf("No \\n in string.\n");
	}
	printf("modified [%s]\n", s);
#endif

	if (0 != fclose(f))
	{
		printf("Error while closing %s\n", filename);
		return 2;
	}

	return 0;
}
