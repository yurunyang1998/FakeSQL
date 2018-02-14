//
// Created by windski on 2/13/18.
//

#ifndef FSM_H_
#define FSM_H_

#include <array>
#include <stack>
#include <initializer_list>

namespace utils {

    class FSM {
    public:
        FSM(std::initializer_list<std::string> accpet_words);
        bool update_state(int ch);
        bool is_error() const { return curr_stat == -1; }
        bool is_accept() const { return curr_stat == accept_stat; }
        void roll_back();

    private:
        int curr_stat;
        int accept_stat;
        std::stack<int> bkup_stat;
    };


} // end of utils

#endif //FSM_H_
