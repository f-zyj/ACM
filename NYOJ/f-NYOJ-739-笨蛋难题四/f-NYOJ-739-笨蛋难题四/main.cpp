//
//  main.cpp
//  f-NYOJ-739-笨蛋难题四
//
//  Created by ZYJ on 16/6/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;

void cinDiy(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int n;
    
    while (cin >> n)
    {
        int MIN = INF;
        int MAX = -1;
        int price;
        for (int i = 1; i <= n; i++)
        {
            cinDiy(price);
            if (price < MIN)
            {
                MIN = price;
            }
            else if (price - MIN > MAX)
            {
                MAX = price - MIN;
            }
        }
        
        cout << MAX << '\n';
    }
    
    return 0;
}
