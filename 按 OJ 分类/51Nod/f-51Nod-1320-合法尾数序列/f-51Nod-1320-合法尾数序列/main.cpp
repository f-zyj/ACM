//
//  main.cpp
//  f-51Nod-1320-合法尾数序列
//
//  Created by ZYJ on 16/9/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 55;
const int MAXM = MAXN + 10;
const int CYCL = 64;

int power[MAXM] = {1};
int tail[MAXM];
int d[MAXN];
int N;
int ans;

void init()
{
    for (int i = 1; i < MAXM; i++)
    {
        power[i] = power[i - 1] * 2;
    }
    
    for (int i = 1; i < MAXM; i++)
    {
        int res = i & (-i);
        for (int j = 0; j < MAXN; j++)
        {
            if (power[j] == res)
            {
                tail[i - 1] = j;
                break;
            }
        }
    }
    
    return ;
}

void solve(int n)
{
    if (n > N)
    {
        return ;
    }
    
    for (int i = 0; i < N - n + 1; i++)
    {
        for (int j = 0; j < CYCL; j++)
        {
            if (d[i] == tail[j] || (j == CYCL - 1 && d[i] >= tail[CYCL - 1]))
            {
                bool flag = true;
                for (int k = 1; k < n; k++)
                {
                    if (j + k == CYCL - 1 && d[i + k] >= tail[CYCL - 1])
                    {
                        continue;
                    }
                    if (d[i + k] != tail[(j + k) % CYCL])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    ans++;
                    break;
                }
            }
        }
    }

    solve(n + 1);
    
    return ;
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    init();
    
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> N;
        
        ans = N;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", d + i);
        }
        solve(2);
        
        cout << ans << '\n';
    }

    return 0;
}
