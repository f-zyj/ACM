//
//  main.cpp
//  f-51Nod-TalkingData数据科学精英夏令营挑战赛-D-数据流中的算法-众数
//
//  Created by ZYJ on 2017/6/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1000;

int n, k;
int pass[MAXN];
map<int, int> mii;

struct SetCmp
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    }
};

set<pair<int, int>, SetCmp> spii;
set<pair<int, int>, SetCmp>::iterator it;

inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

inline void Out(int a)
{
    if (a >= 10)
    {
        Out(a / 10);
    }
    putchar(a % 10 + '0');
}

int main(int argc, const char * argv[])
{
    memset(pass, -1, sizeof(pass));
    
    scan_d(n);
    scan_d(k);
    
    int q, id;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        scan_d(q);
        if (q == 1)
        {
            scan_d(id);
            if (!mii[id])
            {
                mii[id]++;
                spii.insert(make_pair(mii[id], id));
            }
            else
            {
                it = spii.find(make_pair(mii[id], id));
                mii[id]++;
                spii.erase(it);
                spii.insert(make_pair(mii[id], id));
            }
            
            if (pass[cnt] == -1)
            {
                pass[cnt++] = id;
                if (cnt == k)
                {
                    cnt = 0;
                }
            }
            else
            {
                int key = pass[cnt];
                it = spii.find(make_pair(mii[key], key));
                mii[key]--;
                spii.erase(it);
                if (mii[key])
                {
                    spii.insert(make_pair(mii[key], key));
                }
                pass[cnt++] = id;
                if (cnt == k)
                {
                    cnt = 0;
                }
            }
        }
        else
        {
            it = spii.end();
            it--;
            Out(it->second);
            putchar(10);
        }
    }
    
    return 0;
}
