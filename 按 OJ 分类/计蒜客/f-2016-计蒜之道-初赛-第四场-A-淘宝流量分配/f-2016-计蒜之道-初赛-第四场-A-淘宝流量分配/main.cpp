//
//  main.cpp
//  f-2016-计蒜之道-初赛-第四场-A-淘宝流量分配
//
//  Created by ZYJ on 16/6/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

int A[10005];
int B[10005];

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while((c = getchar()) < '0' || c > '9');
    while(c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0'), c = getchar();
}

int main(int argc, const char * argv[])
{
    int N;
    while (std::cin >> N)
    {
        for (int i = 1; i <= N; i++)
        {
            scan_d(A[i]);
        }
        B[0] = 0;
        B[1] = A[1];
        B[2] = std::max(A[1], A[2]);
        for (int i = 3; i <= N; i++)
        {
            B[i] = std::max(A[i] + std::max(B[i - 2], B[i - 3]), B[i - 1]);
        }
        std::cout << B[N] << std::endl;
    }
    return 0;
}
