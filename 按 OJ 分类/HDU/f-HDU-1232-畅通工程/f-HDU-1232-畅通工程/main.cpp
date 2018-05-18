//
//  main.cpp
//  f-HDU-1232-畅通工程
//
//  Created by ZYJ on 2016/10/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 1010;

int maxRoom;
int pre[MAXN];
int root;

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
    int N, M;
    int A, B;
    while (~scanf("%d", &N) && N != 0)
    {
        scanf("%d", &M);
        
        for (int i = 0; i <= MAXN; i++)
        {
            pre[i] = i;
        }
        
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &A, &B);
            join(A, B);
        }
        
        root = 0;
        for (int i = 1; i <= N; i++)
        {
            if (pre[i] == i)
            {
                root++;
            }
        }
        
        cout << root - 1 << '\n';
    }
    
    return 0;
}
