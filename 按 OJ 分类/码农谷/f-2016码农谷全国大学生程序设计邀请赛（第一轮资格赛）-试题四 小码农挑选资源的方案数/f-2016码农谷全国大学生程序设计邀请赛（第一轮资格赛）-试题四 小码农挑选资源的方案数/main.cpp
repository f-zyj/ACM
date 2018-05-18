//
//  main.cpp
//  f-2016码农谷全国大学生程序设计邀请赛（第一轮资格赛）-试题四 小码农挑选资源的方案数
//
//  Created by ZYJ on 16/7/16.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int N;
int sum = 0;
int res = 0;
int price[101];
int flag[101] = {0};

void solve(int n, int s, int q)
{
    if (n < N && s == sum / 2 && q == 1)
    {
        res++;
        return ;
    }
    if (n == N || s > sum / 2 || q == 1)
    {
        return ;
    }
    solve(n + 1, s + price[n], q--);
    solve(n + 1, s, q);
    return ;
}
int main(int argc, const char * argv[])
{
   
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> price[i];
        sum += price[i];
    }
    
    solve(0, 0, 3);
    
    cout << res << '\n';
    
    return 0;
}
