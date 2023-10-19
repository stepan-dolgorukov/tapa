FROM archlinux:latest
WORKDIR /libtapa-test

RUN pacman -Syu --noconfirm cppcheck

COPY \
  tapa.h \
  settings.h \
  value_tag.h \
  type_value.h \
  tag.h \
  tag.c \
  tapa-test.c \
  ./

ENTRYPOINT [ \
  "cppcheck", \
  "--std=c89", \
  "--report-progress", \
  "--language=c", \
  "--enable=style,performance,portability,warning", \
  "." ]
