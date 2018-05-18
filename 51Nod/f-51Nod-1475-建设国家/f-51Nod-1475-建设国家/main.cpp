//
//  main.cpp
//  f-51Nod-1475-建设国家
//
//  Created by ZYJ on 16/8/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1001;

struct city
{
    int hi;
    int pi;
} City[MAXN];

int sum[MAXN];

bool cmp(city a, city b)
{
    return a.hi > b.hi;
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int n;
    long long H;
    cin >> n >> H;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> City[i].hi >> City[i].pi;
    }
    sort(City + 1, City + n + 1, cmp);
    
    city temp_1[MAXN];
    city temp_0[MAXN];
    int key_1 = 1;
    int key_0 = 1;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (key_1 + City[i].hi <= H)
        {
            temp_1[key_1++] = City[i];
        }
        else
        {
            flag++;
            int pos = 0;
            int mink = City[i].pi;
            for (int j = 1; j + City[i].hi <= H; j++)
            {
                if (temp_1[j].pi < mink)
                {
                    mink = temp_1[j].pi;
                    pos = j;
                }
            }
            if (pos)
            {
                temp_0[key_0++] = temp_1[pos];
                temp_1[pos] = City[i];
            }
            else
            {
                temp_0[key_0++] = City[i];
            }
        }
    }
    
    for (int i = 1; i < key_1; i++)
    {
        sum[i] = sum[i - 1] + temp_1[i].pi;
    }
    int ans = sum[key_1 - 1];
    int key = 0;
    long long maxh = H - key_1 + 1;
    for (int i = 1; i < key_1 - 1; i++)
    {
        if (temp_1[i].hi <= maxh)
        {
            key = i;
        }
    }
    
    for (int i = 1; i < key_0; i++)
    {
        ans = ans > sum[H - temp_0[i].hi] + temp_0[i].pi || H - temp_0[i].hi == 0 ? ans : sum[H - temp_0[i].hi] + temp_0[i].pi;
        if (key + temp_0[i].hi <= H && key != 0)
        {
            ans = ans > sum[key_1 - 1] + temp_0[i].pi ? ans : sum[key_1 - 1] + temp_0[i].pi;
        }
    }

    std::cout << ans << '\n';
    return 0;
}
