#include "widget.hpp"
#include "application.hpp"



Widget::Widget(Application* p, int x, int y, int sx, int sy, int r, int g, int b) : _x(x), _y(y), _sx(sx), _sy(sy), _r(r), _g(g), _b(b), _p(p){}


Widget::~Widget() {}

bool Widget::is_over(int x, int y) {
    return x>=_x&&x<_x+_sx&&y>=_y&&y<_y+_sy;

}
