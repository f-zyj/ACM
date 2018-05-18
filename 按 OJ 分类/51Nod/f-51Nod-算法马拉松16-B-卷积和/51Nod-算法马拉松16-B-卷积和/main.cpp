//
//  main.cpp
//  51Nod-算法马拉松16-B-卷积和
//
//  Created by ZYJ on 16/7/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int f[100] = {0};
ll count[100] = {0};

void init()
{
    for (int i = 0; i < 10; i++)
    {
        f[i] = i * i;
    }
    for (int i = 10; i < 100; i++)
    {
        int a = i / 10;
        int b = i % 10;
        f[i] = a * b * 2;
    }
}

int main(int argc, const char * argv[])
{
    init();
    ll L, R;
    cin >> L >> R;
    std::cout << f[0];
    return 0;
}
