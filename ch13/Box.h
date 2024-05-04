#ifndef BOX_H
#define BOX_H

#include "Arc.h"

class Box : public Shape {
public:
    // Box() {}
    Box(Point p, int ww, int hh, int r);

    void draw_lines() const;

private:
    Lines lines;
    Vector_ref<Arc> arcs;
};

Box::Box(Point p, int w, int h, int r)
{
   lines.add({p.x + r, p.y}, {p.x + w - r, p.y});
   lines.add({p.x + w, p.y + r}, {p.x + w, p.y + h - r});
   lines.add({p.x + w - r, p.y + h}, {p.x + r, p.y + h});
   lines.add({p.x, p.y + h - r}, {p.x, p.y + r});

   arcs.push_back(new Arc(Point{p.x+w-r, p.y+r}, r, 0, 90));
   arcs.push_back(new Arc(Point{p.x+r, p.y+r}, r, 90, 180));
   arcs.push_back(new Arc(Point{p.x+r, p.y+h-r}, r, 180, 270));
   arcs.push_back(new Arc(Point{p.x+w-r, p.y+h-r}, r, 270, 360));
}

void Box::draw_lines() const
{
    for(int i{}; i != arcs.size(); ++i) {
        arcs[i].draw_lines();
    }
    lines.draw_lines();
}

#endif

