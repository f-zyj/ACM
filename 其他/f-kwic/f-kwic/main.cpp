//
//  main.cpp
//  f-kwic
//
//  Created by ZYJ on 2017/11/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct line
{
    vector<string> vs;
} L;

vector<line> vl;

struct words
{
    int vl_pos, vs_pos;
};

vector<words> vw;

bool cmp(const words &a, const words &b)
{
    line La, Lb;
    for (int i = a.vs_pos; i < vl[a.vl_pos].vs.size(); i++)
    {
        La.vs.push_back(vl[a.vl_pos].vs[i]);
    }
    for (int i = 0; i < a.vs_pos; i++)
    {
        La.vs.push_back(vl[a.vl_pos].vs[i]);
    }
    
    for (int i = b.vs_pos; i < vl[b.vl_pos].vs.size(); i++)
    {
        Lb.vs.push_back(vl[b.vl_pos].vs[i]);
    }
    for (int i = 0; i < b.vs_pos; i++)
    {
        Lb.vs.push_back(vl[b.vl_pos].vs[i]);
    }
    
    int len = min((int)La.vs.size(), (int)Lb.vs.size());
    for (int i = 0; i < len; i++)
    {
        if (La.vs[i] != Lb.vs[i])
        {
            return La.vs[i] < Lb.vs[i];
        }
    }
    
    return La.vs.size() < Lb.vs.size();
}

string word;

int main()
{
    while (cin >> word)
    {
        L.vs.push_back(word);
        if (getchar() == '\n')
        {
            vl.push_back(L);
            L.vs.clear();   //  此处可以优化
        }
    }
    
    for (int i = 0; i < vl.size(); i++)
    {
        for (int j = 0; j < vl[i].vs.size(); j++)
        {
            vw.push_back({i, j});
        }
    }
    
    sort(vw.begin(), vw.end(), cmp);
    
    for (int i = 0; i < vw.size(); i++)
    {
        int vl_pos = vw[i].vl_pos, vs_pos = vw[i].vs_pos;
        int vs_sz = (int)vl[vw[i].vl_pos].vs.size(), c = 0;
        for (int j = vs_pos; j < vs_sz; j++)
        {
            c++;
            cout << vl[vl_pos].vs[j] << (c == vs_sz ? '\n' : ' ');
        }
        for (int j = 0; j < vs_pos; j++)
        {
            c++;
            cout << vl[vl_pos].vs[j] << (c == vs_sz ? '\n' : ' ');
        }
    }
    
    return 0;
}


