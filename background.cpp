#include "widget.hpp"
#include "application.hpp"
#include "background.hpp"



using namespace genv;
using namespace std;


Background::Background(Application* p, int bx, int by, int bsx, int bsy, int state) : Widget(p, 0, 0, p->get_XX(), p->get_YY(), 255, 255, 255), _bx(bx), _by(by), _bsx(bsx), _bsy(bsy), _state(state) {}


Background::~Background() {}


void Background::racs() {
    for(int i=1; i<9; i++) {
            if(i%3==0) {
                gout << move_to(_bx+i*40-1, _by) << color(0, 0, 0) << box(2, _bsy);
                gout << move_to(_bx, _by+i*40-1) << color(0, 0, 0) << box(_bsx, 2);
            }
            else {
                gout << move_to(_bx+i*40, _by) << color(0, 0, 0) << line(0, _bsy);
                gout << move_to(_bx, _by+i*40) << color(0, 0, 0) << line(_bsx, 0);
            }
        }

}

void Background::draw() {
    if(_state<4) {
    gout << move_to(_x, _y) << color(0, 0, 0) << box(_sx, _sy);
    gout << move_to(_x+3, _y+3) << color(_r, _g, _b) << box(_sx-6, _sy-6);
    }
    if(_state==0) {
        string s0="SUDOKU";
        gout << font("LiberationSans-Regular.ttf", 50);
        gout << move_to(_x+_sx/2-gout.twidth(s0)/2, 75) << color(0, 0, 0) << text(s0);

    }
    if(_state==1) {
        gout << move_to(_bx-2, _by-2) << color(0, 0, 0) << box(_bsx+4, _bsy+4);
        gout << move_to(_bx, _by) << color(0, 255, 0) << box(_bsx, _bsy);
        gout << font("LiberationSans-Regular.ttf", 40);
        string s1="EASY";
        gout << move_to(_bx+_bsx-gout.twidth(s1), 25) << color(0, 0.85*255, 0) << text(s1);


    }
    if(_state==2) {
        gout << move_to(_bx-2, _by-2) << color(0, 0, 0) << box(_bsx+4, _bsy+4);
        gout << move_to(_bx, _by) << color(0, 128, 255) << box(_bsx, _bsy);
        gout << font("LiberationSans-Regular.ttf", 40);
        string s2="MEDIUM";
        gout << move_to(_bx+_bsx-gout.twidth(s2), 25) << color(0, 0.85*128, 0.85*255) << text(s2);

    }
    if(_state==3) {
        gout << move_to(_bx-2, _by-2) << color(0, 0, 0) << box(_bsx+4, _bsy+4);
        gout << move_to(_bx, _by) << color(211, 211, 211) << box(_bsx, _bsy);
        gout << font("LiberationSans-Regular.ttf", 40);
        string s3="HARD";
        gout << move_to(_bx+_bsx-gout.twidth(s3), 25) << color(0.85*211, 0.85*211, 0.85*211) << text(s3);
    }
    if(_state==4) {
        gout << font("LiberationSans-Regular.ttf", 30);
        string s4="Congratulations!";
        gout << move_to(_bx, _by) << color(0, 0, 0) << text(s4);
    }


}


void Background::select() {
}

int Background::get_num() {
    return 0;
}

int Background::get_row() {
    return -1;
}

int Background::get_column() {
    return -1;
}

int Background::get_box() {
    return -1;
}

void Background::bad() {
}


void Background::handle(int n) {
}

bool Background::helytelen() {
    return true;
}
