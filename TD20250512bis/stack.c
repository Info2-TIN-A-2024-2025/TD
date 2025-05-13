  #include "stack.h"
 
error_code init_stack(stack *q) {
    return init_list(q);
}
error_code push(stack *q, const elem e) {
    return insert_list(q,e,q->count);
}
error_code pop(stack *q, elem *e) {
    error_code err;
    err=get_elem(*q,q->count-1,e);
    if(err)
        return err;
    return remove_list(q,q->count-1);
}
