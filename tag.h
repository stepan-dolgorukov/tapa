#ifndef TAG_H
#define TAG_H

#include "settings.h"
#include "value_tag.h"

struct tag {
  struct value_tag value;
  char name[size_name_tag_max];
  struct tag* child[amount_children_tag_max];
};

int
create_tag(const char* name, struct tag** tag_new);

int
delete_tag(struct tag** tag);

int
append_child(struct tag* child, struct tag* parent);

int
remove_child(struct tag* parent, const char* name);

#endif
