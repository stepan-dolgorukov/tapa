#ifndef TAG_H
#define TAG_H

#include "settings.h"

struct tag {
  char name[size_name_tag_max];
  struct tag* children[amount_children_tag_max];
};

int
create_tag(
  const char* name,
  const struct tag* children[],

  struct tag** tag_new
);

int
delete_tag(
  struct tag** tag
);

#endif
