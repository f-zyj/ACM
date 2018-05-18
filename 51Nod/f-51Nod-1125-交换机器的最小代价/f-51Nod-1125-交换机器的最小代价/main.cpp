//
//  main.cpp
//  f-51Nod-1125-交换机器的最小代价
//
//  Created by ZYJ on 2017/3/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 10;

struct machin
{
    int w;  //  重量
    int p;  //  原来的位置
} M[MAXN];

long long minW;   //  所有中W最小的
int vis[MAXN];

long long solve(int k)
{
    long long minW_ = M[k].w; //  此次需要交换的部分中 W 最小的
    int cnt = 0;        //  交换次数
    long long wSum = M[k].w;
    int p = M[k].p;
    vis[k] = 1;
    
    while (k != p)
    {
        wSum += M[p].w;
        vis[p] = 1;
        p = M[p].p;
        cnt++;
    }
    return wSum + min(minW_ * (cnt - 1), minW * (cnt + 2) + minW_);
}

bool cmp(const machin a, const machin b)
{
    return a.w < b.w;
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> M[i].w;
        M[i].p = i;
    }
    sort(M, M + N, /* [](const machin a, const machin b){
        return a.w < b.w;
    } */ cmp);
    minW = M[0].w;
    
    long long ret = 0;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            ret += solve(i);
        }
    }
    
    cout << ret << '\n';
    
    return 0;
}
