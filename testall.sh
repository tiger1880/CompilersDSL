#!/bin/bash

# testing script

globalerror=0

Check() {

    error=0
    base=`basename $1`
    echo "###### Testing $base"

    make parser

}

if [ $# -ge 1 ]
then
    files=$@
else
    files="tests/Phase-2/test-*.gl"
fi

for file in $files
do
    case $file in
	*test-*)
	    Check $file 
	    ;;
	*)
	    echo "unknown file type $file"
	    globalerror=1
	    ;;
    esac
done

exit $globalerror