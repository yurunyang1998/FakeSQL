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

int utils::InterfaceManager::insert_Into_Bson(const Quantum::HyfineStruct_t &hy_p) {

    bson_::bson_couple * bsonCouple = new bson_::bson_couple;
    vector<Quantum::ColumnsName>::size_type  attrNums = (hy_p.colListRef_).size();

    enum _DeclType {
        DE_INT=0, DE_SMALLINT, DE_INTEGER, DE_TINYINT, DE_CHAR, DE_VARCHAR, DE_DATE, DE_DECIMAL, DE_NUMERIC
    }opy;
    int k;
    opy = (enum _DeclType)k;

    for(int i =0;i<attrNums;i++)
    {
        opy = (enum _DeclType)hy_p.colListRef_[i].colType_.type_;

        switch (opy)
        {
            case DE_CHAR: {
                bsonCouple->insert_UTF8_value(hy_p.colListRef_[i].colRef_,
                                              hy_p.colListRef_[i].colVal_);
                break;
            }
            case DE_INT: {
                bsonCouple->insert_int32_value(hy_p.colListRef_[i].colRef_,
                                               hy_p.colListRef_[i].colValINT_);
            };
        }
    }

    uint8_t *bsonBuf_ = bsonCouple->getBsonBuf();
    off64_t keyIntoTree =  this->BasicReadWrite->write_bsonCouple(bsonBuf_);
    this->BTreeManager->insert_data()

    return 0;
}

