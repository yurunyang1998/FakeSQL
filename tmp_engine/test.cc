#include "test.h"
#include <cstring>
#include <strings.h>
#include <cstdlib>

file::file()
    : fd_(-1)
{
    fd_ = open("./foo.data", O_RDWR | O_CREAT, 0664);
    if(fd_ == -1) {
        fprintf(stderr, "failed to create data file\n");
    }

    struct file_stat _file;
    _file.page_size = 4096;
    // 这是第一页,因此index应该指向整个文件的起始.
    _file.flag_.index_ = 0;
    flag_arr.push_back(_file);
    init_file_format(_file);
}

file::~file()
{
    close(fd_);
}


void file::storage_data(std::vector<char> &data)
{
    char buf[sizeof(off_t)];
    int _index = find_free_page();
    struct file_stat _file = flag_arr[_index];

    bzero(buf, sizeof(buf));
    off_t _cur = _file.flag_.index_;
    // 定位到空闲指针所占的位置
    _cur += 68;
    // 定位到位置,以便读取
    lseek(fd_, _cur, SEEK_SET);

    ssize_t _bytes = read(fd_, buf, sizeof(buf));
    // `_bytes' 为 `-1' 代表读取失败,这时没必要继续执行下去了,最好崩溃
    assert(_bytes != -1);
    off_t free_ptr = atoi(buf);

    // 在进行写入之前 *有可能* 需要确认数据大小.因为页的大小不能拓展,所以可能需要多个页一起使用
    lseek(fd_, free_ptr, SEEK_SET);
    for(auto &i : data) {
        char buf[4];
        bzero(buf, sizeof(buf));

        // 分隔开不同列的数据,使用一个特殊的`flag'....`\r'`\n'
        sprintf(buf, "%c%c%c", i, '\r', '\n');
        _bytes = write(fd_, buf, sizeof(char) * 3);
        if(_bytes == -1) {
            perror("file::storage_data: write failed");
        }
    }
}


// 寻找未使用的页面,返回未使用的页面下标
int file::find_free_page()
{
    for(int i = 0; i < static_cast<int>(flag_arr.size()); i++) {
        // 找到未占用的page,如果全部被占用,就直接在申请一块空间
        off_t _cur = flag_arr[i].flag_.index_;
        char buf[64];
        bzero(buf, sizeof(buf));

        lseek(fd_, _cur, SEEK_SET);
        // 这里读取页开始存储的占用标志,大小是`sizeof char'
        read(fd_, buf, sizeof(char));
        if(strcmp(buf, "1") == 0) {
            return i;
        }
    }

    std::vector<struct file_stat>::iterator iter = flag_arr.end();
    struct file_stat _file;
    _file.page_size = 4096;
    // 如果页面大小不变,直接加上固定的`4096'
    _file.flag_.index_ = iter->flag_.index_ + 4096;

    init_file_format(_file);
    flag_arr.push_back(_file);

    return flag_arr.size() - 1;
}

void file::destroy_data(int page_index)
{
    struct file_stat _file = flag_arr[page_index];

    lseek(fd_, _file.flag_.index_, SEEK_SET);
    write(fd_, "1", sizeof(char));

    off_t _cur = _file.flag_.index_;
    _cur += 52;
    _cur = lseek(fd_, _cur, SEEK_SET);
    assert(_cur != -1);
    write(fd_, &_file.page_size, sizeof(int));

    // 接下来修改空闲地址指针
    _cur += 16;
    _cur = lseek(fd_, _cur, SEEK_SET);
    assert(_cur != -1);

    _cur += 16;
    write(fd_, &_cur, sizeof(off_t));
}

// 如果有特殊大小的数据时,lseek可能对存入的数据截断..bug
void file::init_file_format(struct file_stat &file)
{
    off_t _current = file.flag_.index_;

    // 初始化页面标志, 用来标志当前页面是否在使用. `1‘ 为可用，`0’ 为不可用
    // 页面标志占4bits
    // 这里先用普通的阻塞调用
    write(fd_, "1", sizeof(char));
    // 将当前指针指向下一个标志位置.
    _current += 4;
    _current = lseek(fd_, _current, SEEK_SET);
    assert(_current != -1);
    // 致命错误应该停止

    // 这里应该用作,文件拓展类型,是一个可以各种变化的数字,大概先占32bits好了
    // `NaN' 是不清楚文件拓展类型,可以用其他的替代.
    write(fd_, "NaN", sizeof(char) * 3);
    _current += 32;
    _current = lseek(fd_, _current, SEEK_SET);
    assert(_current != -1);

    char buff[4096];
    bzero(buff, sizeof(buff));
    sprintf(buff, "%d", file.page_size);
    // 这里用来表示数据页的大小,先用上16bits
    write(fd_, buff, sizeof(int));
    _current += 16;
    _current = lseek(fd_, _current, SEEK_SET);
    assert(_current != -1);

    bzero(buff, sizeof(buff));
    sprintf(buff, "%d", file.page_size - 58);
    // 接下来是空闲空间大小,也是暂用16bits来存储.
    write(fd_, buff, sizeof(int));
    _current += 16;
    _current = lseek(fd_, _current, SEEK_SET);
    assert(_current != -1);

    // 下面是空闲页面的起始指针.占16bits大小
    _current += 16;
    bzero(buff, sizeof(buff));
    sprintf(buff, "%ld", _current);
    write(fd_, buff, sizeof(off_t));

    // 剩下的所有空间用来存BSON? 目前还没构想好..
}

