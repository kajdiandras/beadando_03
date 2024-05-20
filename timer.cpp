#include "widget.hpp"
#include "application.hpp"
#include "timer.hpp"


using namespace genv;
using namespace std;


Timer::Timer(Application* p, int x, int y) : Widget(p, x, y, 0, 0, 0, 0, 0) {
    _min=0;
    _sec=0;

}

Timer::~Timer() {}

void Timer::handle(int n) {
    _min=n/60;
    _sec=n%60;

}




void Timer::draw() {
    string s1;
    string s2;
    if(_min<10) {
        s1="0";
    }
    if(_sec<10) {
        s2="0";
    }
    s1+=to_string(_min);
    s2+=to_string(_sec);
    string s=s1+":"+s2;
    gout << move_to(_x-gout.twidth(s), _y-gout.cascent()) << color(_r, _g, _b) << text(s);

}




void Timer::racs() {}
void Timer::select() {}
bool Timer::is_over(int x, int y) {return false;}
int Timer::get_num() {return 0;}
int Timer::get_row() {return -1;}
int Timer::get_column() {return -1;}
int Timer::get_box() {return -1;}
void Timer::bad() {}
bool Timer::helytelen() {return true;}
