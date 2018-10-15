//
// Created by yurunyang on 18-10-15.
//

#include "interfaceManager.h"

utils::InterfaceManager::~InterfaceManager() {
    delete BTreeManager;
    delete BasicReadWrite;

}

utils::InterfaceManager::InterfaceManager(char *dbfilenamepath, string initialkey)
        :filepath(dbfilenamepath),initialKey(initialkey) {
        BTreeManager = new Manager<string,off64_t>(initialKey);
        BasicReadWrite = new basic_read_write(filepath);
        
}
