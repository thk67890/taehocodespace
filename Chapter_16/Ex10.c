/*
The following structures are designed to stroe information about objects on a graphics screen:

struct point {
    int x,y;
};

struct rectangle {
    struct point upper_left, lower_right;
};

A point structure stores the x and y coordinates of a poiont on the screen. A rectangle structure stores the coordinates of the
upper left and lower right corners of a rectangle. Write functions that perform the following operations on a rectangle structure r
passed as an argument

(a) Compute the area of x.
(b) Compute the center of r, returning it as a point value. If either the x or y cooridnates of the center isn't an integer, store its
truncated value in the point structure.
(c) Move x by x units in the x direction and y units in the y directions, returning the modified version of r. (x and y are additional
arguments to the function.)
(d) Determine whether a point p lies within r, returning true of false. (p is an additional argument of type struct point.)

*/

#define true 1
#define false 0

typedef int bool;

struct point {
    int x,y;
};

struct rectangle {
    struct point upper_left, lower_right;
};

//a
int area(struct rectangle sample_rect){
    return (sample_rect.lower_right.x - sample_rect.upper_left.x) \
        * (sample_rect.upper_left.y - sample_rect.lower_right.y);
}

//b
struct point center(struct rectangle sample_rect){
    struct point center;
    center.x = (sample_rect.lower_right.x - sample_rect.upper_left.x) / 2;
    center.y = (sample_rect.upper_left.y - sample_rect.lower_right.y) / 2;

    return center;
}
/*
Can return using compound literal instead of creating a new center struct
struct point center(struct rectangle sample_rect){
    return (struct point){(sample_rect.lower_right.x - sample_rect.upper_left.x)/2,
                           (sample_rect.upper_left.y - sample_rect.lower_right.y)/2};

*/

//c
struct rectangle move(struct rectangle sample_rect, int x, int y){
    sample_rect.upper_left.x += x;
    sample_rect.lower_right.x += x;
    sample_rect.upper_left.y += y;
    sample_rect.lower_right.y += y;

    return sample_rect;
}

//d

bool within(struct rectangle sample_rect, struct point p){
    if(p.x < sample_rect.lower_right.x && p.x > sample_rect.upper_left.x)
        if(p.y < sample_rect.upper_left.y && p.y > sample_rect.lower_right.y)
            return true;
    return false;
}
