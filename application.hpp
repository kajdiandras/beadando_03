#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>
#include <fstream>

class Widget;

class Application{
protected:
    std::vector<Widget*> _w;
    std::vector<Widget*> _backgrounds;
    std::vector<Widget*> _levelbtns;
    std::vector<Widget*> _numberbtns;
    Widget* _back;
    Widget* _timer;
    Widget* _selected_w;

    const int _XX, _YY;

    int _level;
    int _number;
    bool _kesz;
    double _t;
    double _t_0;
    bool _elso;
public:
    Application();
    ~Application();
    void event_loop();
    int get_XX();
    int get_YY();
    void feltolt(int r, int g, int b, std::ifstream& befajl);
    void clear_widgets();



};

#endif // APPLICATION_HPP_INCLUDED
