/*
Suppose that s is the following structure (point is a structure tag declared in Exercise 10):

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

If the value of shape_kind is RECTANGLE, the height and width members store the dimensions of a rectangle. If the value of shape_kind is
CIRCLE, the radius member stores the radius of a cirlce. Indicate which of the following statements are lega, and show how to repair the
ones that aren't:

(a) s.shape_kind = RECTANGLE; --> Legal
(b) s.center.x = 10; --> Legal
(c) s.height = 25; --> ILLEGAL
(d) s.u.rectangle.width = 8; --> Legal
(e) s.u.circle = 5; --> ILLEGAL
(f) s.u.radius = 5; --> ILLEGAL


Solution
(a), (b) and (d) are legal statements. (c) must be changed to access the rectangle structure in the u union: s.u.rectangle.height = 25;; (e) must be changed to access the radius member of the circle structure within the u union: s.u.circle.radius = 5;; and (f) must do the same: s.u.circle.radius = 5;.
*/