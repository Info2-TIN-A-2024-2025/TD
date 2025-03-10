#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	const char *filename = "./data/data.j05"; // rel
	const char *mode = "rb";					 
	FILE *f = NULL;

	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error while opening %s\n", filename);
		return 1;
	}
	double x=0.;

	size_t r=0;
	r=fread(&x, sizeof(double), 1, f);
	if (1 != r)
	{
		printf("Error while reading from %s\n", filename);
		return 4;
	}

	printf("x=%.15lf\n", x);
	
	if (0 != fclose(f))
	{
		printf("Error while closing %s\n", filename);
		return 2;
	}

	return 0;
}
