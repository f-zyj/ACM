//
//  file.hpp
//  f-work2
//
//  Created by ZYJ on 2017/3/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#ifndef file_hpp
#define file_hpp

#include <stdio.h>
#include <string>
#include <fstream>

class File
{
    std::string fileName;   //  文件名
    int n;                  //  数据量
    int *num;
    
public:
    File(std::string fileName_, int n_, int *num_) : fileName(fileName_), n(n_), num(num_) {}
    
    void randDate();                    //  生成随机数据文件 fileName
    void sortDate();                    //  读取文件 fileName 中的随机序列并排序，存入 num
    void coutDate();                    //  将 num 中数据存储到 fileName 文件中
    
    int random(double st, double ed);   //  生成 st~ed 随机数
};

#endif /* file_hpp */
