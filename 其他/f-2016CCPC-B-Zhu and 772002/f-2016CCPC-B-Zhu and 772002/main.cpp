//
//  main.cpp
//  f-2016CCPC-B-Zhu and 772002
//
//  Created by ZYJ on 16/8/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 330;

long long a[MAXN];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int N;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            scanf("%lld", a + i);
        }
    }
    std::cout << "Hello, World!\n";
    return 0;
}
