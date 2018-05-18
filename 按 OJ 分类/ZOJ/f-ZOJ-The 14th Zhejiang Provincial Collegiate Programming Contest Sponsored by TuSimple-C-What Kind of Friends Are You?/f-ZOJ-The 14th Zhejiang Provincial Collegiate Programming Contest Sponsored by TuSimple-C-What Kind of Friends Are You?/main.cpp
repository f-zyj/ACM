//
//  main.cpp
//  f-ZOJ-The 14th Zhejiang Provincial Collegiate Programming Contest Sponsored by TuSimple-C-What Kind of Friends Are You?
//
//  Created by ZYJ on 2017/4/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int MAXN = 110;
const int MAXQ = 25;
const int MAXC = 210;

int stateNQ[MAXN][MAXQ];
int stateCQ[MAXC][MAXQ];
int stateCQHash[MAXC];
int pow[MAXQ] = {1, 2};

int n, q, c;
string name;
string name_[MAXC];

map<string, int> msi;

void init()
{
    memset(stateNQ, 0, sizeof(stateNQ));
    memset(stateCQ, 0, sizeof(stateCQ));
    memset(stateCQHash, 0, sizeof(stateCQHash));
    msi.clear();
}

int Hash(int *state)
{
    int res = 0;
    for (int j = 0; j < q; j++)
    {
        res += state[j] * pow[j];
    }
    return res;
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    for (int i = 2; i < MAXQ; i++)
    {
        pow[i] = pow[i - 1] * 2;
    }
    
    int T;
    cin >> T;

    while (T--)
    {
        init();
        
        cin >> n >> q >> c;
        for (int i = 0; i < c; i++)
        {
            cin >> name;
            msi[name] = i;
            name_[i] = name;
        }
        int m;
        for (int i = 0; i < q; i++)
        {
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                cin >> name;
                stateCQ[msi[name]][i] = 1;
            }
        }
        
        for (int i = 0; i < c; i++)
        {
            stateCQHash[i] = Hash(stateCQ[i]);
        }
        
        int flag, cnt;
        for (int i = 0; i < n; i++)
        {
            flag = -1;
            cnt = 0;
            for (int j = 0; j < q; j++)
            {
                scanf("%d", &stateNQ[i][j]);
            }
            int res = Hash(stateNQ[i]);
            for (int j = 0; j < c; j++)
            {
                if (res == stateCQHash[j])
                {
                    if (flag == -1)
                    {
                        flag = j;
                    }
                    cnt++;
                }
            }
            if (cnt != 1)
            {
                cout << "Let's go to the library!!\n";
            }
            else
            {
                cout << name_[flag] << '\n';
            }
        }
    }
    
    return 0;
}
