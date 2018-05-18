//
//  main.cpp
//  f-51Nod-1637-幸运数字转换
//
//  Created by ZYJ on 2017/10/30.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 10;

int n, k;
char d[MAXN];

int main(int argc, const char * argv[])
{
    scanf("%d%d%s", &n, &k, d + 1);
    
    for (int i = 1; i < n && k; i++)
    {
        if (d[i] == '4' && d[i + 1] == '7')
        {
            k--;
            if (i & 1)
            {
                d[i + 1] = '4';
                if (d[i + 2] == '7')
                {
                    if (k & 1)
                    {
                        d[i + 1] = '7';
                    }
                    break;
                }
            }
            else
            {
                d[i] = '7';
                if (d[i - 1] == '4')
                {
                    if (k & 1)
                    {
                        d[i] = '4';
                    }
                    break;
                }
            }
        }
    }
    
    puts(d + 1);
    
    return 0;
}
