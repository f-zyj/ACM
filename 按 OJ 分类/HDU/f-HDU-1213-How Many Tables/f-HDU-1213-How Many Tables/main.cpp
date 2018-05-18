//
//  main.cpp
//  f-HDU-1213-How Many Tables
//
//  Created by ZYJ on 2016/10/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 1010;

int pre[MAXN];
int root[MAXN];

int find(int x)
{
    int r = x;
    while (pre[r] != r)
    {
        r = pre[r];
    }
    
    int i = x, j;
    while (i != r)
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        pre[fx] = fy;
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int N, M;
    int A, B;
    while (T--)
    {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
        {
            pre[i] = i;
        }
        
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &A, &B);
            join(A, B);
        }
        
        mem(root, 0);
        int res = 0;
        for (int i = 1; i <= N; i++)
        {
            int temp = find(i);
            if (!root[temp])
            {
                res++;
                root[temp] = 1;
            }
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
