//
//  main.cpp
//  f-51Nod-1422-沙拉酱前缀
//
//  Created by ZYJ on 16/9/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int n;

ll pos[MAXN];   //  存储每个操作后的长度（位置）

struct ope
{
    int val;
    int oper;   //  当前命令
    
    int x;      //  命令1：添加的数字
    
    int li;     //  命令2：前缀的长度
    int ci;     //        复制的次数
} op[MAXN];

void input()
{
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &op[i].oper);
        if (op[i].oper == 1)
        {
            scanf("%d", &op[i].val);
            pos[i] = pos[i - 1] + 1;
        }
        else
        {
            scanf("%d%d", &op[i].li, &op[i].ci);
            pos[i] = pos[i - 1] + op[i].li * op[i].ci;
        }
    }
}

void solve()
{
    int i, k;
    ll ans;
    scanf("%d", &k);
    
    for (i = 1; i <= k; i++)
    {
        scanf("%lld", &ans);
        
        //  不断向前检索ans位置的对应的指令，如果是1直接输出，否则继续向前检索
        while (true)
        {
            int p = (int)(lower_bound(pos + 1, pos + n, ans) - pos);
            if (op[p].oper == 1)
            {
                printf("%d ", op[p].val);
                break;
            }
            else
            {
                ans = ans - pos[p - 1]; //  截去前缀
                ans = ans % op[p].li;
                if (ans == 0)
                {
                    ans = op[p].li;
                }
            }
        }
    }
    return ;
}

int main()
{
    input();
    solve();
    
    return 0;
}
