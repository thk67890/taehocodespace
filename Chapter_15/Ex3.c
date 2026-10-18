/*
We saw that writing #include <file> instead of #include "file" may not work if file is one that we've written. 
Would there be any problem writing #include "file" instead of #include <file> if file is a system header?

If there is a local header with the same name file, that local header will be used instead of the intended system header.

Sample ANS:
Yes.

The system normally looks in a predetermined location for system header files, and including a file with the same name as a system 
header file would only look in the local scope and potentially redefine a system header file as a local header file.

*/