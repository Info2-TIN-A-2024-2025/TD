#include <stdio.h>
#include "list.h"

int main(int argc, const char *argv[])
{
	list l;
	init_list(&l);
	display_list(l);

	puts("insert elem at pos 0");
	elem e1={.x=1., .y=2.};
	insert_list(&l, e1, 0);
	display_list(l);
	puts("insert elem at pos 1");
	elem e2={.x=5., .y=6.};
	insert_list(&l, e2, 1);
	display_list(l);
	for(int k=0;k<30;k++) {
		puts("insert elem at pos 1");
		elem e3={.x=3., .y=4.};
		insert_list(&l, e3, 1);
	
	}
	display_list(l);

	//remove_list(&l,0);
	//display_list(l);

	puts("--- elem at pos 0");
	elem e4;
	get_elem(l,0,&e4);
	display_elem(e4);

	return 0;
}