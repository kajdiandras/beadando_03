#ifndef MEZO_HPP_INCLUDED
#define MEZO_HPP_INCLUDED

#include "application.hpp"
#include "widget.hpp"
#include "graphics.hpp"

class Mezo:public Widget{
protected:
    int _szam;
    const int _sor, _oszlop, _doboz;
    bool _selected;
    const bool _eredeti;
    bool _helyes;
public:
    Mezo(Application* p, int x, int y, int sx, int sy, int r, int g, int b, int szam, int sor, int oszlop, int doboz, bool eredeti);
    ~Mezo();
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



#endif // MEZO_HPP_INCLUDED
