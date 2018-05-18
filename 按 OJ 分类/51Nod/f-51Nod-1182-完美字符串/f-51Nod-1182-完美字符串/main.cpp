//
//  main.cpp
//  f-51Nod-1182-完美字符串
//
//  Created by ZYJ on 16/7/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string S;
int letter[100] = {0};

int main(int argc, const char * argv[])
{
    while (cin >> S)
    {
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] > 90)
            {
                S[i] -= 32;
            }
            letter[S[i]]++;
        }
        sort(letter + 65, letter + 91);
        int val = 26;
        int ans = 0;
        for (int i = 90; i >= 65; i--)
        {
            ans += letter[i] * val--;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
