//
//  main.cpp
//  f-CF-Codeforces Round #365 (Div. 2)-A-Mishka and Game
//
//  Created by ZYJ on 16/8/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    
    int winM = 0, winC = 0;
    int m, c;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> c;
        if (m > c)
        {
            winM++;
        }
        else if (m < c)
        {
            winC++;
        }
    }
    
    if (winM == winC)
    {
        cout << "Friendship is magic!^^\n";
    }
    else if (winM > winC)
    {
        cout << "Mishka\n";
    }
    else
    {
        cout << "Chris\n";
    }
    
    return 0;
}
