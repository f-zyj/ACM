//
//  main.cpp
//  f-图灵杯-第四届“图灵杯”NEUQ-ACM 程序设计竞赛-J-简单的变位词
//
//  Created by ZYJ on 2017/6/11.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 33333;

int cnt = 0, head = 1;
string s;
string A[MAXN];
string B[MAXN];
map<string, int> msi;
vector<string> vs[MAXN];

bool cmp(vector<string> a, vector<string> b)
{
    if (a.size() != b.size())
    {
        return a.size() > b.size();
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    while (cin >> s)
    {
        A[cnt] = s;
        sort(s.begin(), s.end());
        if (msi[s] == 0)
        {
            msi[s] = head++;
        }
        vs[msi[s]].push_back(A[cnt]);
        cnt++;
    }
    
    for (int i = 1; i < head; i++)
    {
        sort(vs[i].begin(), vs[i].end());
        unique(vs[i].begin(), vs[i].end());
    }
    sort(vs + 1, vs + head, cmp);
    
    if (head > 5)
    {
        for (int i = 1; i <= 5; i++)
        {
            printf("Group of size %lu: ", vs[i].size());
            for (int j = 0; j < vs[i].size(); j++)
            {
                if (j > 0 && vs[i][j] <= vs[i][j - 1])
                {
                    break;
                }
                cout << vs[i][j] << ' ';
            }
            puts(".");
        }
    }
    else
    {
        for (int i = 1; i < head; i++)
        {
            printf("Group of size %lu: ", vs[i].size());
            for (int j = 0; j < vs[i].size(); j++)
            {
                cout << vs[i][j] << ' ';
            }
            puts(".");
        }
    }
    
    return 0;
}
