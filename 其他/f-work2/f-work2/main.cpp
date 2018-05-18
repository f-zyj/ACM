//
//  main.cpp
//  f-work2
//
//  Created by ZYJ on 2017/3/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>
#include "file.hpp"

int main(int argc, const char * argv[])
{
    int n;
    std::cin >> n;
    int *num = new int[n];
    
    std::string text = "text.txt";  
    std::string in = "in.txt";
    
    File f = File(text, n, num);
    
    f.randDate();
    f.sortDate();
    
    File f_ = File(in, n, num);
    
    f_.coutDate();
    
    return 0;
}
