# sorting
My implementation of standard sorting algorithms  
So far includes bubble, insertion, bogo, merge and quick (more to come).  
Each sort uses the same function signature as the standard C `qsort`  
Arrays of any datatype can be sorted by providing an appropriate `compare` function  

Formatting using GNU Indent to roughly match Google C++ style:
`indent -kr -ci2 -cli2 -i2 -l80 -nut -brf -ncs`

To run tests:  
$make  
$./test

