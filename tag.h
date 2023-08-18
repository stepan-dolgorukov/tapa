#ifndef TAG_H
#define TAG_H

struct tag {
  char name[256];
  struct tag* children[8];
};

#endif