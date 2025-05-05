#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include "elem.h"
#include "error.h"

#define TABLE_SIZE_UPDATE 10

typedef struct {

    elem *t;
    size_t size;
    size_t count;
    bool auto_desalloc;
} list;

error_code init_list(list *l);
void display_list(const list l);
error_code insert_list(list *l, const elem e, const size_t pos);
error_code remove_list(list *l, const size_t pos);
bool is_empty(const list l);
bool is_full(const list l);
error_code free_list(list *l);
error_code get_elem(const list l, const size_t pos, elem *e);