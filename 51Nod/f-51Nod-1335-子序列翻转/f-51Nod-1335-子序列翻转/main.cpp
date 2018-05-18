//
//  main.cpp
//  f-51Nod-1335-子序列翻转
//
//  Created by ZYJ on 16/9/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 2505;
const int MAXL = 26;

int letter[MAXL];
char s[MAXN];

int main(int argc, const char * argv[])
{
//     freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int T;
    cin >> T;
    
    while (T--)
    {
        int x = 0;
        int y[MAXN] = {0};
        memset(letter, 0, sizeof(letter));
        cin >> s;
        int len = (int)strlen(s);
        int i;
        for (i = 0; i < len; i++)
        {
            letter[s[i] - 'a']++;
        }
        for (i = 0; i < MAXL; i++)
        {
            if (!letter[i])
            {
                continue;
            }
            for (int j = 0; j < len; j++)
            {
                while (!letter[i])
                {
                    i++;
                }
                if (s[j] - 'a' == i)
                {
                    letter[i]--;
                }
                else
                {
                    x = j;
                    int key = 0;
                    for (int k = j + 1; k < len; k++)
                    {
                        if (s[k] - 'a' == i)
                        {
                            y[key++] = k;
                            if (key == letter[i])
                            {
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            break;
        }
        int ansY = y[0];
        for (int j = 1; j < letter[i]; j++)
        {
            bool flag = true;
            for (int k = 1; k < ansY - x + 1; k++)
            {
                if (s[ansY - k] > s[y[j] - k])
                {
                    ansY = y[j];
                    flag = false;
                    break;
                }
                else if (s[ansY - k] < s[y[j] - k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (int k = 1; k < y[j] - ansY + 1; k++)
                {
                    if (s[ansY + k] > s[y[j] - ansY + x - k])
                    {
                        ansY = y[j];
                        break;
                    }
                    else if (s[ansY + k] < s[y[j] - ansY + x - k])
                    {
                        break;
                    }
                }
            }
        }
        
        cout << x << ' ' << ansY << '\n';
    }
    
    return 0;
}
