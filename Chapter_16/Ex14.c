/*
Let shape be the structure tag declared in Exercise 13. Write functions that perform the following operations on a shape structure s
passed as an argument:
(a) Compute the area of s
(b) Move s by x units in the x direction and y units in the y direction, returning the modified version of s. (x an y are additional 
    arguments to the function.)
(c) Scale s by a factor of c(a double value), returning the modified version of s. (c is an additional argument to the function.)
*/

#include <stdio.h>

#define RECTANGLE 0
#define CIRCLE 1



struct point {
    int x,y;
};

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

int area(struct shape s);

struct shape move(struct shape s, int x, int y);

struct shape scale(struct shape s, double c);

int main(void){
    return 0;
}

//a
int area(struct shape s) {
    int area;
    if (s.shape_kind == RECTANGLE)
        area = s.u.rectangle.height * s.u.rectangle.width;
    else
        area = s.u.circle.radius * s.u.circle.radius * 3.141592;
    
    return area; //Area can be absent; we can just return the expressions
}

struct shape move(struct shape s, int x, int y){
    s.center.x += x;
    s.center.y += y;

    return s;
}

struct shape scale(struct shape s, double c){
    if(s.shape_kind == RECTANGLE){
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    }
    else{
        s.u.circle.radius *= c;
    }

    return s;

}


/*
Solution
(a)
double shape_area(struct shape s) {
    if (s.shape_kind == RECTANGLE)
        return s.u.rectangle.height * s.u.rectangle.width;
    else
        return 3.1415 * s.u.circle.radius * s.u.circle.radius;
}
(b)
struct shape shape_move(struct shape s, int x, int y) {
    s.center.x += x;
    s.center.y += y;

    return s;
}
(c)
struct shape shape_scale(struct shape s, double c) {
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    } else
        s.u.circle.radius *= c;
    return s;
}
*/