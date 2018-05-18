//
//  main.cpp
//  f-51Nod-1285-山峰和分段
//
//  Created by ZYJ on 16/8/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 5e4 + 10;
//const int INF = 0x3f3f3f3f;

int point[MAXN];            //  点数据
int peak[MAXN] = {0};       //  峰数据,B[0]存峰个数,1表示峰
int pre[MAXN] = {0};        //  峰数据,前i个点有几个峰

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", point + i);
    }
    for (int i = 2; i < N; i++)
    {
        if (point[i - 1] < point[i] && point[i + 1] < point[i])
        {
            peak[0]++;
            peak[i]++;
        }
    }
    
    for (int i = 1; i <= N; i++)
    {
        pre[i] = pre[i - 1];
        if (peak[i])
        {
            pre[i]++;
        }
    }
    
    int ans = 0;
    for (int i = peak[0]; i > 0; i--)
    {
        if (N % i)      //  无法整分
        {
            continue;
        }
        ans = i;
        int z = N / i;  //  z为山峰长度
        int j = z;
        for (; j <= N; j += z)
        {
            if (pre[j] - pre[j - z] == 0)   //  此段无峰
            {
                break;
            }
        }
        if (j > N)      //  符合条件的划分方式
        {
            break;
        }
    }
    
    std::cout << ans << '\n';
    return 0;
}
