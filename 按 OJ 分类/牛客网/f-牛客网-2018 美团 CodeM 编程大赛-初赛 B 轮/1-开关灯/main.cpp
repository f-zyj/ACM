//
//  main.cpp
//  f-牛客网-2018 美团 CodeM 编程大赛-初赛 B 轮
//
//  Created by ZYJ on 2018/6/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 555;
const int MAXK = 1e5 + 10;

int n, m, k;
int cnt[MAXN][MAXN];
int tag[MAXN][MAXN];

struct engineer
{
    int x, y, z;
    int HH, MM;
    double SS;
} eng[MAXK];

bool cmp(const engineer &A, const engineer &B)
{
    if (A.HH != B.HH)
    {
        return A.HH < B.HH;
    }
    else if (A.MM != B.MM)
    {
        return A.MM < B.MM;
    }
    else
    {
        return A.SS < B.SS;
    }
}

int main(int argc, const char * argv[])
{
    cin >> n >> m >> k;
    
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d%d:%d:%lf", &eng[i].x, &eng[i].y, &eng[i].z, &eng[i].HH, &eng[i].MM, &eng[i].SS);
    }
    sort(eng, eng + k, cmp);
    
    int c = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (eng[i].z)
        {
            cnt[eng[i].x][eng[i].y]--;
        }
        else
        {
            cnt[eng[i].x][eng[i].y]++;
        }
        
        if (cnt[eng[i].x][eng[i].y] == 0)
        {
            c--;
        }
        else if (cnt[eng[i].x][eng[i].y] == 1)
        {
            c++;
            
            if (c >= ans)
            {
                ans = c;
                memcpy(tag, cnt, sizeof(cnt));
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (tag[i][j] == 0)
            {
                printf("0");
            }
            else
            {
                printf("1");
            }
        }
        printf("\n");
    }
    
    return 0;
}
