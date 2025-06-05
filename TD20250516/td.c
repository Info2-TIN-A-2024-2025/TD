#include <stdio.h>
#include "elem.h"
#include "list.h"
#include "error.h"

int main(int argc, const char *argv[])
{
	list l;
	init_list(&l);
	display_list(l);
	elem e = 10;
	insert_list(&l, e, 0);
	display_list(l);
	e=20;
	insert_list(&l, e, 1);
	display_list(l);
	e=0;
	insert_list(&l, e, 0);
	display_list(l);
	e=33;
	insert_list(&l, e, 3);
	display_list(l);
	e=25;
	insert_list(&l, e, 3);
	display_list(l);
	return 0;
}