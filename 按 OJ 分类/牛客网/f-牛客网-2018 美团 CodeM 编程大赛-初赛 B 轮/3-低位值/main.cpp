//
//  main.cpp
//  f-牛客网-2018 美团 CodeM 编程大赛-初赛 B 轮
//
//  Created by ZYJ on 2018/6/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>
#include <string>

using namespace std;

const int MAXN = 2e4 + 10;

string num;
long long temp[MAXN] = {0, 1, 1};

void init()
{
    for (int i = 3; i < MAXN; i++)
    {
        temp[i] = temp[i - 1] + i - 1;
    }
}

int main(int argc, const char * argv[])
{
    init();
    
    cin >> num;
    
    long long ans = 0;
    for (int i = 1; i < num.length(); i++)
    {
        if (num[i] == '1')
        {
            ans = (num.length() - 1) - i;
            break;
        }
    }
    
    long long cnt = 0;
    for (int i = 1; i < num.length(); i++)
    {
        if (num[i] == '1')
        {
            cnt++;
        }
    }
    
    ans = max(ans, cnt);
    ans += temp[num.length()];
    
    cout << ans << '\n';
    
    return 0;
}
