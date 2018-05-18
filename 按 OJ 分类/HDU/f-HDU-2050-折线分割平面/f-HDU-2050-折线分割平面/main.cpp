//
//  main.cpp
//  f-HDU-2050-折线分割平面
//
//  Created by ZYJ on 2016/11/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

const int MAXN = 10010;

int res[MAXN];

int main()
{
    int C;
    scanf("%d", &C);
    
    res[0] = 1;
    
    int lines = 0;
    for (int i = 1; i < MAXN; i++)
    {
        res[i] = res[i - 1] + lines * 2 + 1;
        lines += 2;
    }
    
    while (C--)
    {
        int Q;
        scanf("%d", &Q);
        printf("%d\n", res[Q]);
    }
    
    return 0;
}
