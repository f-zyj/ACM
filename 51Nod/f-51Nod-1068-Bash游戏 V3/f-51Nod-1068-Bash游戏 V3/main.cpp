//
//  main.cpp
//  f-51Nod-1068-Bash游戏 V3
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int win[] = {1, 1, 0};

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int N;
    char S[1010];
    while (T--)
    {
        cin >> S;
        int len = (int)strlen(S);
        
        N = 0;
        for (int i = 0; i < len; i++)
        {
            N += S[i] - '0';
        }
        if (win[(N - 1) % 3])
        {
            cout << "A\n";
        }
        else
        {
            cout << "B\n";
        }
    }
    
    return 0;
}
