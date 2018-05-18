//
//  main.cpp
//  f-图灵杯-第四届“图灵杯”NEUQ-ACM 程序设计竞赛-B-一个简单的问题
//
//  Created by ZYJ on 2017/6/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 11;

int A[MAXN];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        for (int i = 0; i < MAXN; i++)
        {
            scanf("%d", A + i);
        }
        sort(A + 1, A + MAXN);
        
        printf("%d %d\n", A[0], A[8]);
    }
    
    return 0;
}
