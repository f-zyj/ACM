//
//  main.cpp
//  f-51Nod-1523-非回文
//
//  Created by ZYJ on 2016/10/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//const int MAXN = 1010;
//
//char s[MAXN];
//
//int main(int argc, const char * argv[])
//{
//    freopen("/Users/zyj/Desktop/51nod_Problem_1523_Test_18_In.txt", "r", stdin);
//    freopen("/Users/zyj/Desktop/output.txt", "w", stdout);
//    
//    int n, p;
//    while (cin >> n >> p)
//    {
//        char ss[MAXN];
//        
//        scanf("%s", s);
//        int len = (int)strlen(s);
//        for (int i = 0; i < len && i < n; i++)
//        {
//            ss[i] = s[i];
//        }
//        int flag = 0;
//        for (int i = len; i < n; i++)
//        {
//            flag = 1;
//            for (int j = 0; j < p; j++)
//            {
//                if ('a' + j != ss[i - 1] && 'a' + j != ss[i - 2])
//                {
//                    ss[i] = 'a' + j;
//                    flag = 0;
//                    break;
//                }
//            }
//            if (flag)
//            {
//                puts("NO");
//                break;
//            }
//        }
//        if (flag)
//        {
//            continue;
//        }
//        if (len < n)
//        {
//            puts(ss);
//        }
//        else
//        {
//            //  flag = 0;
//            for (int i = n - 1; i >= 0; i--)
//            {
//                for (int j = ss[i] + 1; j < 'a' + p; j++)
//                {
//                    if (i > 0 && j == ss[i - 1])
//                    {
//                        continue;
//                    }
//                    else if (i > 1 && j == ss[i - 2])
//                    {
//                        continue;
//                    }
//                    else
//                    {
//                        ss[i] = j;
//                        flag = 1;
//                        break;
//                    }
//                }
//                if (flag)
//                {
//                    for (int j = i + 1; j < n; j++)
//                    {
//                        for (int k = 0; k < p; k++)
//                        {
//                            if (j > 1)
//                            {
//                                if ('a' + k != ss[j - 1] && 'a' + k != ss[j - 2])
//                                {
//                                    ss[j] = 'a' + k;
//                                    break;
//                                }
//                            }
//                            else if (j > 0)
//                            {
//                                if ('a' + k != ss[j - 1])
//                                {
//                                    ss[j] = 'a' + k;
//                                    break;
//                                }
//                            }
//                        }
//                    }
//                    puts(ss);
//                    break;
//                }
//            }
//            if (!flag)
//            {
//                puts("NO");
//            }
//        }
//    }
//    
//    return 0;
//}

#include <cstdio>

using namespace std;

const int MAXN = 1005;

int N, P;
char s[MAXN];

bool check(int v)
{
    if (v > 0 && s[v] == s[v - 1])
    {
        return false;
    }
    if (v > 1 && s[v] == s[v - 2])
    {
        return false;
    }
    return true;
}

bool solve(int v)
{
    while (true)
    {
        if (v >= N)
        {
            return true;
        }
        
        if (v < 0)
        {
            return false;
        }
        
        if (s[v] - 'a' == P - 1)
        {
            s[v] = 'a' - 1;
            v--;
        }
        else
        {
            int k = (s[v] - 'a' + 1) % P;
            if (k < 0)
            {
                k = 0;
            }
            s[v] = 'a' + k;
            
            if (check(v))
            {
                v++;
            }
        }
    }
    return false;
}

int main ()
{
    scanf("%d%d%s", &N, &P, s);
    
    if (solve(N - 1))
    {
        s[N] = '\0';
        printf("%s\n", s);
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}
