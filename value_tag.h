#ifndef VALUE_H
#define VALUE_H

#include "settings.h"
#include "type_value.h"

struct value_tag {
  int type;

  union {
    int integer;
    float floating_point;
    char string[size_value_tag_max];
  } value;
};

#endif
