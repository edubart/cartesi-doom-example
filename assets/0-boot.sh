#!/bin/sh
cat doom1.wad > /dev/null # force file cache
if [ $# -eq 0 ]; then # no arguments
    exec ./doom \
        -iwad doom1.wad \
        -skill 3 -warp 1 1 \
        -levelquit 3 \
        -deathquit \
        -nowipe \
        -nomenu
else
    exec ./doom -iwad doom1.wad "$@"
fi