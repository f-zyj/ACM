//
//  main.cpp
//  f-51Nod-1430-奇偶游戏
//
//  Created by ZYJ on 2017/9/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

void D_win()
{
    cout << "Daenerys" << endl;
}

void S_win()
{
    cout << "Stannis" << endl;
}

int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    
    int cnt1 = 0, cnt2, x;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (x & 1)
        {
            cnt1++;
        }
    }
    cnt2 = n - cnt1;
    
    int D_cnt = (n - k) >> 1;   //  后手取的次数
    int S_cnt = (n - k) & 1 ? D_cnt + 1 : D_cnt;
    
    if (cnt1 <= D_cnt)
    {
        D_win();
        return 0;
    }
    
    if (((k & 1) == 0) && cnt2 <= D_cnt)
    {
        D_win();
        return 0;
    }
    
    if (((k & 1) == 1) && cnt2 <= S_cnt)
    {
        S_win();
        return 0;
    }
    
    if (n == k)
    {
        if ((cnt1 & 1) == 0)
        {
            D_win();
        }
        else
        {
            S_win();
        }
        return 0;
    }
    
    if (S_cnt > D_cnt)
    {
        S_win();
    }
    else
    {
        D_win();
    }
    
    return 0;
}
