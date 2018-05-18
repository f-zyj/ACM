//
//  main.cpp
//  f-51Nod-1381-硬币游戏
//
//  Created by ZYJ on 16/7/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int R;
    while (T--)
    {
        cin >> R;
        cout << R + R << '\n';
    }
    
    return 0;
}
