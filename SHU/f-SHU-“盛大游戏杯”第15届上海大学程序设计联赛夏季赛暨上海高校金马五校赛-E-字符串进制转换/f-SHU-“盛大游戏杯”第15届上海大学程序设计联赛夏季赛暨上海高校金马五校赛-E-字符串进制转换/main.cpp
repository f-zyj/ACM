//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-E-字符串进制转换
//
//  Created by ZYJ on 2017/7/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

const int MAXN = 15;
const int MAGIC = 26;

int m;
ll POW[MAXN] = {1};
string A;

void init()
{
    for (int i = 1; i < MAXN; i++)
    {
        POW[i] = POW[i - 1] * MAGIC;
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    while (cin >> A >> m)
    {
        ll num = 0;
        for (int i = (int)A.length() - 1, j = 0; i >= 0; i--, j++)
        {
            num += (A[i] - 'a') * POW[j];
        }
        
        if (num == 0)
        {
            cout << "0\n";
            continue;
        }
        
        string ans;
        while (num)
        {
            ans.push_back(num % m + '0');
            num /= m;
        }
        reverse(ans.begin(), ans.end());
        
        cout << ans << '\n';
    }
    
    return 0;
}
