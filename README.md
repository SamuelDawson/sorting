# sorting
My implementation of standard sorting algorithms  
So far includes bubble, insertion, and bogosort (more to come).  
Each sort uses the same function signature as the standard C `qsort`  
Arrays of any datatype can be sorted by providing an appropriate `compare` function

To use:  
$make  
$./test \[numelements] \[print]  
Ex:  
./test 100  
./test 20 print
