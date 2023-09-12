#include "tapa.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
test_tag_no_children(void) {

  printf("%s\n", __FUNCTION__);

  struct tag* root;
  int status;
  size_t index;

  root = NULL;

  status = create_tag("root", &root);
  assert(0 == status);
  assert(0 == strcmp("root", root->name));

  for (index = 0; index < amount_children_tag_max; ++index) {
    assert(NULL == root->child[index]);
  }

  status = delete_tag(&root);
  assert(0 == status);
  assert(NULL == root);
}

void
test_appending_children(void) {

  printf("%s\n", __FUNCTION__);

  struct tag *root, *left, *center, *right;

  int status;
  size_t index;

  root = left = center = right = NULL;
  status = create_tag("root", &root);

  assert(0 == status);
  assert(0 == strcmp("root", root->name));

  status = create_tag("left", &left);
  assert(0 == status);
  assert(0 == strcmp("left", left->name));

  status = append_child(left, root);
  assert(0 == status);

  status = create_tag("center", &center);
  assert(0 == status);
  assert(0 == strcmp("center", center->name));

  status = append_child(center, root);
  assert(0 == status);

  status = create_tag("right", &right);
  assert(0 == status);
  assert(0 == strcmp("right", right->name));

  status = append_child(right, root);
  assert(0 == status);

  status = delete_tag(&root);
  assert(0 == status);
  assert(NULL == root);
}

void
test_remove_children(void) {

  printf("%s\n", __FUNCTION__);

  struct tag *root, *a, *b;
  int status;

  root = a = b = NULL;

  {
    status = create_tag(".", &root);
    assert(0 == status);
    assert(0 == strcmp(".", root->name));
  }

  {
    status = create_tag("A", &a);
    assert(0 == status);
    assert(0 == strcmp("A", a->name));
  }

  {
    status = create_tag("B", &b);
    assert(0 == status);
    assert(0 == strcmp("B", b->name));
  }

  {
    status = append_child(a, root);
    assert(0 == status);
    assert(a == root->child[0]);
  }

  {
    status = append_child(b, root);
    assert(0 == status);
    assert(b == root->child[1]);
  }

  {
    status = remove_child(root, "A");
    assert(0 == status);
    assert(NULL == root->child[0]);
  }

  {
    status = remove_child(root, "A");
    assert(1 == status);
  }

  {
    status = delete_tag(&root);
    assert(0 == status);
    assert(NULL == root);
  }
}

int
main(void) {
  test_tag_no_children();
  test_appending_children();
  test_remove_children();

  return 0;
}
