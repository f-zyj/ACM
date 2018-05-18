//
//  file.cpp
//  f-work2
//
//  Created by ZYJ on 2017/3/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include "file.hpp"
#include <algorithm>
#include <ctime>
#include <cstdlib>

#define S 0
#define T 1000000

//  生成随机数据文件
void File::randDate()
{
    std::fstream fp(fileName, std::ios::out);
    
    while (!fp)
    {
        fp.open(fileName, std::ios::out);
    }
    
    srand(unsigned(time(0)));
    
    int k = n;
    while (k--)
    {
        fp << random(S, T) << '\n';
    }
    
    fp.close();
}

//  读取数据文件，存入num，并排序
void File::sortDate()
{
    std::fstream fp(fileName, std::ios::in);
    
    while (!fp)
    {
        fp.open(fileName, std::ios::in);
    }
    
    int k = 0;
    while (fp >> num[k++]) {}
    std::sort(num, num + n);
    
    fp.close();
}

//  将 num 中数据存入文件中
void File::coutDate()
{
    std::fstream fp(fileName, std::ios::out);
    
    while (!fp)
    {
        fp.open(fileName, std::ios::out);
    }
    
    for (int i = 0; i < n; i++)
    {
        fp << num[i] << '\n';
    }
    
    fp.close();
}

//  生成随机数，随机数在 st~ed 之内
int File::random(double st, double ed)
{
    return (int)st + (ed - st) * rand() / (RAND_MAX + 1.0);
}
