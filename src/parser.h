#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <vector>

namespace utils {

    enum token_t { IDENTIFIER, SELETE, FROM };

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
        int curr_index;
        char next_ch();

    public:
        bool check_accept();
        Parser(std::string str);
        std::vector<id_t> get_ids_stream() const
        {
            return ids_token;
        }
        ~Parser();
    };



} // end of utils

#endif // end of PARSER_H_