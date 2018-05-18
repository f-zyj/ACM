//
//  main.cpp
//  f-51Nod-1095-Anigram单词
//
//  Created by ZYJ on 16/8/2.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    map<string, int> mp_1, mp_2;
    for (int i = 0; i < n; i++)
    {
        char s[11];
        scanf("%s", s);
        int len = (int)strlen(s);
        //  原串存入
        mp_1[s]++;
        //  排序后并存入
        sort(s, s + len);
        mp_2[s]++;
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        char s[11];
        scanf("%s", s);
        int len = (int)strlen(s);
        //  查找原串
        int num_1 = mp_1[s];
        sort(s, s + len);
        //  查找排序后串
        int num_2 = mp_2[s];
        //  相减即可得到所求
        cout << num_2 - num_1 << endl;
    }
    return 0;
}