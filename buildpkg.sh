#!/bin/bash

colcon build
colcon test

while getopts ":v" opt; do
  case $opt in
    v)
      timeNow=$(date +'%d%m%Y_%H%M%S')
      filename="test_result_${timeNow}.txt"
      printf "\n=========================\nExporting test results...\n=========================\n" >&2
      colcon test-result --verbose > $filename
      printf "Exported as $filename\n\n" >&2
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
  esac
done
