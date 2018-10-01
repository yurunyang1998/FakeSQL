//
// Created by falleuion on 10/1/18.
//

#ifndef HYPERFINE_STRUCTURE_HPP
#define HYPERFINE_STRUCTURE_HPP

#include "ast.h"
#include <vector>
#include <string>

namespace Quantum {

struct tableName {
    std::string _nameRef;

    // something else....maybe...
};

struct columnsName {
    // TODO: desinged the structure...
};

struct _HyperfineStructure
{
    /**操作符类型...suck as `SELECT', `CREATE', `INSERT'.
     * 但他们不是简单的直接这样使用,它们在枚举里面的名字是有TS前缀的...比如`TS_SELECT'. `TS_CREATE'
     * `TS' 前缀意思是 test, 没啥特别含义...后面可能会改掉..
     */
    enum oprt_type _OpType;

    // 表名, 数据库名字直接给你应该就好了.这个没有什么特别的讲究,
    std::vector<struct tableName> _tableListRef;
    std::vector<struct columnsName> _colListRef;
};

} // end of Quantum


#endif //HYPERFINE_STRUCTURE_HPP
