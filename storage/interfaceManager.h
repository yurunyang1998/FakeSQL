//
// Created by yurunyang on 18-10-15.
//

#ifndef THE_NEW_FAKE_SQL_INTERFACEMANAGER_H
#define THE_NEW_FAKE_SQL_INTERFACEMANAGER_H

#include "B-tree-initial.hpp"
#include "bson_.h"
#include "pub_friends.hpp"
#include "file_read_write_system.h"
namespace  utils {
    class InterfaceManager {
    private:
        char * filepath;
        string initialKey;
        Manager<int , off64_t > *BTreeManager;// = new Manager<string, off64_t>("-2147483648");
        basic_read_write *BasicReadWrite ;//= new basic_read_write(".//test.db");

    public:
        InterfaceManager(char* dbfilenamepath,string initialkey);

        ~InterfaceManager();

        int insert_Into_Bson(const Quantum::HyfineStruct_t  &hy_p);

    };
}
#endif //THE_NEW_FAKE_SQL_INTERFACEMANAGER_H
