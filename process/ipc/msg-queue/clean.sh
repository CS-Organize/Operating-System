#!/bin/sh

docker rm -f alpine > /dev/null 2>&1 && docker rmi -f alpine > /dev/null 2>&1
