#include "widget.hpp"
#include "application.hpp"
#include "level_buttons.hpp"


using namespace genv;
using namespace std;


Level_buttons::Level_buttons(Application* p, int x, int y, int sx, int sy, string s, int r, int g, int b) : Widget(p, x, y, sx, sy, r, g, b), _s(s) {
    _over=false;
    _betumeret=10;
    gout << font("LiberationSans-Regular.ttf", _betumeret);

    while(gout.twidth(_s)<_sx*0.7&&gout.cascent()<_sy*0.7) {
        gout << font("LiberationSans-Regular.ttf", _betumeret);
        _betumeret++;
    }
    _betumeret--;
}


Level_buttons::~Level_buttons() {}


bool Level_buttons::is_over(int x, int y) {
    if(x>=_x&&x<_x+_sx&&y>=_y&&y<_y+_sy) {
        _over=true;
        return true;
    }
    else {
        _over=false;
        return false;
    }

}

void Level_buttons::draw() {

    gout << move_to(_x, _y) << color(0, 0, 0) << box(_sx, _sy);

    if(!_over) {
        gout << move_to(_x+2, _y+2) << color(_r, _g, _b) << box(_sx-4, _sy-4);
    }
    else {
        gout << move_to(_x+2, _y+2) << color(0.8*_r, 0.8*_g, 0.8*_b) << box(_sx-4, _sy-4);
    }


    gout << font("LiberationSans-Regular.ttf", _betumeret);

    gout << move_to(_x+_sx/2-gout.twidth(_s)/2, _y+_sy/2-gout.cascent()/2-gout.cdescent()/2) << color(0, 0, 0) << text(_s);
}

void Level_buttons::racs() {
}

void Level_buttons::select() {
}

int Level_buttons::get_num() {
    return 0;
}

int Level_buttons::get_row() {
    return -1;
}

int Level_buttons::get_column() {
    return -1;
}

int Level_buttons::get_box() {
    return -1;
}

void Level_buttons::bad() {
    _over=false;
}

void Level_buttons::handle(int n) {
}

bool Level_buttons::helytelen() {
    return true;
}
