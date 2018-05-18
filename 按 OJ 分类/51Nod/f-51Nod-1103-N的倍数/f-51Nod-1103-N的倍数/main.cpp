//
//  main.cpp
//  f-51Nod-1103-N的倍数
//
//  Created by ZYJ on 16/8/19.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

typedef long long ll;

using namespace std;

const int MAXN = 5e4 + 10;

int A[MAXN];

ll sum[MAXN];

int main(int argc, const char * argv[])
{
    int N;
    while (cin >> N)
    {
        int flag = 0;
        sum[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", A + i);
            sum[i] = (sum[i - 1] + A[i]) % N;
            if (sum[i] == 0)    //  从1~相加符合
            {
                flag = i;
            }
        }
        
        if (flag)               //  输出结果并continue
        {
            printf("%d\n", flag);
            for (int i = 1; i <= flag; i++)
            {
                printf("%d\n", A[i]);
            }
            continue;
        }
        
        int left = 0, right = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                if (sum[i] == sum[j])
                {
                    left = i + 1;
                    right = j;
                    flag = j - i;   //  查找到结果
                    break;
                }
            }
            if (flag)               //  查找到则跳出
            {
                break;
            }
        }
        
        if (flag)
        {
            printf("%d\n", flag);
            for (int i = left; i <= right; i++)
            {
                printf("%d\n", A[i]);
            }
        }
        else
        {
            printf("No Solution\n");
        }
    }
    
    return 0;
}
