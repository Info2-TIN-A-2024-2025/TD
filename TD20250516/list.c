#include <stdio.h>
#include <string.h>
#include "list.h"

error_code init_list(list *l)
{
    if (NULL == l)
        return BAD_LIST;
    l->count = 0;
    l->first = NULL;
    l->last = NULL;
    return NO_ERROR;
}

void display_list(const list l)
{
    printf("count=%lu\n", l.count);
    node *n = l.first;

    while (NULL != n)
    {
        display_elem(n->e);
        n = n->next;
    }
    return;
}

error_code insert_list(list *l, const elem e, const size_t pos)
{
    if (NULL == l)
        return BAD_LIST;
    if (pos > l->count)
        return BAD_POS;
    node *n = (node *)malloc(sizeof(node));

    if (NULL == n)
        return ERROR_ALLOC;

    memcpy(&(n->e), &e, sizeof(elem));

    if (0 == l->count)
    {
        l->count++;
        l->first = n;
        l->last = n;
        n->next = NULL;
        n->prev = NULL;
        return NO_ERROR;
    }
    if (pos == l->count)
    { // insert at the end
        l->last->next = n;
        n->prev = l->last;
        n->next = NULL;
        l->last = n;
        l->count++;
        return NO_ERROR;
    }
    if(0==pos) {
        l->first->prev=n;
        n->prev=NULL;
        n->next=l->first;
        l->first=n;
        l->count++;
        return NO_ERROR;
    }
    // TODO: insert at pos (not begin nor end)

    return NO_ERROR;
}

error_code remove_list(list *l, const size_t pos)
{
    return NO_ERROR;
}

error_code get_elem(const list l, const size_t pos, elem *e)
{
    // 🍎C🍎V
    return NO_ERROR;
}

bool is_empty(const list l)
{
    return l.count == 0;
}
