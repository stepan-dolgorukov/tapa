#include "tapa.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
test_tag_no_children(void) {

  printf("%s\n", __FUNCTION__);

  struct tag *root;
  int status;
  size_t index;

  root = NULL;
  status = create_tag("root", &root);

  assert(0 == status);
  assert(0 == strcmp("root", root->name));

  for (index = 0; index < amount_children_tag_max; ++index) {
    assert(NULL == root->child[index]);
  }

  delete_tag(&root);
  assert(NULL == root);
}

int main(void) {
  test_tag_no_children();

  return 0;
}
