////
////  main.cpp
////  f-CF-Codeforces Round #410 (Div. 2)-B-Mike and strings
////
////  Created by ZYJ on 2017/4/21.
////  Copyright © 2017年 ZYJ. All rights reserved.
////
//
//#include <iostream>
//#include <string>
//#include <cstring>
//
//using namespace std;
//
//const int MAXN = 200;
//const int INF = 0x3f3f3f3f;
//
//int cnt[MAXN];
//int cnt_[MAXN];
//string s[MAXN];
//
//int main(int argc, const char * argv[])
//{
//    int n;
//    cin >> n;
//    
//    cin >> s[0];
//    for (int i = 0; i < s[0].length(); i++)
//    {
//        cnt[s[0][i]]++;
//    }
//    for (int i = 1; i < n; i++)
//    {
//        cin >> s[i];
//        memset(cnt_, 0, sizeof(cnt_));
//        if (s[i].length() != s[0].length())
//        {
//            cout << "-1\n";
//            return 0;
//        }
//        for (int j = 0; j < s[i].length(); j++)
//        {
//            cnt_[s[i][j]]++;
//            if (cnt_[s[i][j]] > cnt[s[i][j]])
//            {
//                cout << "-1\n";
//                return 0;
//            }
//        }
//    }
//    
//    int res = INF;
//    int flag = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int temp = 0;
//        for (int j = 0; j < n; j++)
//        {
//            if (i == j)
//            {
//                continue;
//            }
//            flag = 0;
//            for (int k = 0; k < s[0].length(); k++)
//            {
//                if (s[i][0] == s[j][k])
//                {
//                    flag = 1;
//                    for (int l = 1; l < s[0].length(); l++)
//                    {
//                        if (s[i][l] != s[j][(k + l) % s[0].length()])
//                        {
//                            flag = 0;
//                            break;
//                        }
//                    }
//                }
//                if (flag)
//                {
//                    temp += k;
//                    break;
//                }
//            }
//        }
//        res = min(res, temp);
//    }
//    
//    if (res == 0 && flag == 0 && n != 1)
//    {
//        cout << -1 << '\n';
//    }
//    else
//    {
//        cout << res << '\n';
//    }
//    
//    return 0;
//}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 55;
const int INF = 0x3f3f3f3f;

char s[MAXN][MAXN];
int cnt[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    
    int len = (int)strlen(s[1]);
    
    int tag = 1, flag = 0;
    for (int k = 2; k <= n; k++)
    {
        flag = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[k][i] == s[1][0])
            {
                int z = 0, j = i;
                for (; z < len; z++, j++)
                {
                    if (s[k][j % len] != s[1][z])
                    {
                        break;
                    }
                }
                if (z == len)
                {
                    cnt[k] = i;
                    flag = 1;
                    break;
                }
                
            }
        }
        if (!flag)
        {
            tag = 0;
            break;
            
        }
    }
    
    cnt[1] = 0;
    
    int len_ = 0;   //  循环节，比较坑
    for (int i = 1; i < len; i++)
    {
        if (s[1][i] == s[1][0])
        {
            int flag = 1;
            for (int j = 1; j < len; j++)
            {
                if (s[1][(i + j) % len] != s[1][j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                len_ = i;
                break;
            }
        }
    }
    
    if (!tag)
    {
        cout << "-1" << endl;
    }
    else
    {
        if (len_)
        {
            len = len_;
        }
        int ans = INF;
        for (int i = 0; i < len; i++)
        {
            int tmp = 0;
            for (int j = 1; j <= n; j++)
            {
                tmp += cnt[j];
                cnt[j] = (cnt[j] + 1) % len;
            }
            ans = min(tmp, ans);
        }
        cout << ans << endl;
    }
    
    return 0;
}
