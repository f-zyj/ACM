//
//  main.cpp
//  f-HDU-1856-More is better
//
//  Created by ZYJ on 2016/10/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 10000010;

int ans;
int maxRoom;
int pre[MAXN];
int res[MAXN];
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
    if (x > maxRoom)
    {
        maxRoom = x;
    }
    if (y > maxRoom)
    {
        maxRoom = y;
    }
    
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        pre[fx] = fy;
        res[fy] += res[fx];
    }
    
    return ;
}

int main(int argc, const char * argv[])
{
    int n;
    int A, B;
    while (cin >> n)
    {
        if (n == 0)
        {
            cout << "1\n";
            continue;
        }
        
        mem(res, 0);
        
        ans = 0;
        maxRoom = 0;
        for (int i = 0; i <= MAXN; i++)
        {
            pre[i] = i;
            res[i] = 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &A, &B);
            join(A, B);
        }
        
        for (int i = 0; i <= maxRoom; i++)
        {
            if (res[i] > ans)
            {
                ans = res[i];
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
