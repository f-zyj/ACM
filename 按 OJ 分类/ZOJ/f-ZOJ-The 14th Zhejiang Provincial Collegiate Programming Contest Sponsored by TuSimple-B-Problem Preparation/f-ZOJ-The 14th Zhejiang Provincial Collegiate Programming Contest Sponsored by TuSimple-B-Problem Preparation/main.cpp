//
//  main.cpp
//  f-ZOJ-The 14th Zhejiang Provincial Collegiate Programming Contest Sponsored by TuSimple-B-Problem Preparation
//
//  Created by ZYJ on 2017/4/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 110;

int s[MAXN];

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int T;
    scanf("%d", &T);
    
    int n;
    while (T--)
    {
        scanf("%d", &n);
//        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", s + i);
//            if (s[i] == 1)
//            {
//                cnt++;
//            }
        }
        if (n < 10 || n > 13/* || cnt < 2*/)
        {
            printf("No\n");
            continue;
        }
        
        sort(s, s + n);
        
        //  ???
        if (s[0] != 1 || s[0] != 1)
        {
            printf("No\n");
            continue;
        }
        
        int flag = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] - s[i - 1] > 2 && s[i] != s[n - 1])
            {
                flag = 0;
                break;
            }
        }
        
        if (flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    
    return 0;
}
