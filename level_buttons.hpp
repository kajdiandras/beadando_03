#ifndef LEVEL_BUTTONS_HPP_INCLUDED
#define LEVEL_BUTTONS_HPP_INCLUDED

#include "application.hpp"
#include "widget.hpp"
#include "graphics.hpp"


class Level_buttons:public Widget{
protected:

    std::string _s;
    bool _over;
    int _betumeret;
public:
    Level_buttons(Application* p, int x, int y, int sx, int sy, std::string s, int r, int g, int b);
    ~Level_buttons();
    virtual void draw() override;
    virtual bool is_over(int x, int y) override;
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

#endif // LEVEL_BUTTONS_HPP_INCLUDED
