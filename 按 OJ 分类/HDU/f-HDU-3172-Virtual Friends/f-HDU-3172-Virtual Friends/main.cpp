//
//  main.cpp
//  f-HDU-3172-Virtual Friends
//
//  Created by ZYJ on 2016/11/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAXN = 2e5 + 10;

int pre[MAXN];
int sum[MAXN];
int total;

map<string, int> people; //  用map来处理人名与数字下标之间的对应关系

int find(int x)
{
    if (x != pre[x])
    {
        pre[x] = find(pre[x]);
    }
    return pre[x];
}

int join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    
    if (fx != fy)
    {
        pre[fx] = fy;
        sum[fy] += sum[fx];
    }
    
    return sum[fy];
}

int main()
{
    int T, n;
    string a, b;
    
    while (cin >> T)
    {
        while (T--)
        {
            total = 0;
            people.clear();
            
            scanf("%d", &n);
            while (n--)
            {
                cin >> a >> b;
                if (people.find(a) == people.end())
                {
                    total++;
                    people[a] = total;
                    pre[total] = total;
                    sum[total] = 1;
                }
                if (people.find(b) == people.end())
                {
                    total++;
                    people[b] = total;
                    pre[total] = total;
                    sum[total] = 1;
                }
                int ans = join(people[a], people[b]);
                printf("%d\n", ans);
            }
        }
    }
    
    return 0;
}
