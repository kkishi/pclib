#!/bin/bash

base=$TEST_SRCDIR/__main__/ABC153/F

for file in $base/in/*; do
  diff=$($base/main < $file | diff - $base/out/$(basename $file))
  if [ "$diff" = "" ]; then
    echo $(basename $file) OK
  else
    echo $(basename $file) NG
    echo "$diff"
    exit 1
  fi
done

