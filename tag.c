#include "tag.h"
#include "settings.h"

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int
create_tag(
  const char* name,
  const struct tag* children[],

  struct tag** tag_new
) {

  if (NULL == tag_new) {

    return 1;
  }

  if (NULL != *tag_new) {

    return 1;
  }

  *tag_new = (struct tag*)malloc(sizeof(struct tag));

  if (NULL == *tag_new) {

    return 1;
  }

  strncpy((*tag_new)->name, name, size_name_tag_max);
  (*tag_new)->children[0] = NULL;

  if (NULL != children) {

    for (size_t index = 0u;
      (index < amount_children_tag_max) && (NULL != children[index]);
      ++index) {

      (*tag_new)->children[index] = children[index];
    }
  }

  return 0;
}
