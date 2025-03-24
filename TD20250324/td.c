#include <stdio.h>
#include <stdlib.h>
#define MAX_FILENAME_SIZE 100

double get_random_value(const double min, const double max)
{
	double x = 0.;
	double a = (max - min) / RAND_MAX;
	double b = min;
	x = rand() * a + b;
	return x;
}

void manage_data(double **data, const size_t n)
{

	// alloc dyn of n x double + test if NULL
	*data = (double *)malloc(n * sizeof(double));
	if (NULL == *data)
		return;

	double *t = *data;

	// for loop [0..n[, fill data[index] with random value [0..1]
	for (size_t index = 0; index < n; index++)
	{
		t[index] = get_random_value(0., 1.);
		//(*data)[index]=get_random_value(0.,1.);
		//*((*data)+index)=get_random_value(0.,1.);
	}
}

int main(int argc, const char *argv[])
{
	// process args
	// argc == 3
	// argv[0] -> num_cells
	// argv[1] -> filename index
	if(3!=argc){
		printf("bad number of args.");
		return 1;
	}
	// create data -> manage_data : data address, num_cells
	double *data = NULL;
	size_t num_cells = atoi(argv[1]);

	manage_data(&data, num_cells);
	if (NULL == data)
	{
		printf("Error while allocating memory for data.");
		return 2;
	}

	// compute min, max, mean
	double min_value = data[0];
	double max_value = data[0];
	double sum = data[0];
	double mean_value = 0.;
	for (size_t index = 1; index < num_cells; index++) {
		min_value=data[index]<min_value ? data[index] : min_value;
		max_value=data[index]>max_value ? data[index] : max_value;
		sum+=data[index];
	}
	mean_value=sum/num_cells;
	printf("min  = %7.4lf\n", min_value);
	printf("max  = %7.4lf\n", max_value);
	printf("mean = %7.4lf\n", mean_value);

	// filename setup
	char filename[MAX_FILENAME_SIZE];
	sprintf(filename,"./data/d%d.bin", atoi(argv[2]));
	printf("filename = [%s]\n", filename);

	// fopen
	const char *mode="wb";
	FILE* f=fopen(filename,mode);
	if (NULL == f)
	{
		printf("Error while opening file.");
		free(data);
		return 4;
	}

	// fwrite header
	int ret=0;
	ret=fwrite(&num_cells, sizeof(size_t), 1, f);

	// fwrite data

	// fwrite min,max,mean

	// fclose

	// free
	return 0;
}