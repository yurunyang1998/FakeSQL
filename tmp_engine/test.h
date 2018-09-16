#ifndef TEST_H_
#define TEST_H_

#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>
#include <cassert>

struct file_stat {
    int page_size;
    struct offset_ {
        off_t index_;
    } flag_;
};

class file {
public:
    file();
    ~file();
    void storage_data(std::vector<char> &data);
    void destroy_data(int page_index);

private:
    int fd_;
    std::vector<struct file_stat> flag_arr;

    int find_free_page();
    void init_file_format(struct file_stat &_file);
};


class engine {

};


#endif


