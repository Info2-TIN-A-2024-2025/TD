#include <stdio.h>
#include <string.h>
#include "list.h"

error_code init_list(list *l)
{
    if (NULL == l)
        return BAD_LIST;
    l->count = 0;
    l->size = 0;
    l->t = NULL;
    l->auto_desalloc=true;
    return NO_ERROR;
}

error_code free_list(list *l) {
    if (NULL == l)
        return BAD_LIST;
    if(l->t) {
        free(l->t);
        l->size=0;
        l->count=0;
    }
    return NO_ERROR;
}

void display_list(const list l)
{
    printf("count=%lu\n", l.count);
    for (size_t index = 0; index < l.count; index++)
    {
        display_elem(l.t[index]);
    }
    return;
}

error_code insert_list(list *l, const elem e, const size_t pos)
{
    if (NULL == l)
        return BAD_LIST;
    if (is_full(*l))
    {
        elem *tmp = (elem *)realloc(l->t, (l->size + TABLE_SIZE_UPDATE) * sizeof(elem));
        if (NULL == tmp)
            return LIST_FULL;
        l->t=tmp;
        l->size+=TABLE_SIZE_UPDATE;
    }
    if (pos > l->count)
        return BAD_POS;
    for (size_t index = l->count; index > pos; index--)
        l->t[index] = l->t[index - 1];
    l->t[pos] = e;
    l->count++;
    return NO_ERROR;
}

error_code remove_list(list *l, const size_t pos)
{
    if (NULL == l)
        return BAD_LIST;
    if (is_empty(*l))
        return LIST_EMPTY;
    if (pos >= l->count)
        return BAD_POS;
    for (size_t index = pos; index <= l->count - 2; index++)
        l->t[index] = l->t[index + 1];
    l->count--;
    if(l->auto_desalloc && l->size-l->count>TABLE_SIZE_UPDATE) {
        // auto desalloc extra memory
    }
    return NO_ERROR;
}

error_code get_elem(const list l, const size_t pos, elem *e)
{
    if (is_empty(l))
        return LIST_EMPTY;
    if (pos >= l.count)
        return BAD_POS;
    if (NULL == e)
        return BAD_ELEM;
    // 🍎C🍎V de l.t[pos] dans *e;
    memcpy(e, &(l.t[pos]), sizeof(elem));
    return NO_ERROR;
}

bool is_empty(const list l)
{
    return l.count == 0;
}
bool is_full(const list l)
{
    return l.count == l.size;
}
