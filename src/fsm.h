//
// Created by windski on 2/13/18.
//

#ifndef FSM_H_
#define FSM_H_

#include <array>
#include <stack>
#include <initializer_list>

namespace utils {

    typedef struct {
        bool type;
        char *word;
        size_t x, y;
    } word_status_t;

    class FSM {
    public:
        FSM(std::initializer_list<std::string> &accpet_words);
        bool update_state(int ch);
        bool is_error() const { return curr_stat == -1; }
        bool is_accept() const { return curr_stat == accept_stat; }
        void clear_flag() { accept_stat = -1; }
        void roll_back();

    private:
        int curr_stat;
        int accept_stat;
        std::stack<int> bkup_stat;
        static std::array<std::array<int, 93>, 93> trans_tbl;
    };


} // end of utils

#endif //FSM_H_
