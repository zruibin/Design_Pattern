/*
 * Macros.h
 *
 * Created by zhouruibin734 on 2020/08/06.
 * Copyright (c) 2020年 zhouruibin734 All rights reserved.
 */

#ifndef MACROS_H
#define MACROS_H

#define SPACE stl
#define NAMESPACE_START namespace SPACE {
#define NAMESPACE_END }


NAMESPACE_START
template<typename T>
void print(T t)
{
    for(auto &i : t) {
        std::cout << i << " | ";
    }
    std::cout<<'\n';
}
NAMESPACE_END

NAMESPACE_START
template<typename T>
void printMap(T t)
{
    for(auto &i : t) {
        std::cout << i.first << ":" << i.second << " | ";
    }
    std::cout<<'\n';
}
NAMESPACE_END


#endif /* !MACROS_H */
