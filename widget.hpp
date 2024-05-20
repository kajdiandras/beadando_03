#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "application.hpp"
#include "graphics.hpp"


class Widget{
protected:
    Application* _p;
    const int _x, _y, _sx, _sy;
    int _r, _g, _b;


public:
    Widget(Application* p, int x, int y, int sx, int sy, int r, int g, int b);
    ~Widget();
    virtual void draw()=0;
    virtual bool is_over(int x, int y);
    virtual void racs()=0;
    virtual void select()=0;
    virtual int get_num()=0;
    virtual void handle(int n)=0;
    virtual int get_row()=0;
    virtual int get_column()=0;
    virtual int get_box()=0;
    virtual void bad()=0;
    virtual bool helytelen()=0;

};

#endif // WIDGET_HPP_INCLUDED
