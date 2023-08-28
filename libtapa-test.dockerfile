FROM archlinux:latest
WORKDIR /libtapa-test

COPY tapa.h .
COPY settings.h .
COPY tag.h .

COPY tag.c .
COPY make/libtapa.mk libtapa.mk

COPY libtapa-test.c .
COPY make/libtapa-test.mk libtapa-test.mk

RUN pacman -Syuv gcc make --noconfirm && \
    make -f libtapa.mk && \
    make -f libtapa-test.mk

ENV LD_LIBRARY_PATH=.
CMD ["./libtapa-test"]