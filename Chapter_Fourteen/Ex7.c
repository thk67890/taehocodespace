/*
Let GENERIC_MAX be the following macro:
#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}
(a) show the preprocessor's expansion of GENERIC_MAX(long)
->
long long_max(long x, long y)
{
    return x > y ? x : y;
}

(b) Explain why GENERIC_MAX doesn't work for basic types such as unsigned long
->
When GENERIC_MAX recieved "unsigned long" as an argument, the name of the function it creates will have 
a space between "unsigned" and "long". This results in a complie error.

(c) ?

Sample ANS:
(a)

long long_max(long x, long y)
{
  return x > y ? x : y;
}
The preprocessor would actually put all the tokens on one line, but this version is more readable.

(b) The problem with types such as unsigned long is that they require two words, which prevents GENERIC_MAX from creating the desired function name. For example, GENERIC_MAX(unsigned long) would expand into

unsigned long unsigned long_max(unsigned long x, unsigned long y)
{
  return x > y ? x : y;
}
(c) To make GENERIC_MAX work with any basic type, use a type definition to rename the type:

typedef unsigned long ULONG; **** typedef allows us to rename types as we wish ****

*/

