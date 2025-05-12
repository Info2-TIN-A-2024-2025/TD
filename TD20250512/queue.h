#pragma once

#include "error.h"
#include "elem.h"
#include "list.h"

error_code init_queue(list *q);
error_code enqueue(list *q, const elem e);
error_code dequeue(list *q, elem *e);
