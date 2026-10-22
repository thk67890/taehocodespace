/*In the following declarations, the x and y structures have members named x and y:
struct {
    int x,y;
} x;

struct {
    int x,y;
} y;
Are these declarations legal on an individual basis? Could both declarations appear as shown in a program? Justify your answer.

Yes, both declarations are legal. Since member names of a struct variable are declared in a separate name space, 
these names do not conflict with other names in a program. Hence, both declarations are legal.
*/