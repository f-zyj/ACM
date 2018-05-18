//
//  main.cpp
//  f-PAT-2017年团体程序设计天梯赛-大区赛-L2-4-功夫传人
//
//  Created by ZYJ on 2017/3/26.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 10;

vector<int> v[MAXN];

int N;
double Z, r;
double p[MAXN];
double sum = 0;

void dfs(int root)
{
    for (int i = 0; i < v[root].size(); i++)
    {
        if (p[v[root][i]] != 1)
        {
            p[v[root][i]] = p[root] * r * p[v[root][i]];
            sum += p[v[root][i]];
        }
        else
        {
            p[v[root][i]] = p[root] * r;
            dfs(v[root][i]);
        }
    }
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    cin >> N >> Z >> r;
    r = (100 - r) / 100;
    
    for (int i = 0; i < N; i++)
    {
        p[i] = 1;
    }
    p[0] = Z;
    
    int K, nt;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &K);
        if (K == 0)
        {
            scanf("%lf", p + i);
            continue;
        }
        for (int j = 0; j < K; j++)
        {
            scanf("%d", &nt);
            v[i].push_back(nt);
        }
    }
    
    if (N == 1)
    {
        printf("%d\n", (int)(p[0] * Z));
        return 0;
    }
    
    dfs(0);
    
    printf("%d\n", (int)sum);
    
    return 0;
}
