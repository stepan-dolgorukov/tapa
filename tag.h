#ifndef TAG_H
#define TAG_H

#include "settings.h"

struct tag {
  char name[size_name_tag_max];
  const struct tag* children[amount_children_tag_max];
};

int
create_tag(
  const char* name,
  struct tag** tag_new
);

int
delete_tag(
  const struct tag** tag
);

#endif
