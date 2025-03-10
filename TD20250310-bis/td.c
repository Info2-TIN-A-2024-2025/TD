#include <stdio.h>
#include <stdint.h>
#include <math.h>

// in math.h : # define M_PI_2		1.57079632679489661923	/* pi/2 */
// od -t x1 data/data.j05 

int main(int argc, const char *argv[])
{
	const char *filename = "./data/data.j05"; // rel
	const char *mode = "wb";					 
	FILE *f = NULL;

	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error while opening %s\n", filename);
		return 1;
	}
	double x=M_PI_2;

	// fprintf(f,"%.15lf",x); -> txt mode
	size_t r=0;
	r=fwrite(&x, sizeof(double), 1, f);
	if (1 != r)
	{
		printf("Error while writing to %s\n", filename);
		return 4;
	}

	uint8_t *p=(uint8_t *)&x;

	for(size_t i=0;i<sizeof(double); i++) {
		printf("%02X ", p[i]);
		printf("%02X ", *(p+i));
	}
	puts("");

	if (0 != fclose(f))
	{
		printf("Error while closing %s\n", filename);
		return 2;
	}

	return 0;
}
