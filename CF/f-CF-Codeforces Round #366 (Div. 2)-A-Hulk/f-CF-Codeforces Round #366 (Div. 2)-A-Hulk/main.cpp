//
//  main.cpp
//  f-CF-Codeforces Round #366 (Div. 2)-A-Hulk
//
//  Created by ZYJ on 16/8/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const char say[][100] = {"I hate that", "I love that"};
const char say_[][100] = {"I hate it", "I love it"};

int main(int argc, const char * argv[])
{
    int n;
    
    int tag;
    while (cin >> n)
    {
        tag = 0;
        for (; tag < n - 1; tag++)
        {
            cout << say[tag % 2] << ' ';
        }
        cout << say_[(n + 1) % 2] << '\n';
    }
    
    return 0;
}
