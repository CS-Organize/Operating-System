FROM alpine:3.20

RUN apk update && \
    apk add vim \
        gcc \
        g++ && \
    mkdir /app

WORKDIR /app

CMD while true; do sleep 100; done
