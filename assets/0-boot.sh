#!/bin/sh
if [ $# -eq 0 ]; then # no arguments
    exec ./doom \
        -iwad doom1.wad \
        -skill 3 -warp 1 1 \
        -nomenu \
        -autoquit \
        "$@"
else
    exec ./doom \
        -iwad doom1.wad \
        "$@"
fi