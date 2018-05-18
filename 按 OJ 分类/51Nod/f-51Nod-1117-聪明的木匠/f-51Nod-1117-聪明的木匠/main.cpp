//
//  main.cpp
//  f-51Nod-1117-聪明的木匠
//
//  Created by ZYJ on 16/8/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    int num;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &num);
        q.push(num);
    }
    
    int temp_1, temp_2;
    int sum = 0;
    while (q.size() > 1)
    {
        temp_1 = q.top();   //  每次先合并长度最小的
        q.pop();
        temp_2 = q.top();
        q.pop();
        sum += temp_1 + temp_2;
        q.push(temp_1 + temp_2);
    }
    
    printf("%d\n", sum);
    
    return 0;
}
