#!/bin/bash
find src -prune -o -regex ".+\.[c|h]" -print0 | xargs -0 ./addcopyright.sh

