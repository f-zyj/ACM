//
//  main.cpp
//  f-EOJ-大学生程序设计邀请赛（华东师范大学）-A-拼音魔法
//
//  Created by ZYJ on 2017/5/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10;

char s[MAXN];

int main()
{
    int n;
    cin >> n;
    
    int cs = 1;
    while (n--)
    {
        scanf("%s", s);
        printf("Case %d: ", cs++);
        int len = (int)strlen(s);
        int flag = 0;
        if (s[len - 1] >= '1' && s[len - 1] <= '4')
        {
            flag = s[len - 1] - '0';
            len--;
        }
        int a = 0, e = 0, i = 0, o = 0, u = 0, v = 0;
        for (int j = 0; j < len; j++)
        {
            if (s[j] == 'a')
            {
                a++;
            }
            else if (s[j] == 'e')
            {
                e++;
            }
            else if (s[j] == 'i')
            {
                i++;
            }
            else if (s[j] == 'o')
            {
                o++;
            }
            else if (s[j] == 'u')
            {
                u++;
            }
            else if (s[j] == 'v')
            {
                v++;
                if (s[j + 1] == 'e' || s[j + 1] == 'n')
                {
                    s[j] = 'u';
                    u++;
                    v--;
                }
            }
        }
        for (int j = 0; j < len; j++)
        {
            if (s[j] == 'a')
            {
                switch (flag)
                {
                    case 0:
                        cout << "a";
                        break;
                    case 1:
                        cout << "ā";
                        break;
                    case 2:
                        cout << "á";
                        break;
                    case 3:
                        cout << "ǎ";
                        break;
                    case 4:
                        cout << "à";
                        break;
                }
                flag = 0;
                a--;
            }
            else if (a == 0 && s[j] == 'o')
            {
                switch (flag)
                {
                    case 0:
                        cout << "o";
                        break;
                    case 1:
                        cout << "ō";
                        break;
                    case 2:
                        cout << "ó";
                        break;
                    case 3:
                        cout << "ǒ";
                        break;
                    case 4:
                        cout << "ò";
                        break;
                }
                flag = 0;
                o--;
            }
            else if (a == 0 && s[j] == 'e')
            {
                switch (flag)
                {
                    case 0:
                        cout << "e";
                        break;
                    case 1:
                        cout << "ē";
                        break;
                    case 2:
                        cout << "é";
                        break;
                    case 3:
                        cout << "ě";
                        break;
                    case 4:
                        cout << "è";
                        break;
                }
                flag = 0;
                e--;
            }
            else if (a == 0 && o == 0 && e == 0 && s[j] == 'i')
            {
                if (s[j + 1] == 'u')
                {
                    cout << "i";
                    i--;
                    continue;
                }
                switch (flag)
                {
                    case 0:
                        cout << "i";
                        break;
                    case 1:
                        cout << "ī";
                        break;
                    case 2:
                        cout << "í";
                        break;
                    case 3:
                        cout << "ǐ";
                        break;
                    case 4:
                        cout << "ì";
                        break;
                }
                flag = 0;
                i--;
            }
            else if (a == 0 && o == 0 && e == 0 && s[j] == 'u')
            {
                if (s[j + 1] == 'i')
                {
                    cout << "u";
                    u--;
                    continue;
                }
                switch (flag)
                {
                    case 0:
                        cout << "u";
                        break;
                    case 1:
                        cout << "ū";
                        break;
                    case 2:
                        cout << "ú";
                        break;
                    case 3:
                        cout << "ǔ";
                        break;
                    case 4:
                        cout << "ù";
                        break;
                }
                flag = 0;
                u--;
            }
            else if (a == 0 && o == 0 && e == 0 && i == 0 && u == 0 && s[j] == 'v')
            {
                switch (flag)
                {
                    case 0:
                        cout << "ü";
                        break;
                    case 1:
                        cout << "ǖ";
                        break;
                    case 2:
                        cout << "ǘ";
                        break;
                    case 3:
                        cout << "ǚ";
                        break;
                    case 4:
                        cout << "ǜ";
                        break;
                }
                flag = 0;
                v--;
            }
            else
            {
                if (s[j] == 'v')
                {
                    cout << "ü";
                    v--;
                }
                else if (s[j] == 'a')
                {
                    cout << "a";
                    a--;
                }
                else if (s[j] == 'e')
                {
                    cout << "e";
                    e--;
                }
                else if (s[j] == 'i')
                {
                    cout << "i";
                    i--;
                }
                else if (s[j] == 'o')
                {
                    cout << "o";
                    o--;
                }
                else if (s[j] == 'u')
                {
                    cout << "u";
                    u--;
                }
                else
                {
                    cout << s[j];
                }
            }
        }
        
        cout << '\n';
    }
    
    return 0;
}
