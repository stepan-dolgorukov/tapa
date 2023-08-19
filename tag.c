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

  *tag_new = (struct tag*)malloc(sizeof(struct tag));

  if (NULL == *tag_new) {

    return 1;
  }

  strncpy((*tag_new)->name, name, size_name_tag_max);
  (*tag_new)->children[0] = NULL;

  return 0;
}
