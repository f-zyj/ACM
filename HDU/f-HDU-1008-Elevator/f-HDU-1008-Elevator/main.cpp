//
//  main.cpp
//  f-HDU-1008-Elevator
//
//  Created by ZYJ on 2016/10/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int N;
    while (cin >> N && N)
    {
        int tot = 5 * N;
        int floor = 0;
        int req;
        for (int i = 0; i < N; i++)
        {
            cin >> req;
            if (req > floor)
            {
                tot += (req - floor) * 6;
            }
            else
            {
                tot += (floor - req) * 4;
            }
            floor = req;
        }
        
        cout << tot << '\n';
    }
    
    return 0;
}
