//
//  main.cpp
//  f-HDU-1847-Good Luck in CET-4 Everybody!
//
//  Created by ZYJ on 2017/9/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1010;
const int MAXM = 32;

int n;
int f[MAXM];
int SG[MAXN];
int _hash[MAXN];

void get_SG(int n)
{
    memset(SG, 0, sizeof(SG));
    
    for (int i = 1; i <= n; i++)
    {
        memset(_hash, 0, sizeof(_hash));
        
        for (int j = 1; f[j] <= i; j++)
        {
            _hash[SG[i - f[j]]] = 1;
        }
        for (int j = 0; j <= n; j++)
        {
            if (_hash[j] == 0)
            {
                SG[i] = j;
                break;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    f[1] = 1;
    for (int i = 2; i < MAXM; i++)
    {
        f[i] = f[i - 1] << 1;
    }
    get_SG(MAXN - 1);
    
    while (cin >> n)
    {
        if (SG[n])
        {
            puts("Kiki");
        }
        else
        {
            puts("Cici");
        }
    }
    
    return 0;
}
