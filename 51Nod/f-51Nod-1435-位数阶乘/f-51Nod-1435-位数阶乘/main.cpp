//
//  main.cpp
//  f-51Nod-1435-位数阶乘
//
//  Created by ZYJ on 16/9/19.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 16;
const int MAXM = 10;
const int MAXA = 300;

char num[MAXN];
int num_[MAXN];
int dig[MAXM];
int ans[MAXA];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    cin >> num;
    for (int i = 0; i < n; i++)
    {
        num_[i] = num[i] - '0';
        for (int j = 2; j <= num_[i]; j++)
        {
            if (j == 4)
            {
                dig[2] += 2;
            }
            else if (j == 6)
            {
                dig[2]++;
                dig[3]++;
            }
            else if (j == 8)
            {
                dig[2] += 3;
            }
            else if (j == 9)
            {
                dig[3] += 2;
            }
            else
            {
                dig[j]++;
            }
        }
    }
    int pos = 0;
    for (int i = 7; i > 1; i--)
    {
        if (dig[i] > 0)
        {
            switch (i)
            {
                case 7:
                    for (int j = 0; j < dig[7]; j++)
                    {
                        ans[pos++] = 7;
                    }
                    dig[2] -= dig[7] * 4;
                    dig[3] -= dig[7] * 2;
                    dig[5] -= dig[7];
                    break;
                case 5:
                    for (int j = 0; j < dig[5]; j++)
                    {
                        ans[pos++] = 5;
                    }
                    dig[2] -= dig[5] * 3;
                    dig[3] -= dig[5];
                    break;
                case 3:
                    for (int j = 0; j < dig[3]; j++)
                    {
                        ans[pos++] = 3;
                    }
                    dig[2] -= dig[3];
                    break;
                case 2:
                    for (int j = 0; j < dig[2]; j++)
                    {
                        ans[pos++] = 2;
                    }
                    break;
            }
        }
    }
    
    for (int i = 0; i < pos; i++)
    {
        cout << ans[i];
    }
    cout << '\n';
    
    return 0;
}
