#ifndef BACKGROUND_HPP_INCLUDED
#define BACKGROUND_HPP_INCLUDED

#include "application.hpp"
#include "widget.hpp"
#include "graphics.hpp"

class Background:public Widget{
protected:
    Application* _p;
    int _bx, _by, _bsx, _bsy;
    int _state;
public:
    Background(Application* p, int bx, int by, int bsx, int bsy, int state);
    ~Background();
    virtual void draw() override;
    virtual void racs() override;
    virtual void select() override;
    virtual int get_num() override;
    virtual void handle(int n) override;
    virtual int get_row() override;
    virtual int get_column() override;
    virtual int get_box() override;
    virtual void bad() override;
    virtual bool helytelen() override;

};

#endif // BACKGROUND_HPP_INCLUDED
