// commentaire bidon

#pragma once // absolument nécessaire


typedef struct {
    double rho; 
    double theta; 
} polar;

typedef struct {
    double x; 
    double y; 
} cart;


cart polar2cart(const polar p);
polar cart2polar(const cart p);
void display_cart(const cart p);
void display_polar(const polar p);
