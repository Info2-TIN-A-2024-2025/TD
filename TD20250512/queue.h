#pragma once

#include "error.h"
#include "elem.h"
#include "list.h"

typedef list queue;

error_code init_queue(queue *q);
error_code enqueue(queue *q, const elem e);
error_code dequeue(queue *q, elem *e);
