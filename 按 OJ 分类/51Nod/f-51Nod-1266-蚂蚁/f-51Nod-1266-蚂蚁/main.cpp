//
//  main.cpp
//  f-51Nod-1266-蚂蚁
//
//  Created by ZYJ on 16/8/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int N, L;
    
    int A;
    while (cin >> N >> L)
    {
        int MAX = -1;
        int MIN = -1;
        
        int MAX_, MIN_;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A);
            MAX_ = A > L - A ? A : L - A;
            MIN_ = L - MAX_;
            //  最长时间从每只蚂蚁的最长时间里取最长
            if (MAX < MAX_)
            {
                MAX = MAX_;
            }
            //  最短时间从每只蚂蚁的最短时间里去最长
            if (MIN < MIN_)
            {
                MIN = MIN_;
            }
        }
        
        cout << MIN << ' ' << MAX << '\n';
    }
    
    return 0;
}
