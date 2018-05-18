//
//  main.cpp
//  f-51Nod-1243-排船的问题
//
//  Created by ZYJ on 16/8/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 5e4 + 5;

int N, X, M;
int P[MAXN];

int judge(int d)
{
    int st = 2 * X;                     //  船尾可以放置的首位置
    for (int i = 0; i < N; i++)
    {
        if (abs(st - P[i] - X) <= d)    //  绳子的长度小于等于d
        {
            st += 2 * X;                //  推移到下一个位置
        }
        else
        {
            if (P[i] - d + X > st)      //  如果在绳长为d时，可以放下船
            {
                st = P[i] - d + X;      //  更新首位置
            }
            else
            {
                return 0;
            }
            st += 2 * X;                //  推移到下一个位置
        }
    }
    if (st - 2 * X > M)                 //  最后一个船越界了
    {
        return 0;
    }
    return 1;
}

//  二分
int bs(int left, int right)
{
    int ans = M;
    int mid;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (judge(mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    cin >> N >> X >> M;
    
    if (2 * X * N > M)
    {
        cout << "-1\n";
        return 0;
    }
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", P + i);
    }
    
    //  二分，绳子长度为0到M-1
    int ans = bs(0, M - 1);
    
    std::cout << ans << '\n';
    return 0;
}
