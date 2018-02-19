#include "parser.h"
#include "fsm.h"

#include <cstdio>
#include <cstring>
#include <strings.h>

static std::initializer_list<std::string> accept_words = {"SELECT", "FROM"};

utils::Parser::Parser(std::string str)
        : curr_index(-1), buff_str(str),
          mashine(accept_words), pending_str()
{

}

utils::Parser::Parser()
        : curr_index(-1), buff_str(),
          mashine(accept_words), pending_str()
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


int utils::Parser::pre_parse()
{
    if(!cmd_que.empty()) {
        pending_str = cmd_que.front();
        cmd_que.pop();

        // keep to add tag
    }

    // replace ENTER with SPACE
    std::string::iterator iter = buff_str.begin();
    for( ; iter != buff_str.end(); iter++) {
        if(*iter == '\n') {
            *iter = ' ';
        }
    }

    char buff[MAXBUF];
    int count = 0;
    bzero(buff, sizeof(buff));

    iter = buff_str.begin();
    while(iter != buff_str.end()) {
        buff[count++] = *iter++;

        if(*iter == ' ') {
            buff[count++] = *iter;
            while(* ++iter == ' ');
        }
    }

    // debug 用....
    printf("%s", buff);
}


utils::Parser::~Parser()
{

}


static int fgets2buf(char *buff, FILE *fp, size_t max)
{
    char ch;
    int i = 0;
    while(((ch = std::fgetc(fp)) != EOF) && (i < max)) {
        buff[i] = ch;
        if(buff[i - 1] == ';' && buff[i] == '\n') {
            return i + 1;
        }
        i++;
    }
    return i;
}


void utils::shell()
{
    Parser parser;
    char buff[MAXBUF];
    while(true) {
        bzero(buff, sizeof(buff));
        printf(":>> ");
        fgets2buf(buff, stdin, MAXBUF);
        parser << buff;

        // Just for test..
        if(!parser.check_accept()) {
            break;
        }
    }

}
