#!/bin/sh
if [ $# -eq 0 ]; then # no arguments
    exec ./doom \
        -iwad doom1.wad \
        -skill 3 -warp 1 1 \
        -levelquit 3 \
        -deathquit \
        -nomenu
else
    exec ./doom -iwad doom1.wad "$@"
fi