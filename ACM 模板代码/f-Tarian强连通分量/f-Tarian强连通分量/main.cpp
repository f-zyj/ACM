//
//  main.cpp
//  f-Tarian强连通分量
//
//  Created by ZYJ on 16/7/17.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 *  Tarjan 强连通分量
 *  INIT: vec[]为邻接表; stop, cnt, scnt置0; pre[]置-1;
 *  CALL: for(i=0;i<n;++i)if(-1==pre[i])tarjan(i,n);
 */
const int V = 10010;
vector<int> vec[V];
int id[V], pre[V], low[V], s[V], stop, cnt, scnt;
void tarjan(int v, int n)   //  vertex: 0 ~ n-1
{
    int t, minc = low[v] = pre[v] = cnt++;
    vector<int>::iterator pv;
    s[stop++] = v;
    for (pv = vec[v].begin(); pv != vec[v].end(); ++pv)
    {
        if (-1 == pre[*pv])
        {
            tarjan(*pv, n);
        }
        if (low[*pv] < minc)
        {
            minc = low[*pv];
        }
    }
    if (minc < low[v])
    {
        low[v] = minc;
        return ;
    }
    do
    {
        id[t = s[--stop]] = scnt;
        low[t] = n;
    }
    while (t != v);
    ++scnt;         // 强连通分量的个数
    return ;
}

int main(int argc, const char * argv[])
{
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
