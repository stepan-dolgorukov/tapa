#include "tag.h"
#include "settings.h"

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int
create_tag(
  const char* name,
  struct tag** tag_new
) {

  if (NULL == tag_new) {

    return 1;
  }

  if (NULL != *tag_new) {

    return 1;
  }

  if (0u == strlen(name)) {

    return 1;
  }

  *tag_new = (struct tag*)malloc(sizeof(struct tag));

  if (NULL == *tag_new) {

    return 1;
  }

  strncpy((*tag_new)->name, name, size_name_tag_max);
  (*tag_new)->child[0] = NULL;

  return 0;
}

int
append_child(
  struct tag* child,
  struct tag* parent
) {

  if (NULL == parent) {
    return 1;
  }

  if (NULL == child) {
    return 1;
  }

  if (child == parent) {
    return 1;
  }

  size_t index;

  index = 0u;
  while (index < amount_children_tag_max &&
    NULL != parent->child[index]) {

    if (0 == strcmp(parent->child[index]->name, child->name)) {
      return 1;
    }

    ++index;
  }

  index = 0u;
  while (index < amount_children_tag_max &&
    NULL != parent->child[index]) {

    ++index;
  }

  if (index >= amount_children_tag_max) {
    return 1;
  }

  parent->child[index] = child;
  return 0;
}

int
delete_tag(
  const struct tag** tag
) {

  if (NULL == tag) {
    return 1;
  }

  if (NULL == *tag) {
    return 1;
  }

  size_t index = 0u;

  while (index < amount_children_tag_max &&
    NULL != (*tag)->child[index]) {

    const struct tag* child = (*tag)->child[index];
    delete_tag(&child);

    ++index;
  }

  free((void*)(*tag));
  *tag = NULL;

  return 0;
}

int
remove_child(
  struct tag *parent,
  const char *name
) {

  if (NULL == parent) {
    return 1;
  }

  if (NULL == name) {
    return 1;
  }

  size_t index;

  index = 0u;
  while (index < amount_children_tag_max &&
    0 != strcmp(parent->child[index]->name, name)) {

    ++index;
  }

  if (index >= amount_children_tag_max) {
    return 1;
  }

  return delete_tag(&parent->child[index]);
}