#!/bin/sh
echo "Updating $3"
diff -ru $1 $2 | sed /"^Only in"/d > $3
