TESTPATH="./../testcases/Phase-2/t*.txt"
FILENAME=$TESTPATH



for file in $TESTPATH
do  
    make parser 
    ./parser $file
    ./translate_run.sh
done

