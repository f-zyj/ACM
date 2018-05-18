//
//  main.cpp
//  f-51Nod-1478-括号序列的最长合法子段
//
//  Created by ZYJ on 2016/9/26.
//  Copyright ? 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#include <string.h>
//
//const int MAXN = 1e6 + 5;
//
//char s[MAXN];
//
//int main(int argc, const char * argv[])
//{
//    scanf("%s", s);
//    
//    int len = (int)strlen(s);
//    int numA = 0, numB = 0;
//    int res = 0, count = 1;
//    for (int i = 0; i < len; i++)
//    {
//        if (s[i] == '(')
//        {
//            numA++;
//        }
//        else
//        {
//            if (numA == numB)
//            {
//                numA = numB = 0;
//                continue;
//            }
//            numB++;
//            if (numA == numB && numA + numB >= res)
//            {
//                if (res < numA + numB)
//                {
//                    res = numA + numB;
//                    count = 1;
//                }
//                else
//                {
//                    count++;
//                }
//            }
//            else if (numA > numB && numB + numB >= res)
//            {
//                int pos = i - numB - numB;
//                int A = 0, B = 0;
//                for (int j = i; j > pos; j--)
//                {
//                    if (s[j] == ')')
//                    {
//                        B++;
//                    }
//                    else
//                    {
//                        if (A == B)
//                        {
//                            break;
//                        }
//                        A++;
//                        if (A == B && A + B >= res)
//                        {
//                            if (res < A + B)
//                            {
//                                res = A + B;
//                                count = 1;
//                            }
//                            else
//                            {
//                                count++;
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    
//    printf("%d %d\n", res, count);
//    
//    return 0;
//}

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

char s[MAXN];
int vis[MAXN];

int main()
{
    scanf("%s", s + 1);
    memset(vis, 0, sizeof(vis));
    stack<int> sta;
    int l = (int)strlen(s + 1);
    int res = 0, tmp, count = 1;
    for (int i = 1; i <= l; i++)
    {
        if (s[i] == '(')
        {
            sta.push(i);
        }
        else
        {
            if (!sta.empty())
            {
                vis[i] = 1;
                vis[sta.top()] = 1;
                sta.pop();
            }
        }
    }
    tmp = res = 0;
    for (int i = 1; i <= l; i++)
    {
        if (vis[i])
        {
            tmp++;
        }
        else
        {
            tmp = 0;
        }
        if (tmp == res && res)
        {
            count++;
        }
        else if (tmp > res)
        {
            count = 1, res = tmp;
        }
    }
    
    cout << res << " " << count << endl;
    
    return 0;
}
