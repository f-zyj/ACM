//
//  main.cpp
//  f-51Nod-1639-绑鞋带
//
//  Created by ZYJ on 16/8/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    
    while(~scanf("%d", &n))
    {
        double ans = 1.0;
        for (int i = 2; i <= n; i++)
        {
            ans = ans * (i - 1) * 2.0 / (2.0 * i - 1);
        }
        printf("%.8lf\n", ans);
    }
    return 0;
}