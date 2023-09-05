FROM archlinux:latest
WORKDIR /libtapa-test

RUN pacman -Syu --noconfirm cppcheck

COPY \
  tapa.h \
  settings.h \
  tag.h \
  tag.c \
  ./

ENTRYPOINT [ \
  "cppcheck", \
  "--std=c89", \
  "--report-progress", \
  "--language=c", \
  "--enable=portability,performance", \
  "." ]