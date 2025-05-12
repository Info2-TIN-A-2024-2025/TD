 #include "queue.h"
 
error_code init_queue(list *q) {
    return init_list(q);
}
error_code enqueue(list *q, const elem e) {
    return insert_list(q,e,q->count);
}
error_code dequeue(list *q, elem *e) {
    error_code err;
    err=get_elem(*q,0,e);
    if(err)
        return err;
    return remove_list(q,0);
}
