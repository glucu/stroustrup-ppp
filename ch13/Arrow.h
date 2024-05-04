#ifndef ARROW_H
#define ARROW_H

#include "Graph.h"

class Arrow : public Shape {
public:
    Arrow(Point p1, Point p2);

    void draw_lines() const;

private:
    int size{14};
    int iso{30};
};

Arrow::Arrow(Point p1, Point p2) 
{
    add(p1);
    add(p2);
}

void Arrow::draw_lines() const
{
    constexpr double PI = 3.14159265;

    int diff_x = point(1).x - point(0).x;
    int diff_y = point(1).y - point(0).y;
    double angle = atan2(diff_y, diff_x)*180/PI;

    double x1 = point(1).x - cos((angle-iso)*PI/180) * size;
    double y1 = point(1).y - sin((angle-iso)*PI/180) * size;

    double x2 = point(1).x - cos((angle+iso)*PI/180) * size;
    double y2 = point(1).y - sin((angle+iso)*PI/180) * size;

    Polygon head;
    head.add(point(1));
    head.add(Point{int(x1), int(y1)});
    head.add(Point{int(x2), int(y2)});
    head.set_fill_color(color());

    head.draw_lines();          // draw arrow head
    Shape::draw_lines();        // draw line
}

#endif
