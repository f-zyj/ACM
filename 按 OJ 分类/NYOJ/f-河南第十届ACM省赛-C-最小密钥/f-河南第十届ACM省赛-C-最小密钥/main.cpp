//
//  main.cpp
//  f-河南第十届ACM省赛-C-最小密钥
//
//  Created by ZYJ on 2017/5/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 3000;
const int MAXM = 2e4 + 50;

int n;
int A[MAXN];
int hash_[MAXM];

bool charge(int x)
{
    for (int i = x; i < MAXM; i += x)
    {
        if (hash_[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        memset(hash_, 0, sizeof(hash_));
        
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &A[i]);
        }
        
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (A[i] > A[j])
                {
                    hash_[A[i] - A[j]] = 1;
                }
                else
                {
                    hash_[A[j] - A[i]] = 1;
                }
            }
        }
        for (int ans = n; ; ans++)
        {
            if (charge(ans))
            {
                printf("%d\n", ans);
                break;
            }
        }
    }
    
    return 0;
}
