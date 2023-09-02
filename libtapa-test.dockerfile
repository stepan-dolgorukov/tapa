FROM archlinux:latest
WORKDIR /libtapa-test

RUN pacman -Syuv gcc make --noconfirm

COPY tapa.h .
COPY settings.h .
COPY tag.h .

COPY tag.c .
COPY make/libtapa.mk libtapa.mk

COPY libtapa-test.c .
COPY make/libtapa-test.mk libtapa-test.mk

RUN make --file libtapa.mk && \
    make --file libtapa-test.mk

ENV LD_LIBRARY_PATH=.
ENTRYPOINT [ "./libtapa-test" ]