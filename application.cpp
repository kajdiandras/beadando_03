#include "application.hpp"
#include "widget.hpp"
#include "background.hpp"
#include "level_buttons.hpp"
#include "mezo.hpp"
#include "timer.hpp"

#include "graphics.hpp"
#include <vector>
#include <fstream>

using namespace genv;
using namespace std;

Application::Application() : _XX(800), _YY(600) {

    Background* b0=new Background(this, 0, 0, 0, 0, 0);
    _backgrounds.push_back(b0);
    for(int i=1; i<=3; i++) {
        Background* bck=new Background(this, 100, 100, 360, 360, i);
        _backgrounds.push_back(bck);
    }
    Background* b4=new Background(this, 550, 25, 0, 0, 4);
    _backgrounds.push_back(b4);

    _level=0;

    Level_buttons* btn1=new Level_buttons(this, 300, 200, 200, 50, "EASY", 0, 255, 0);
    _levelbtns.push_back(btn1);
    Level_buttons* btn2=new Level_buttons(this, 300, 300, 200, 50, "MEDIUM", 0, 128, 255);
    _levelbtns.push_back(btn2);
    Level_buttons* btn3=new Level_buttons(this, 300, 400, 200, 50, "HARD", 211, 211, 211);
    _levelbtns.push_back(btn3);

    _back=new Level_buttons(this, 100, 25, 50, 50, "BACK", 216, 222, 44);
    _selected_w=nullptr;

    int num=1;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            Mezo* mz=new Mezo(this, 550+j*65, 100+i*65, 50, 50, 224, 224, 224, num, 0, 0, 0, false);
            _numberbtns.push_back(mz);
            num++;
        }
    }
    Mezo* del=new Mezo(this, 550, 295, 180, 50, 224, 224, 224, 10, 0, 0, 0, false);
    _numberbtns.push_back(del);
    _number=0;

    _timer=new Timer(this, 730, 460);



}

Application::~Application()
{

    for (auto widget : _w) {
        delete widget;
    }
    for(auto widget : _backgrounds) {
        delete widget;
    }
    for (auto btn : _levelbtns) {
        delete btn;
    }
    for (auto widget : _numberbtns) {
        delete widget;
    }
    delete _back;
    delete _timer;
}

int Application::get_XX() {return _XX;}
int Application::get_YY() {return _YY;}

void Application::clear_widgets() {
    for (auto widget : _w) {
        delete widget;
    }
    _w.clear();
}


void Application::feltolt(int r, int g, int b, ifstream& befajl) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            int box=(i/3)*3+j/3;
            int szam;
            befajl >> szam >> ws;
            bool eredeti=false;
            if(szam!=-1)
                eredeti=true;
            Mezo* m=new Mezo(this, 100+j*40, 100+i*40, 40, 40, r, g, b, szam, i, j, box, eredeti);
            _w.push_back(m);
        }
    }


}

void Application::event_loop() {


    ifstream befajl;


    gout.open(_XX, _YY);
    event ev;



    _backgrounds[0]->draw();
    for(Widget* w:_levelbtns) {
        w->draw();
    }

    gin.timer(50);

    while (gin >> ev && ev.keycode != key_escape) {

        _backgrounds[_level]->draw();



        if(_level>0&&_level<4) {

            if(_elso&&ev.type==ev_timer) {
                _t_0=ev.time;
                _elso=false;
            }

            if(ev.type==ev_timer) {
                _t=ev.time-_t_0;
                _timer->handle(_t/1000);
            }


            if(_selected_w==nullptr) {
                for(int i=0; i<_w.size(); i++) {
                    if(ev.type==ev_mouse&&ev.button==btn_left&&_w[i]->is_over(ev.pos_x, ev.pos_y)) {
                        _selected_w=_w[i];
                        _selected_w->select();


                    }
                }

            }
            else if(_selected_w!=nullptr) {

                    for(int i=0; i<_w.size(); i++) {
                        if(ev.type==ev_mouse&&ev.button==btn_left&&_w[i]->is_over(ev.pos_x, ev.pos_y)) {
                            _selected_w->select();
                            _number=0;
                            _selected_w=_w[i];
                            _selected_w->select();


                        }
                    }




                    for(int i=0; i<_numberbtns.size(); i++) {
                        if(ev.type==ev_mouse&&ev.button==btn_left&&_numberbtns[i]->is_over(ev.pos_x, ev.pos_y))
                            _number=_numberbtns[i]->get_num();
                    }
                    if(ev.type==ev_key&&ev.keycode>='1'&&ev.keycode<='9')
                            _number=ev.keycode-'0';
                    if(ev.type==ev_key&&ev.keycode==key_backspace)
                            _number=-1;
                    if(_number!=0) {
                        _selected_w->handle(_number);
                        if(_number!=-1) {
                            for(int i=0; i<_w.size(); i++) {
                                if(_w[i]!=_selected_w) {
                                    if(_selected_w->get_num()==_w[i]->get_num()) {
                                        if(_selected_w->get_row()==_w[i]->get_row()||_selected_w->get_column()==_w[i]->get_column()||_selected_w->get_box()==_w[i]->get_box()) {
                                            _selected_w->bad();


                                        }
                                    }
                                }
                            }
                        }

                    }


            }



            for(Widget* w: _w) {
                w->draw();
            }

            for(Widget* w: _numberbtns) {
                w->draw();
            }

            _timer->draw();

            _backgrounds[_level]->racs();




            if(ev.type==ev_mouse) {
                if(_back->is_over(ev.pos_x, ev.pos_y)&&ev.button==btn_left) {
                    _level=0;
                    clear_widgets();
                    _selected_w=nullptr;
                    _number=0;
                    _back->bad();
                }


            }
            _back->draw();

            for(Widget* w:_w) {
                _kesz=true;
                if(w->helytelen()) {
                    _kesz=false;
                    break;
                }
            }

            if(_kesz) {
                _level=4;
            }

        }



        else if(_level==0) {
            if(ev.type==ev_mouse) {
                for(int i=0; i<_levelbtns.size(); i++) {
                    if(_levelbtns[i]->is_over(ev.pos_x, ev.pos_y)&&ev.button==btn_left) {
                        _elso=true;
                        _level=i+1;

                        if(_level==1) {
                            _levelbtns[i]->bad();
                            befajl.open("easy.txt");
                            feltolt(0, 255, 0, befajl);
                            befajl.close();

                        }
                        else if(_level==2) {
                            _levelbtns[i]->bad();
                            befajl.open("medium.txt");
                            feltolt(0, 128, 255, befajl);
                            befajl.close();
                        }
                        else if(_level==3) {
                            _levelbtns[i]->bad();
                            befajl.open("hard.txt");
                            feltolt(211, 211, 211, befajl);
                            befajl.close();
                        }
                    }

                }
            }


            for(Widget* w: _levelbtns) {
                w->draw();
            }
        }

        else if(_level==4) {
            if(ev.type==ev_mouse) {
                if(_back->is_over(ev.pos_x, ev.pos_y)&&ev.button==btn_left) {
                    _level=0;
                    clear_widgets();
                    _selected_w=nullptr;
                    _number=0;
                    _back->bad();
                }


            }
            _back->draw();


        }








        gout << refresh;
    }


}
