#!/bin/bash

CURRDIR=$(pwd)
DIRNAME=$1
EXTENTION=$2
BACKUPFOLDER=$3
ARCHIVENAME=$4

mkdir $BACKUPFOLDER

find $DIRNAME -name "*.$EXTENTION" -exec cp --backup=numbered {} $CURRDIR/$BACKUPFOLDER \;
tar -czf $ARCHIVENAME.gz --absolute-names $CURRDIR/$BACKUPFOLDER

echo "done"

exit 0
