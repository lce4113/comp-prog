#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#define epsilon 0         //for convex hull

#define COLINEAR 0      //orientation results
#define CW 1
#define CCW 2

struct point
{
    long double x, y;
    point(long double xloc, long double yloc) : x(xloc), y(yloc) {}
    point() {}
    point& operator= (const point& other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }
    int operator == (const point& other) const {
        return (other.x == x && other.y == y);
    }
    int operator != (const point& other) const {
        return !(other.x == x && other.y == y);
    }
    bool operator< (const point& other) const {
        return (x < other.x ? true : (x == other.x && y < other.y));
    }
};

struct vect { long double i, j; };

struct segment
{
    point p1, p2;
    segment(point a, point b) : p1(a), p2(b) {}
    segment() {}
};

//computes the cross product from AB to AC
long double crossProduct(point A, point B, point C) {
    vect AB, AC;
    AB.i = B.x - A.x;
    AB.j = B.y - A.y;
    AC.i = C.x - A.x;
    AC.j = C.y - A.y;
    return (AB.i * AC.j - AB.j * AC.i);
}

//finds orientation of ordered triplet (p, q, r).
//returns 0 if points are colinear, 1 for CW orientation and 2 for CCW
int orientation(point p, point q, point r) {
    int val = (int)crossProduct(p, q, r);
    if (val == 0) return COLINEAR;      //colinear
    return (val > 0) ? CW: CCW;     //CW or CCW
}

//returns true if point p lies on segment s (assuming all are colinear)
bool onSegment(point p, segment s) {
    return (p.x <= max(s.p1.x, s.p2.x) && p.x >= min(s.p1.x, s.p2.x) &&
            p.y <= max(s.p1.y, s.p2.y) && p.y >= min(s.p1.y, s.p2.y));
}

//computes polygon area; negative => CW, positive => CCW
long double area(vector<point> p)
{
    long double result = 0;
    for (int i = 0, j = 1, n = p.size(); i < n; i++, j = (i+1) % n)
        result += (p[i].x * p[j].y) - (p[i].y * p[j].x);
    return result / 2.0;
}

//computes and returns the midpoint between two points
point midpoint(point a, point b)
{
    return point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);
}

int main()
{
    cout << setprecision(15) ;
    int n;                          //number of points
    vector<point> poly;             //polygon vertices, CCW order
    point endpoint;                 //fixed endpoint of dividing line (door)
    long double room_area;          //total area of room
    long double half_area;          //target partition area - half of total room
    segment edge;                   //edge on polygon, used for finding where fixed endpoint lies
    int walk_idx;                   //index of current vertex on polygon walk
    long double partition_area;     //current area of partition
    vector<point> tri_poly;         //vector of points forming a triangle
    long double tri_area;           //area of current triangle
    point left, right, mid;         //points for binary search on edge

    cin >> n;

    //read in all polygon points
    poly.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> poly[i].x >> poly[i].y;
    }

    //read in dividing line endpoint (door)
    endpoint = poly[0] ;

    //compute area of room
    room_area = area(poly);
    //divide in half to get target partition area
    half_area = room_area / 2.0;

    //starting from the fixed endpoint, walk the polygon,
    //adding triangle areas, until we pass the halfway point
    //the optimal endpoint will lie on the last edge added

    //first - on which edge does the fixed endpoint lie?
    for (int i = 0; i < n; i++)
    {
        //grab edge as segment
        edge = segment(poly[i], poly[(i+1)%n]);

        if (orientation(edge.p1, endpoint, edge.p2) == COLINEAR and onSegment(endpoint, edge))
        {
            //first vertex to start poly walk on - makes triangle with idx+1 and idx+2 vertices and fixed endpoint
            walk_idx = i;
            break;
        }
    }

    //walk from the fixed endpoint to other, adding up triangle areas
    partition_area = 0;
    tri_area = 0;
    //set up a vector polygon for triangles
    tri_poly.resize(3);
    tri_poly[0] = endpoint;
    while (partition_area + tri_area <= half_area)
    {
        //add area of last triangle
        partition_area += tri_area;

        //move to next triangle
        walk_idx = (walk_idx + 1) % n;

        //get area of current triangle
        tri_poly[1] = poly[walk_idx];
        tri_poly[2] = poly[(walk_idx+1)%n];
        tri_area = area(tri_poly);
    }

    //fell out of loop, found edge on which other endpoint of dividing line must lie
    //edge vertices are at walk_idx and walk_idx+1

    //is solution on an endpoint? bypass the binary search
    if (abs(partition_area - half_area) < epsilon)
    {
        mid = poly[walk_idx];
        tri_area = 0;
    }

    //use binary search to find the correct dividing line endpoint
    left = poly[walk_idx];
    right = poly[(walk_idx+1)%n];
    while (abs(partition_area + tri_area - half_area) > epsilon)    //if area not right, keep searching
    {
        //get updated mid point
        mid = midpoint(left, right);

        //compute area using this point as dividing line endpoint
        tri_poly[2] = mid;
        tri_area = area(tri_poly);

        //found solution, break
        if (abs(partition_area + tri_area - half_area) < epsilon)     //area within tolerance
            break;

        //area too big, move left
        if (partition_area + tri_area - half_area > epsilon)      //area bigger than target
            right = mid;

        //area too small, move right
        else
            left = mid;
    }

    //print solution
    cout << fixed;
    cout <<mid.x << " " << mid.y << endl;
}
