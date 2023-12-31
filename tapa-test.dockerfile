FROM archlinux:latest
WORKDIR /libtapa-test

RUN pacman -Syu gcc make --noconfirm

COPY tapa.h \
     settings.h \
     tag.h \
     value_tag.h \
     type_value.h \
     tag.c \
     tapa-test.c \
     ./

COPY make/tapa.mk tapa.mk
COPY make/tapa-test.mk tapa-test.mk

ENV SANITIZE="yes"

RUN make --file tapa.mk && \
    make --file tapa-test.mk

ENV LD_LIBRARY_PATH=.
ENTRYPOINT [ "./tapa-test" ]
