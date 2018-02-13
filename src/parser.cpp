#include "parser.h"


utils::Parser::Parser(std::string& str)
: curr_index(0),
  pending_str(str)
{

}


int utils::Parser::next_ch()
{
    curr_index++;
    return pending_str[curr_index];
}


utils::Parser::~Parser()
{

}


