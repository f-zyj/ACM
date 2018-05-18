//
//  main.cpp
//  f-51Nod-1413-权势二进制
//
//  Created by ZYJ on 16/8/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    
    int res = 0;
    while (cin >> n)
    {
        res = 0;
        while (n)
        {
            res = n % 10 > res ? n % 10 : res;
            n /= 10;
        }
    }
    
    std::cout << res << '\n';
    return 0;
}
