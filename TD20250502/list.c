#include <stdio.h>
#include "list.h"

error_code init_list(list *l) {
    if(NULL==l)
        return BAD_LIST;
    l->count=0;
    return NO_ERROR;
}

void display_list(const list l) {

    printf("count=%lu\n", l.count);
    for(size_t index=0; index<l.count;index++) {
        display_elem(l.t[index]);
    }
    return;
}

error_code insert_list(list *l, const elem e, const size_t pos) {
    
}