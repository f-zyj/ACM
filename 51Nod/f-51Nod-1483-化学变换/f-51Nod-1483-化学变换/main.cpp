//
//  main.cpp
//  f-51Nod-1483-化学变换
//
//  Created by ZYJ on 16/8/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int num[MAXN];
int sum[MAXN];
int N;

//  翻倍
void F(int temp, int cnt)
{
    for (temp = temp * 2, cnt++; temp < MAXN; temp *= 2, cnt++)
    {
        num[temp]++;
        sum[temp] += cnt;
    }
    return ;
}

int main(int argc, const char * argv[])
{
    while (cin >> N)
    {
        memset(num, 0, sizeof(num));
        memset(sum, 0, sizeof(num));
        
        for (int i = 0; i < N; i++)
        {
            int a, cnt = 0;
            cin >> a;
            bool flag = true;
            while (a)
            {
                num[a]++;
                sum[a] += cnt;
                if (flag)
                {
                    F(a, cnt);
                }
                if (a & 1)  //  如果是奇数，折半向下取整后可以继续翻倍
                {
                    flag = true;
                }
                else        //  如果是偶数，则不能继续翻倍
                {
                    flag = false;
                }
                a /= 2; //  折半(向下取整)
                cnt++;
            }
        }
        int ans = INF;
        for (int i = 0; i < MAXN; i++)
        {
            if (num[i] == N)    //  可以全部变换到这个状态
            {
                ans = min(ans, sum[i]);
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
