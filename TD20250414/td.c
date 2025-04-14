#include <stdio.h>
#include <string.h>

#define FR 1
#define EN 2
#define DE 3

// #define LANGUAGE DE  // see Makefile

int main(int argc, const char *argv[])
{
#ifndef LANGUAGE
#warning "LANGUAGE NOT DEFINED"
#define LANGUAGE FR
#endif

#if LANGUAGE == EN
	printf("Hello!\n");
#elif LANGUAGE == FR
	printf("Bonjour !\n");
#elif LANGUAGE == DE
	printf("HALO!\n");
#else
	printf("Unsupported language.\n");
#endif
	return 0;
}
