#include <math.h> // M_PI_4
#include "polar.h"
#include "error.h"

int main(int argc, const char *argv[])
{
	polar p1={.rho=1., .theta=M_PI_4};
	cart p2={.x=0.5, .y=sqrt(3)/2.};


	cart p;

	p=polar2cart(p1);
	display_cart(p);

	p1=cart2polar(p);
	display_polar(p1);
	return 0;
}