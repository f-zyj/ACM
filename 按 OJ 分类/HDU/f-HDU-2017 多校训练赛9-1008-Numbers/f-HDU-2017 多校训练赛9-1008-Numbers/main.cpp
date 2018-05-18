//
//  main.cpp
//  f-HDU-2017 多校训练赛9-1008-Numbers
//
//  Created by ZYJ on 2017/8/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

map<int, int> mii;

const int MAXN = 1111;

int m;
int a[MAXN];

int main(int argc, const char * argv[])
{
    while (~scanf("%d", &m))
    {
        mii.clear();
        
        int x;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &x);
            mii[x]++;
        }
        
        int cnt = 0;
        for (auto i : mii)
        {
            while (i.second > 0)
            {
                for (int j = 0; j < cnt; j++)
                {
                    mii[i.first + a[j]]--;
                }
                i.second--;
                a[cnt++] = i.first;
            }
        }
        
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++)
        {
            printf("%d%c", a[i], i == cnt - 1 ? '\n' : ' ');
        }
    }
    
    return 0;
}
