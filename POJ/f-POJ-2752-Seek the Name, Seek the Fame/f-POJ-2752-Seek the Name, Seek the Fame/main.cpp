//
//  main.cpp
//  f-POJ-2752-Seek the Name, Seek the Fame
//
//  Created by ZYJ on 2017/10/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1e6;

int n;
char s[MAXN];
int nxt[MAXN];
vector<int> ans;

void getnxt()
{
    nxt[0] = -1;
    int i = 0, j = -1;
    int len = (int)strlen(s);
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            nxt[i] = j;
        }
        else
        {
            j = nxt[j];
        }
    }
}

int main()
{
    while (~scanf("%s", s))
    {
        int len = (int)strlen(s);
        
        getnxt();
     
        ans.clear();
        int pos = nxt[len - 1];
        while (pos != -1)
        {
            if (s[pos] == s[len - 1])
            {
                ans.push_back(pos + 1);
            }
            pos = nxt[pos];
        }
        
        for (int i = (int)ans.size() - 1; i >= 0; i--)
        {
            printf("%d ", ans[i]);
        }
        printf("%d\n", len);
    }
    
    return 0;
}
