#ifndef TAG_H
#define TAG_H

#include "settings.h"

struct tag {
  char name[size_name_tag_max];
  struct tag* children[amount_children_tag_max];
};

#endif