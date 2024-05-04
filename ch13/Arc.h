#ifndef ARC_H
#define ARC_H

#include "Graph.h"

class Arc : public Shape { 
public:
    Arc(Point p, int rr, double s, double e)
        : r{rr}, start{s}, end{e}
    {
        add({p.x - r, p.y - r});
    }

    void draw_lines() const;

private:
    int r;
    double start;
    double end;
};

void Arc::draw_lines() const
{
    if(fill_color().visibility()) {
        fl_color(fill_color().as_int());
        fl_pie(point(0).x, point(0).y, r+r, r+r, start, end);
        fl_color(color().as_int());
    }
    
    if(color().visibility()) {
        fl_color(color().as_int());
        fl_arc(point(0).x, point(0).y, r+r, r+r, start, end);
    }
}

#endif

