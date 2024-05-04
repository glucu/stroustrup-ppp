void swap_v(int a, int b) { int temp; temp = a; a = b; b = temp; }
void swap_r(int &a, int &b) { int temp; temp = a; a = b; b = temp; }


/*
 * This function does not compile. The parameters are const objects and the logic
 * attempts to assign to both <b>a</b> and <b>b</b> when they are const objects.
 *
 * void swap_cr(const int &a, const int &b) { int temp; temp = a; a = b; b = temp; }
 */

int main()
{
    int x = 7;
    int y = 9;
    swap_r(x,y);
    swap_v(7,9);
    const int cx = 7;
    const int cy = 9;
    // swap_v(cx,cy); cannot swap const objects (requires assignment)
    swap_v(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx,dy);
}


