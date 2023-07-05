/*
 *
 * struct.c
 *
 * Created by zhouruibin734 on 2019/06/07.
 * Copyright (c) 2019年 zhouruibin734 All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
https://www.cnblogs.com/qiyuexin/p/9009699.html
*/

typedef struct _Object {
    int a;
    int b;
    int c;
    void (*show)(const int var);
} Object;

void show(const int var)
{
    printf("show...var:%d\n", var);
}


typedef char* string;

typedef struct _String {
    string s;
    int (*length)(const string s);
} String;

int length(const string s)
{
    return strlen(s);
}


int main()
{
    Object ob = {
        .a = 1,
        .b = 2,
        .c = 3,
        .show = show
    };
    
    printf("object a=%d\n", ob.a);
    ob.show(ob.b);


    Object ob2 = {
        a:11,
        b:22,
        c:33,
        show:show
    };

    printf("object ob2 a=%d\n", ob2.a);
    ob2.show(ob2.b);

    Object *obj = (Object *)malloc(sizeof(Object *));
    obj->a = 111;
    obj->b = 222;
    obj->show = show;

    printf("object obj a=%d\n", obj->a);
    obj->show(obj->b);
    
    free(obj);

    printf("-------------------------------------------------\n");

    string str = "asdfg";
    printf("sizeof str:%lu len:%lu\n", sizeof(str), strlen(str));
    printf("str:%s\n", str);

    string str2 = (string)malloc(sizeof(string));
    str2 = "12345";
    printf("str2:%s len:%lu\n", str2, strlen(str2));
    str2 = NULL;
    printf("str2:%s len:%lu\n", str2, str2==NULL?0:strlen(str2));
    free(str2);

    printf("-------------------------------------------------\n"); 
    
    String s1 = {
        .s = "string",
        .length = length
    };
    printf("s1:%s len:%d\n", s1.s, s1.length(s1.s));

    String *s2 = (String *)malloc(sizeof(String *));
    s2->s = "string2";
    s2->length = length;
    printf("s2:%s len:%d\n", s2->s, s2->length(s2->s));
    free(s2);

    printf("-------------------------------------------------\n"); 

    string array[] = {
        [0] = "000",
        [1] = "111",
        [3] = "333",
        [2] = "222",
    };
    printf("array 3: %s\n", array[3]);

    return 0;
}


