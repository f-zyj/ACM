//
//  main.cpp
//  f-51Nod-1127-最短的包含字符串
//
//  Created by ZYJ on 16/8/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int INF = 0x3f3f3f3f;


int flag[27] = {0};
string S;

int main(int argc, const char * argv[])
{
    cin >> S;
    
    int ans = INF;
    int num = 0;
    int left = 0, right = 0;
    for (; right < S.length(); right++)
    {
        if (flag[S[right] - 'A'] == 0)
        {
            num++;
        }
        flag[S[right] - 'A']++;
        while (flag[S[left] - 'A'] > 1)
        {
            flag[S[left] - 'A']--;
            left++;
        }
        if (num == 26)
        {
            ans = ans > right - left + 1 ? right - left + 1 : ans;
        }
    }
   
    if (ans == INF)
    {
        cout << "No Solution" << '\n';
        return 0;
    }
    std::cout << ans << '\n';
    return 0;
}
