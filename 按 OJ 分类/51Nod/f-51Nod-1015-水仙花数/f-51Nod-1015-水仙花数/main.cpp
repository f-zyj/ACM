//
//  main.cpp
//  f-51Nod-1015-水仙花数
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int NarNum[] = {153, 370, 371, 407, 1634};

int main(int argc, const char * argv[])
{
    int M;
    while (cin >> M)
    {
        for (int i = 0; i < 5; i++)
        {
            if (NarNum[i] >= M)
            {
                cout << NarNum[i] << '\n';
                break;
            }
        }
    }
    
    return 0;
}
