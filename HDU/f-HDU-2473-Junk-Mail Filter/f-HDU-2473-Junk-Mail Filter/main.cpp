//
//  main.cpp
//  f-HDU-2473-Junk-Mail Filter
//
//  Created by ZYJ on 2016/11/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
int pre[10 * MAXN];
int pre_[MAXN];
set<int> st;

void init()
{
    for (int i = 0; i < n; i++)
    {
        pre[i] = i;
        pre_[i] = i;
    }
}

int find(int x)
{
    if (x == pre[x])
    {
        return pre[x];
    }
    pre[x] = find(pre[x]);
    return pre[x];
}

void join(int x, int y)
{
    int a = find(x);
    int b = find(y);
    
    if (a == b)
    {
        return ;
    }
    pre[a] = b;
}

int main()
{
    int cas = 0, a, b;
    char str[2];
    
    while (scanf("%d %d", &n, &m) == 2 && (n + m))
    {
        init();
        st.clear();
        int num = n;
        
        while (m--)
        {
            scanf("%s", str);
            if (str[0] == 'S')
            {
                scanf("%d", &a);
                pre_[a] = num++;
                pre[pre_[a]] = pre_[a];
            }
            else
            {
                scanf("%d %d", &a, &b);
                join(pre_[a], pre_[b]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            st.insert(find(pre_[i]));
        }
        printf("Case #%d: %lu\n", ++cas, st.size());
    }
    
    return 0;
}
