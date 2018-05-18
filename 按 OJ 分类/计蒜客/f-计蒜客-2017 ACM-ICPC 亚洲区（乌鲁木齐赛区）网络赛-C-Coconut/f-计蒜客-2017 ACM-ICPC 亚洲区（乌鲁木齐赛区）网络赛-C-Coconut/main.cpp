//
//  main.cpp
//  f-计蒜客-2017 ACM-ICPC 亚洲区（乌鲁木齐赛区）网络赛-C-Coconut
//
//  Created by ZYJ on 2017/9/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1111;

int N, b;
int C[MAXN];
int D[MAXN];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        scanf("%d%d", &N, &b);
        
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", C + i);
        }
        for (int i = 2; i <= N; i++)
        {
            scanf("%d", D + i);
        }
        
        int sum = C[1], dis = 0, flag = 1;
        for (int i = 2; i <= N; i++)
        {
            dis += D[i];
            if (sum < dis * b)
            {
                flag = 0;
                break;
            }
            sum += C[i];
        }
        
        if (flag)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    
    return 0;
}
