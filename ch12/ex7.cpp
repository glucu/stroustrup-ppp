#include "Simple_window.h"
#include "Graph.h"

int main()
{
    try {
       
        Line_style house_style(Line_style::solid,4);
        Simple_window win(Point{100,100}, 1920,1080, "Canvas");

        Graph_lib::Rectangle house(Point(100,370),640,330);
        house.set_style(house_style);
        house.set_fill_color(Color::dark_red);
        win.attach(house);

        Graph_lib::Rectangle door(Point(370,500),100,200);
        door.set_style(house_style);
        door.set_fill_color(Color::dark_green);
        win.attach(door);

        Graph_lib::Rectangle win1(Point(210,525),50,75);
        win1.set_style(house_style);
        win1.set_fill_color(Color::cyan);
        win.attach(win1);

        Graph_lib::Rectangle win2(Point(580,525),50,75);
        win2.set_style(house_style);
        win2.set_fill_color(Color::cyan);
        win.attach(win2);

        Graph_lib::Polygon roof;
        roof.add(Point(50,370));
        roof.add(Point(420,270));
        roof.add(Point(790,370));
        roof.set_style(house_style);
        roof.set_fill_color(Color::dark_blue);
        win.attach(roof);

        Graph_lib::Polygon chimney;
        chimney.add(Point(590,250));
        chimney.add(Point(620,250));
        chimney.add(Point(620,324));
        chimney.add(Point(590,316));
        chimney.set_style(house_style);
        chimney.set_fill_color(Color::dark_magenta);
        win.attach(chimney);

        win.wait_for_button();

        return 0;
    }
    catch(runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
