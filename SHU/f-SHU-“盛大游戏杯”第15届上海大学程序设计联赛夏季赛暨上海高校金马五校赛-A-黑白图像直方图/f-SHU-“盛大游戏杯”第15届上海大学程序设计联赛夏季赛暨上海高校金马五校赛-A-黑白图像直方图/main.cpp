//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-A-黑白图像直方图
//
//  Created by ZYJ on 2017/7/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 111;

int n, m;
int cnt[MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> n >> m)
    {
        memset(cnt, 0, sizeof(cnt));
        
        int x;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &x);
                if (x)
                {
                    cnt[j]++;
                }
            }
        }
        
        printf("%d", cnt[0]);
        for (int j = 1; j < m; j++)
        {
            printf(" %d", cnt[j]);
        }
        putchar(10);
    }
    
    return 0;
}
