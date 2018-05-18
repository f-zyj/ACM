//
//  main.cpp
//  f-51Nod-1428-活动安排问题
//
//  Created by ZYJ on 16/8/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1e4 + 10;

struct party
{
    int point;
    bool flag;
} P[MAXN * 2];

int key = 0;
//  将头尾全部添加到一起
void addParty(int Begin, int End)
{
    P[key].point = Begin;
    P[key++].flag = true;
    P[key].point = End;
    P[key++].flag = false;
}

bool cmp(party a, party b)
{
    return a.point < b.point;
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int n;
    cin >> n;
    
    int Begin, End;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &Begin, &End);
        addParty(Begin, End);
    }
    
    sort(P, P + n + n, cmp);
    
    int res = 1;
    int flag = 0;
    for (int i = 0; i < n + n - 1; i++)
    {
        if (P[i].flag)
        {
            flag++;
        }
        else
        {
            res = res > flag ? res : flag;
            flag--;
        }
    }
    
    cout << res << '\n';
    return 0;
}
