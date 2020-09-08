#!/usr/bin/env bash

cur_dir=$(pwd | rev | cut -d"/" -f1 | rev)

if [[ "$cur_dir" == "scripts" ]]; then
  cd ..
fi

echo "Running in $(pwd)"

docker run -it -v $(pwd):/home/user/project -w /home/user/project ubuntu:ikostelidis-20.04 bash