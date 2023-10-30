#!/bin/bash

# testing script

globalerror=0

## Add this later 
## Add comments above functions, top of this file
Usage() {
    echo "Usage: testall.sh [options] [.mc files]"
    echo "-k    Keep intermediate files"
    echo "-h    Print this help"
    exit 1
}

Compare() {
    
    DIFF_OUTPUT=`diff -b $1 $2`
    DIFF=$?

    if [ $DIFF -eq 0 ]
    then
        return 0
    else
        echo "$1 differs from $2"
        echo
        echo "diff -b $1 $2"
        echo "$DIFF_OUTPUT"
        echo
        return 1
    fi

}

Check() {

    fullpathname=$1

    outfile=$(echo "$1" | sed 's/\.gl$/.out/')

    base=`basename $1`
    echo "###### Testing $base"

    make parser > /dev/null

    ./parser $1
    EXIT_STATUS=$?

    if [ $EXIT_STATUS -eq 0 ]
    then
        echo Parsed without error
    fi

    generatedfile="seq_token.txt"

    Compare $generatedfile $outfile
    DIFF_STATUS=$?

    if [ $DIFF_STATUS -eq 0 ]
    then 
        echo seq_token.txt matched correctly
    fi

    if [[ $EXIT_STATUS -eq 0 &&  $DIFF_STATUS -eq 0 ]]
    then 
        echo "###### SUCCESS"
    else
        echo "###### FAILED"
    fi

    echo 
    echo
    
}

CheckError() {
    fullpathname=$1
    outfile=$(echo "$1" | sed 's/\.gl$/.err/')
    
    base=`basename $fullpathname`
    
    echo "###### Testing $base"

    make parser > /dev/null

    generatedfile="error.txt"

    ./parser $1 2> $generatedfile
    EXIT_STATUS=$?

    if [ $EXIT_STATUS -eq 1 ]
    then
        echo Error Generated
    fi


    Compare $generatedfile $outfile
    DIFF_STATUS=$?

    if [ $DIFF_STATUS -eq 0 ]
    then 
        echo Error matched correctly
    fi

    if [[ $EXIT_STATUS -eq 1 &&  $DIFF_STATUS -eq 0 ]]
    then 
        echo "###### SUCCESS"
    else
        echo "###### FAILED"
    fi

    echo 
    echo

}

files="tests/Phase-2/test-*.gl tests/Phase-2/err-*.gl"

for file in $files
do  
    case $file in
	*test-*)
	    Check $file 
	    ;;
    *err-*)
	    CheckError $file 
	    ;;
	*)
	    echo "unknown file type $file"
	    globalerror=1
	    ;;
    esac
done

exit $globalerror