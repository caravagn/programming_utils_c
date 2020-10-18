# Input filename - this is to be passed to the
# main C function that contains data-loading routines
# to get the input from the file (eg an array, etc.)
FILETEST=$1

echo
echo "~~> Running test: '$FILETEST'"
echo

# Main program call with the specified input
echo "~~~~~~~~~~ Output from C program ~~~~~~~~~~~"
output=$(./main $FILETEST)
echo "$output"
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

# The run program dumps results to a folder
# named "output", using the same filename of $FILETEST.
# The expected output is available in a folder named
# "result", again under filename $FILETEST.
#
# A  diff-operation between the two files should
# return no differences, implying the computed and 
# expected file contents are exactly the same.
diff_result=$(diff output/$FILETEST result/$FILETEST | wc -l)
#ndiff = $(wc -l $diff_file)

echo
echo "~~~> n = $diff_result differences ..."
echo

# Establish result (0 = PASS)
if [ $diff_result -eq 0 ] ; then
  echo "-----------------"
  echo "| Result: Pass! |"
  echo "-----------------"
  echo
  echo "Test with '$FILETEST' passed."
  exit 0
else
  echo "-----------------"
  echo "| Result: Fail! |"
  echo "-----------------"
  echo
  echo "Test with '$FILETEST' failed."
  exit 1
fi


