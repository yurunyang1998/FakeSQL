//
// Created by windski on 2/13/18.
//

#include "fsm.h"

#define ch2index(ch) ((ch) - 21)
#define index2ch(ch) ((ch) + 21)

static std::array<std::array<int, 93>, 93> trans_tbl;

utils::FSM::FSM(std::initializer_list<std::string> accept_words)
: accept_stat(0),
  curr_stat(0)
{
    std::array<std::array<int, 93>, 93>::iterator iter1;
    std::array<int, 93>::iterator iter2;

    for(iter1 = trans_tbl.begin(); iter1 != trans_tbl.end(); iter1++) {
        for(iter2 = iter1->begin(); iter2 != iter1->end(); iter2++) {
            *iter2 = -1;
        }
    }


    int init_index = 0;
    for(auto iter : accept_words) {
        for(auto ch : iter) {
            int inch = (int)ch;
            trans_tbl[init_index][ch2index(inch)] = init_index + 1;
            init_index++;
            accept_stat++;
        }
    }
}


bool utils::FSM::update_state(int ch)
{
    if(curr_stat != -1) {
        // clear it..
        while(!bkup_stat.empty())
            bkup_stat.pop();
    } else {
        return false;
    }

    bkup_stat.push(curr_stat);
    curr_stat = trans_tbl[curr_stat][ch2index(ch)];

    return true;
}


void utils::FSM::roll_back()
{
    curr_stat = bkup_stat.top();
    bkup_stat.pop();
}
