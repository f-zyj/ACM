//
//  main.cpp
//  f-51Nod-1241-特殊的排序
//
//  Created by ZYJ on 2017/4/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 5;

int A[MAXN], pre[MAXN];

int main()
{
    int N;
    
    while (~scanf("%d", &N))
    {
        memset(pre, 0, sizeof(pre));
        
        int res = 0;
        for (int i = 1; i <= N; ++i)
        {
            scanf("%d", &A[i]);
            pre[A[i]] = pre[A[i] - 1] + 1;
            res = max(res, pre[A[i]]);
        }
        printf("%d\n", N - res);
    }
    
    return 0;
}
