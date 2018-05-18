//
//  main.cpp
//  f-HDU-1004-Let the Balloon Rise
//
//  Created by ZYJ on 2016/10/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

string balloon;
map<string, int>::iterator it;

int main(int argc, const char * argv[])
{
    int N;
    while (cin >> N && N)
    {
        map<string, int> balloons;
        
        for (int i = 0; i < N; i++)
        {
            cin >> balloon;
            balloons[balloon]++;
        }
        
        map<string, int>::iterator it_ = it = balloons.begin();
        for (; it != balloons.end(); it++)
        {
            if (it->second > it_->second)
            {
                it_ = it;
            }
        }
        
        cout << it_->first << '\n';
    }
    
    return 0;
}
