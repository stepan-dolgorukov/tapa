#ifndef VALUE_H
#define VALUE_H

#include "type_value.h"

struct value_tag {
  int type;

  union {
    int integer;
    float floating_point;
    char string[80];
  } value;
};

#endif
