//
//  main.cpp
//  f-strstr函数
//
//  Created by ZYJ on 16/6/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//函数名：strstr

/*
 *  strstr函数
 *  功能：在串中查找指定字符串的第一次出现
 *  用法：char *strstr(char *strOne, char *strTwo);
 *  据说strstr函数和KMP的算法效率差不多
 */

int main(int argc, const char * argv[])
{
    char strOne[] = "Borland International";
    char strTwo[] = "nation";
    char *ptr;
    ptr = strstr(strOne, strTwo);
    std::cout << ptr << '\n';
    return 0;
}
