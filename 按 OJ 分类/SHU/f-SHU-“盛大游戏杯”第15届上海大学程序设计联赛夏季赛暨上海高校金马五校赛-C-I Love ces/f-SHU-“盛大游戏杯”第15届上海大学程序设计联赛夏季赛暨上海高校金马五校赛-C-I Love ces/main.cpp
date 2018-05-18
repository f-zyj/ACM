//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-C-I Love ces
//
//  Created by ZYJ on 2017/7/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 100;
const int MAGIC = 32;
const int INF = 0x3f3f3f3f;

string s;
int cnt[MAXN];

int main(int argc, const char * argv[])
{
    while (cin >> s)
    {
        memset(cnt, 0, sizeof(cnt));
        
        int len = (int)s.length();
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= 'a')
            {
                s[i] -= MAGIC;
            }
            cnt[s[i]]++;
        }
        cnt['E'] /= 2;
        
        int res = INF;
        res = min(res, cnt['I']);
        res = min(res, cnt['L']);
        res = min(res, cnt['O']);
        res = min(res, cnt['V']);
        res = min(res, cnt['E']);
        res = min(res, cnt['C']);
        res = min(res, cnt['S']);
        
        cout << res << '\n';
    }
    
    return 0;
}
