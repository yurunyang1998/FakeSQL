#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <vector>
#include "fsm.h"
#include <queue>

namespace utils {

    const size_t MAXBUF = 4096;

    enum token_t { IDENTIFIER, SELECT, FROM };


    struct id_t {
        bool is_sqlkw;
        enum token_t token;
        std::string str;
    };

    typedef struct id_t id_t;

    class Parser {
    private:
        std::vector<id_t>ids_token;
        std::string pending_str;
        std::string buff_str;
        int curr_index;
        utils::FSM mashine;
        std::queue<std::string> cmd_que;

        char next_ch();
        int pre_parse();

    public:
        bool check_accept();
        Parser(std::string str);
        Parser();
        std::vector<id_t> get_ids_stream() const
        {
            return ids_token;
        }

        friend Parser& operator<<(Parser &op, std::string Rstr)
        {
            op.buff_str = Rstr;
            op.pre_parse();
            return op;
        }
        friend Parser& operator<<(Parser &op, char* Rstr)
        {
            std::string tmp(Rstr);
            op.buff_str = tmp;
            op.pre_parse();
            return op;
        }

        ~Parser();
    };


    extern void shell();

} // end of utils

#endif // end of PARSER_H_