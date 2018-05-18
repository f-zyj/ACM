//
//  main.cpp
//  f-POJ-1729-Jack and Jill
//
//  Created by ZYJ on 16/6/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>
char map[32][32];

int main(int argc, const char * argv[])
{
    int n;
    
    std::cout << sqrt(101);
    
    while (std::cin >> n && n != 0)
    {
        std::memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                std::cin >> map[i][j];
            }
        }
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
