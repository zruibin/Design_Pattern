/*
 *
 * main.cc
 *
 * Created by zhouruibin734 on 2019/07/26.
 * Copyright (c) 2019年 zhouruibin734 All rights reserved.
 */

#include "Features.hpp"
#include "ContainerTest.hpp"
#include "sort/Sort.hpp"
#include "DP/DP.hpp"


int main(int argc, char **argv )
{
    testFeatures();
    testMainContainer();

    SPACE::testSort();
    SPACE::testDP();
}











