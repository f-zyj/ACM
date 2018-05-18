//
//  main.cpp
//  f-HDU-5982-Relic Discovery
//
//  Created by ZYJ on 2017/10/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int n;

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &n);
        
        int sum = 0, x, y;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            
            sum += x * y;
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}
