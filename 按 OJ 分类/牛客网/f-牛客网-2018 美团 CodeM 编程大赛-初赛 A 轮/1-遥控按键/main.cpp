//
//  main.cpp
//  f-牛客网-2018 美团 CodeM 编程大赛-初赛 A 轮
//
//  Created by ZYJ on 2018/6/9.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MAXN = 27;

int T;
string s;

struct location
{
    int x, y;
} letter[MAXN];

void init()
{
    letter[0] = letter[1] = letter[2] = {0, 1};
    letter[3] = letter[4] = letter[5] = {0, 2};
    letter[6] = letter[7] = letter[8] = {1, 0};
    letter[9] = letter[10] = letter[11] = {1, 1};
    letter[12] = letter[13] = letter[14] = {1, 2};
    letter[15] = letter[16] = letter[17] = letter[18] = {2, 0};
    letter[19] = letter[20] = letter[21] = {2, 1};
    letter[22] = letter[23] = letter[24] = letter[25] = {2, 2};
}

int main(int argc, const char * argv[])
{
    init();
    
    cin >> T;
    while (T--)
    {
        cin >> s;
        
        int ans = 0;
        location init = {0, 0};
        for (int i = 0; i < s.length(); i++)
        {
            location curr = letter[s[i] - 'A'];
            ans += abs(curr.x - init.x) + abs(curr.y - init.y);
            init = curr;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
