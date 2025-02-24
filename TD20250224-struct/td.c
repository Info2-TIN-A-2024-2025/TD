// all measures in [meter]
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
	double length; // ⚠️ No init
	double width;
	double height;
	unsigned char num_legs;
	double thickness;
	unsigned int material;
} table;

void display_table(const table t);
bool init_table(table *p);

void display_table(const table t)
{
	printf("%-9s : %8.4lf\n", "length", t.length);
	printf("%-9s : %8.4lf\n", "width", t.width);
	printf("%-9s : %8.4lf\n", "height", t.height);
	printf("%-9s : %3u\n", "num_legs", t.num_legs);
	printf("%-9s : %8.4lf\n", "thickness", t.thickness);
	printf("%-9s : %3u\n", "material", t.material);
	return;
}

bool init_table(table *p) {
	if(NULL==p)
		return false;
#if 1
	p->height=0.; // (*p).height=0.;
	p->width=0.;
	p->length=0.;
	p->num_legs=0;
	p->thickness=0.;
	p->material=0;
#else
	memset(p, 0, sizeof(table));
#endif
	return true;
}

int main(int argc, const char *argv[])
{
	printf("sizeof(table)=%lu bytes.\n", sizeof(table));

	table t1 = {2., 0.95, 0.80, 4, 0.0254, 1};	// same order as declared in the typedef
	table t2 = {.material = 1, .height = 0.80}; // no order
	table t3;
	table *pt=&t3;

	init_table(pt);

	//display_table(t1);
	//display_table(t2);
	display_table(t3);

	return 0;
}