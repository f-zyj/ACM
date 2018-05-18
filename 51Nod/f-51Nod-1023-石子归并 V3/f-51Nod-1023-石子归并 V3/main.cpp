//
//  main.cpp
//  f-51Nod-1023-石子归并 V3
//
//  Created by ZYJ on 2017/9/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 5e4 + 5;

int n, num;
ll ans;
int A[MAXN];

void dfs(int now)
{
    int temp = A[now - 1] + A[now];
    ans += (ll)temp;
    for (int i = now; i < num - 1; i++)
    {
        A[i] = A[i + 1];
    }
    num--;
    
    int j;
    for (j = now - 1; j > 0 && A[j - 1] < temp; j--)
    {
        A[j] = A[j - 1];
    }
    A[j] = temp;
    while (j >= 2 && A[j - 2] <= A[j])
    {
        int d = num - j;
        dfs(j - 1);
        j = num - d;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", A + i);
    }
    
    num = 1;
    ans = 0;
    for (int i = 1; i < n; i++)
    {
        A[num++] = A[i];
        while (num >= 3 && A[num - 3] <= A[num - 1])
        {
            dfs(num - 2);
        }
    }
    
    while (num > 1)
    {
        dfs(num - 1);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
