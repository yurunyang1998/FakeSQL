//
// Created by windski on 2/13/18.
//

#ifndef FSM_H
#define FSM_H

#include <array>

namespace utils {

    class FSM;

    class Status {
    protected:
        FSM *fsm = nullptr;

    public:
        virtual void status_enter() = 0;
        virtual void status_exit() = 0;
        virtual void status_update() = 0;

        Status(FSM *_fsm);
        virtual ~Status();
    };

    typedef enum { ERROR, SUCCESS, START } stat_code_t;
    class FSM {
    private:
        static std::array<std::array<int, 93>, 2> stat_tbl;
        stat_code_t cur_stat = START;

    public:
        bool register_stat(stat_code_t status, Status *pstatus);
        bool change_stat(stat_code_t status);
    };


} // end of utils

#endif //FAKESQL_FSM_H
