//
//  main.cpp
//  f-51Nod-1400-序列分解
//
//  Created by ZYJ on 16/9/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 41;

int n;
int a[MAXN];
int b[MAXN];
int c[MAXN];
bool flag;

void dfs(int posA, int posB, int posC)
{
    if (posB > n / 2)
    {
        return ;
    }
    if (posB == posC && posA == n)
    {
        flag = true;
        return ;
    }
    for (int i = posA; i < n; i++)
    {
        if (posB == posC)
        {
            b[++posB] = a[i];
        }
        else if (b[posC + 1] == a[i])
        {
            if (flag)
            {
                break;
            }
            c[++posC] = a[i];
            dfs(i + 1, posB, posC);
            if (flag)
            {
                break;
            }
            posC--;
            b[++posB] = a[i];
            dfs(i + 1, posB, posC);
            return ;
        }
        else
        {
            b[++posB] = a[i];
        }
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        flag = false;
        
        dfs(0, -1, -1);
        
        if (flag)
        {
            cout << "Good job!!\n";
        }
        else
        {
            cout << "What a pity!\n";
        }
    }
    
    return 0;
}
