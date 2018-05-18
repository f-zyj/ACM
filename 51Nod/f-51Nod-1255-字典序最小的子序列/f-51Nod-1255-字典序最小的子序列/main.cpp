//
//  main.cpp
//  f-51Nod-1255-字典序最小的子序列
//
//  Created by ZYJ on 16/8/29.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstring>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//const int MAXM = 27;
//
//char S[MAXN];
//char SS[MAXM];
//int Sflag[MAXM];
//bool SSflag[MAXM];
//
//void order(int pos, int len)
//{
//    char s = SS[pos];
//    for (int i = pos; i < len - 1; i++)
//    {
//        SS[i] = SS[i + 1];
//    }
//    SS[len - 1] = s;
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    scanf("%s", S);
//    
//    int lenS = (int)strlen(S);
//    int lenSS = 0;
//    
//    for (int i = 0; i < lenS; i++)
//    {
//        Sflag[S[i] - 'a']++;
//    }
//    
//    for (int i = 0; i < lenS; i++)
//    {
//        Sflag[S[i] - 'a']--;
//        if (!SSflag[S[i] - 'a'])
//        {
//            SS[lenSS++] = S[i];
//            SSflag[S[i] - 'a'] = 1;
//            continue;
//        }
//        for (int j = 0; j < lenSS; j++)
//        {
//            if (SS[j] == S[i])
//            {
//                for (int k = j + 1; k < lenSS; k++)
//                {
//                    if (Sflag[SS[k] - 'a'] == 0 && SS[k] > S[i])
//                    {
//                        break;
//                    }
//                    if (SS[k] < S[i])
//                    {
//                        order(j, lenSS);
//                        break;
//                    }
//                }
//                break;
//            }
//        }
//    }
//    
//    std::cout << SS << '\n';
//    return 0;
//}

#include <iostream>
#include <cstdio>

const int MAXN = 1e5 + 5;
const int MAXM = 128;
const int MAXL = 27;

char  p[MAXN + 1];
int   c[MAXM], apr[MAXM], sapr[MAXM];
int   kind, min = -1, len, top = -1;
char  ans[MAXL], stack[MAXL];

//  如果是当前的最小值，加入结果，并清空stack，更新最小值
//  如果不在stack，则更新stack
//  是该种类的最后一个，直接将栈底至该元素加入结果，该元素至栈顶向下亚

int main()
{
    fgets(p, MAXN, stdin);
    
    for (int i = 0; p[i]; ++i)
    {
        ++c[p[i]];  //  每个字母出现此时
    }
    for (int i = 'a'; i <= 'z'; ++i)
    {
        if (c[i])
        {
            if (min < 0)
            {
                min = i;
            }
            ++kind; //  多少字母
        }
    }
    for (int i = 0; kind > 0; ++i)
    {
        if (apr[p[i]] == 0)         //  结果中字母状态
        {
            if (p[i] == min)
            {
                ans[len++] = p[i];
                apr[p[i]] = 1;
                --kind;
                for (++min; min <= 'z'; ++min)
                {
                    if (apr[min] == 0 && c[min])
                    {
                        break;
                    }
                }
                for (int k = 0; k <= top; ++k)
                {
                    sapr[stack[k]] = 0; //  栈内字母状态
                }
                top = -1;
            }
            else
            {
                //  update stack
                if (sapr[p[i]] == 0)    //  不在栈内
                {
                    while (top >= 0 && stack[top] > p[i])   //  保证栈内元素是单调的
                    {
                        sapr[stack[top]] = 0;
                        --top;
                    }
                    stack[++top] = p[i];
                    sapr[p[i]] = 1;
                }
                
                if (--c[p[i]] == 0)
                {
                    int  k, k2;
                    for (k = 0; k <= top; ++k)
                    {
                        ans[len++] = stack[k];
                        apr[stack[k]] = 1;
                        sapr[stack[k]] = 0;
                        --kind;
                        if (stack[k] == p[i])
                        {
                            break;
                        }
                    }
                    for (++k, k2 = -1; k <= top; ++k)
                    {
                        stack[++k2] = stack[k];
                    }
                    top = k2;
                }
            }
        }
    }
    
    puts(ans);
    
    return 0;
}