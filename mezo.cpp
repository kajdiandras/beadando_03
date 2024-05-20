#include "widget.hpp"
#include "application.hpp"
#include "mezo.hpp"


using namespace genv;
using namespace std;


Mezo::Mezo(Application* p, int x, int y, int sx, int sy, int r, int g, int b, int szam, int sor, int oszlop, int doboz, bool eredeti)
    : Widget(p, x, y, sx, sy, r, g, b), _szam(szam), _sor(sor), _oszlop(oszlop), _doboz(doboz), _eredeti(eredeti) {
        _selected=false;
        if(eredeti||_sy==50) {
            _helyes=true;
        }
        else {
            _helyes=false;
        }
    }


Mezo::~Mezo() {}

bool Mezo::is_over(int x, int y) {
    if(x>=_x&&x<_x+_sx&&y>=_y&&y<_y+_sy&&!_eredeti) {
        return true;
    }
    else {
        return false;
    }

}

void Mezo::select() {
    if(_selected==false)
        _selected=true;
    else
        _selected=false;
}


int Mezo::get_num() {
    if(_szam==10) {
        return -1;
    }
    else
        return _szam;
}

int Mezo::get_row() {
    return _sor;
}

int Mezo::get_column() {
    return _oszlop;
}

int Mezo::get_box() {
    return _doboz;
}

void Mezo::handle(int n) {
    _szam=n;
    _helyes=true;
}

void Mezo::bad() {
    _helyes=false;
}

bool Mezo::helytelen() {
    if(!_helyes) {
        return true;
    }
}

void Mezo::draw() {
    if(_eredeti) {
        gout << move_to(_x, _y) << color(0.85*_r, 0.85*_g, 0.85*_b) << box(_sx, _sy);
    }
    if(!_eredeti&&!_selected) {
        gout << move_to(_x, _y) << color(_r, _g, _b) << box(_sx, _sy);
    }
    if(_selected) {
        gout << move_to(_x, _y) << color(255, 153, 51) << box(_sx, _sy);
    }
    if(_szam!=-1&&_szam!=10) {
        gout << font("LiberationSans-Regular.ttf", 20);
        string s=to_string(_szam);
        if(_helyes) { gout << color(0, 0, 0);}
        else { gout << color(255, 0, 0);}
        gout << move_to(_x+_sx/2-gout.twidth(s)/2, _y+_sy/2-gout.cascent()/2-gout.cdescent()/2) << text(s);
    }
    if(_szam==10) {
        string s="X";
        gout << move_to(_x+_sx/2-gout.twidth(s)/2, _y+_sy/2-gout.cascent()/2-gout.cdescent()/2) << color(0, 0, 0) << text(s);
    }




}


void Mezo::racs() {
}
