#include <stdio.h>
#include <math.h>
#include "polar.h"

cart polar2cart(const polar p) {
    cart c;
    c.x=p.rho*cos(p.theta);
    c.y=p.rho*sin(p.theta);
    return c;
}

void display_cart(const cart p) {
    printf("x=%+7.3lf\n", p.x);
    printf("y=%+7.3lf\n", p.y);
    return;
}

polar cart2polar(const cart c) {
    polar p;
    p.rho=sqrt(c.x*c.x+c.y*c.y);
    p.theta=atan2(c.y,c.x);
    return p;
}

void display_polar(const polar p) {
    printf("𝜌=%+7.3lf\n", p.rho);
    printf("𝜭=%+7.3lf\n", p.theta);
    return;
}