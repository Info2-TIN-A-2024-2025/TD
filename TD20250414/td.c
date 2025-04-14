#include <stdio.h>
#include <string.h>

//#define LANGUAGE "EN" // see Makefile


int main(int argc, const char *argv[])
{
	if (strcmp(LANGUAGE, "EN") == 0)
	{
		printf("Hello!\n");
	}
	else if (strcmp(LANGUAGE, "FR") == 0)
	{
		printf("Bonjour !\n");
	}
	else if (strcmp(LANGUAGE, "DE") == 0)
	{
		printf("HALO!\n");
	}
	else
	{
		printf("Unsupported language.\n");
	}

	return 0;
}
