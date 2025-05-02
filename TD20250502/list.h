#pragma once

#include <stdlib.h>
#include "elem.h"
#include "error.h"

#define MAX_LIST_SIZE 10

typedef struct {

    elem t[MAX_LIST_SIZE];
    size_t count;
} list;

error_code init_list(list *l);
void display_list(const list l);
error_code insert_list(list *l, const elem e, const size_t pos);
