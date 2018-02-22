#include "parser.h"
#include "fsm.h"

#include <cstdio>
#include <cstring>
#include <strings.h>
#include <iostream>

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


// 解析的预处理.
// 将回车替换成空格, 然后再将多余的空格减少成一个
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

    // 去掉多余的空格. 用buff作为缓冲区,将去掉多余的空格的字符串放到这里.
    iter = buff_str.begin();
    while(iter != buff_str.end()) {
        buff[count++] = *iter++;

        if(*iter == ' ') {
            buff[count++] = *iter;
            while(* ++iter == ' ');
        }
    }
    std::string tmp(buff);

    unsigned long head = 0;
    for(unsigned long  i = 0; i < tmp.length(); i++) {
        if(tmp[i] == ';') {
            cmd_que.push(tmp.substr(head, i - head));
            head = i + 1;
        }
    }



    // debug 用....
//    printf("%s\n", buff);

    // print the queue's data
    while(!cmd_que.empty()) {
        std::cout << cmd_que.front() << std::endl;
        cmd_que.pop();
    }
    // force stop
    exit(1);
}


utils::Parser::~Parser()
{

}


// 定义一个专门用于shell 输入的函数. 目前先作为测试用
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
