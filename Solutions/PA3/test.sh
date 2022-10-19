# Author: Amittai Aviram - aviram@bc.edu

echo "Building ..."
make clean && make

echo "Running ..."
./div < input.txt > output.txt

echo "Checking ..."
DIFF=$(diff output.txt gold.txt)
if [ "$DIFF" != "" ]
then
    echo "\nXXXXXXXX UNEXPEXTED OUTPUT: XXXXXXXX\n"
    echo "$DIFF\n"
else
    echo "\n======== CORRECT ========\n"
fi

rm output.txt
make clean
