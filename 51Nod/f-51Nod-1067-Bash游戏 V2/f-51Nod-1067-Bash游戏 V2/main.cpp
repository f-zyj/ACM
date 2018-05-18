//
//  main.cpp
//  f-51Nod-1067-Bash游戏 V2
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int win[] = {1, 0, 1, 1, 1, 1, 0};    //  2、7必输

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int N;
    while (T--)
    {
        cin >> N;
        if (win[(N - 1) % 7])
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
