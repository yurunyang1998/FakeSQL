#include "parser.h"
#include "fsm.h"

#include <cstdio>

utils::Parser::Parser(std::string str)
: curr_index(-1),
  pending_str(str)
{

}


char utils::Parser::next_ch()
{
    curr_index++;
    return pending_str[curr_index];
}


bool utils::Parser::check_accept()
{
    int ch = (int)next_ch();

    FSM mashine({"SELECT"});
    while(true) {
        if(!mashine.update_state(ch)) {
            break;
        }
        ch = next_ch();
    }

    while(mashine.is_error()) {
        mashine.roll_back();
        curr_index--;
    }

    return mashine.is_accept();
}


utils::Parser::~Parser()
{

}


