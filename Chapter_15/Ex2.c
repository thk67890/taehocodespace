/*
Which of the following should not be put in a header file? Why not?
(a) Function prototype
(b) Function definition
(c) Macro definition
(d) Type definition

(b) Funtion definition --> When put in a header file, function definitions that requires C header files make header files include
C library headers. When a source file links to the particular header it could result in a double link.

Sample ANS:
2. [was #2] (b). Function definitions should not be put in a header file. If a function definition appears 
in a header file that is included by two (or more) source files, the program can't be linked, since the linker will see two copies of the 
function.

*/