//
//  main.cpp
//  f-HDU-5878-I Count Two Three
//
//  Created by ZYJ on 2017/6/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5555;
const int MAXM = 4;

int bs[MAXN] = {1, 2, 3, 4, 5,
				6, 7, 8, 9, 10};
int tp[MAXM] = {2, 3, 5, 7};

void init()
{
    int cnt;
    for (int i = 10; i < MAXN; i++)
    {
        cnt = i - 1;
        bs[i] = INT_MAX;
        for (int j = 0; j < 4; j++)
        {
            while (bs[cnt - 1] * tp[j] > bs[i - 1])
            {
                cnt--;
            }
            bs[i] = min(bs[i], bs[cnt] * tp[j]);
        }
    }
}

int n;

int main()
{
    init();
    
    int t;
    cin >> t;
    
    while (t--)
    {
        scanf("%d", &n);
        int res = *lower_bound(bs, bs + MAXN, n);
        printf("%d\n", res);
    }		
}
