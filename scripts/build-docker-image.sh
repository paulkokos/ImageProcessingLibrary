#!/usr/bin/env bash

cur_dir=$(pwd | rev | cut -d"/" -f1 | rev)

if [[ "$cur_dir" == "scripts" ]]; then
  cd ..
fi

echo "Running in $(pwd)"

docker build -f ./docker/Dockerfile -t ubuntu:ikostelidis-20.04 .