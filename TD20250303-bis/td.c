#include <stdio.h>
#include <math.h>

double deg2rad(const double alpha);
double rad2deg(const double alpha);

double deg2rad(const double alpha) {
	return alpha*M_PI/180.;
}

double rad2deg(const double alpha) {
	return alpha*180./M_PI;
}

int main(int argc, const char *argv[])
{
	const char *filename = "./data/circle.txt"; // rel
	const char *mode = "w";					  // r = read
	FILE *f = NULL;

	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error while opening %s\n", filename);
		return 1;
	}

	const double ALPHA_MIN = 0.;
	const double ALPHA_MAX = 359.;
	const double ALPHA_STEP = rad2deg(M_PI/1234.);
	const double RADIUS = 2.;

	double alpha=0.;

	for (alpha=ALPHA_MIN;alpha<=ALPHA_MAX;alpha+=ALPHA_STEP) {
		double r=RADIUS*cos(deg2rad(alpha));
		double i=RADIUS*sin(deg2rad(alpha));
		fprintf(f, "%+8.3lf %+8.3lf %+8.3lf\n", alpha, r, i);
	}

	if (0 != fclose(f))
	{
		printf("Error while closing %s\n", filename);
		return 2;
	}

	return 0;
}
