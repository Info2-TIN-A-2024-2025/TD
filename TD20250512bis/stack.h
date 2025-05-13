#pragma once

#include "error.h"
#include "elem.h"
#include "list.h"

typedef list stack;

error_code init_stack(stack *s);
error_code push(stack *s, const elem e);
error_code pop(stack *s, elem *e);