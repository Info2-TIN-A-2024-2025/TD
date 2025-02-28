#include <stdio.h>
#include <ctype.h>

int main(int argc, const char *argv[])
{
#if 0
	const char* filename="./data/poeme.txt"; // rel
	//const char* filename="/workspaces/TD/TD20250228/data/poeme.txt"; // abs
	const char* mode = "r"; // r = read
	FILE *f=NULL;

	f=fopen(filename,mode);
	if(NULL==f) {
		printf("Error while opening %s\n", filename);
		return 1;
	}

	//int c=fgetc(f);
	//printf("c=[%c]\n",c);

	int c=0;
	size_t count=0;
	do {
		c=fgetc(f);
		if(EOF!=c) {
			printf("%c",c);
			count++;
		}
	} while(c!=EOF);

	printf("\n%lu bytes\n",count);

	if(0!=fclose(f)) {
		printf("Error while closing %s\n", filename);
		return 2;
	}
#else
	const char *filename = "./data/ascii.txt"; // rel
	const char *mode = "w";					   // w = write and create
	FILE *f = NULL;

	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error while opening %s\n", filename);
		return 1;
	}

	// in the file, add the value as ASCII code formn 32 to 127
	fprintf(f,"ASCII TABLE\n");
	for(int i=32;i<128;i++)
		fprintf(f,"%3d %3o  %2X  %c\n",i,i,i,i);

	if (0 != fclose(f))
	{
		printf("Error while closing %s\n", filename);
		return 2;
	}
#endif
	return 0;
}