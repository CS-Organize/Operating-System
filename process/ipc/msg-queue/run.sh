#!/bin/sh

docker build -t alpine . && docker run -d --name alpine -v $(pwd)/src:/app alpine 
