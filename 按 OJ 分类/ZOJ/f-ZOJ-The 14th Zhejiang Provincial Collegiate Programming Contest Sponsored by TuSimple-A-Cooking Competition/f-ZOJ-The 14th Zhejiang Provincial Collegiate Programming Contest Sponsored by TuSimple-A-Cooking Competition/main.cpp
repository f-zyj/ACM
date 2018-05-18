//
//  main.cpp
//  f-ZOJ-The 14th Zhejiang Provincial Collegiate Programming Contest Sponsored by TuSimple-A-Cooking Competition
//
//  Created by ZYJ on 2017/4/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int K[] = {0, 1, 0, 1, -1};
const int D[] = {0, 0, 1, 1, -1};

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int n, x, resK, resD;
    while (T--)
    {
        cin >> n;
        resK = resD = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            resK += K[x];
            resD += D[x];
        }
        if (resK > resD)
        {
            cout << "Kobayashi\n";
        }
        else if (resK < resD)
        {
            cout << "Tohru\n";
        }
        else
        {
            cout << "Draw\n";
        }
    }
    
    return 0;
}
