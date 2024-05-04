Design discussions regarding the interface classes in Graph.h

1. struct Lines : Shape
Lines(initializer_list<Point> lst V.S Lines(initializer_list<pair<Point,Point>> lst)
	- Lines(initializer_list<Point> lst: 
	  The formal needs to test if the number of Point objects is not odd. This is so
	  because the last Point cannot connect to another Point through a line segment.
	  Because of this, the constructor must insert an invariant to check it and cause a
	  run-time error if the size is odd.
	
	- Lines(initializer_list<pair<Point,Point>> lst): 
	  The latter takes an initializer list of pair objects that denotes a pair of Point objects.
	  This forces the user to pass a pair of Point objects where the number of Point objects is guaranteed
	  to be even, eliminating the need to do an if-check within the body.
	
	- why the latter? It catches the potential error at "compile-time" rather than at run-time. compile-time
	  errors are easier to deal with because it regards to either a syntax error, or a type error. Always favor
	  compile-time errors over run-time errors. However, there might be a good reason for the formal. I will
	  update this latter once I discover if there is one that exists.
	
Closed_polyline::draw_lines() const
	if(2 < number_of_points() && color().visibility()) V.S if(color().visibility())
   
	- By definition a closed-polyline is not considered a closed-polyline with only
	  one line segment (two points). It requires three points at least. But then again, 
	  three points can be placed where a straight line can be drawn. What then?
	  This would depend on the under-lying Graphics library you are using.
	  This can vary based on the implementation details of the graphics library or software being used.
	  The check if the number of points is greater than 2 is redundant because you can still draw a straight line
	  with three points or any N. FLTK handles this by forming a "closed loop". Zero or 1 Point will not draw anything
	  via the Shape::draw_lines fuction's if condition that fails if 1 < points.size().
