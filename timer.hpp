#ifndef TIMER_HPP_INCLUDED
#define TIMER_HPP_INCLUDED

#include "application.hpp"
#include "widget.hpp"
#include "graphics.hpp"


class Timer : public Widget {
protected:
    int _min, _sec;
public:
    Timer(Application* p, int x, int y);
    ~Timer();
    virtual void draw() override;
    virtual void racs() override;
    virtual void select() override;
    virtual bool is_over(int x, int y) override;
    virtual int get_num() override;
    virtual void handle(int n) override;
    virtual int get_row() override;
    virtual int get_column() override;
    virtual int get_box() override;
    virtual void bad() override;
    virtual bool helytelen() override;


};

#endif // TIMER_HPP_INCLUDED
