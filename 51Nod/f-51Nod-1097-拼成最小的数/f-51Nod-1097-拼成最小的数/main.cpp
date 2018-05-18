//
//  main.cpp
//  f-51Nod-1097-拼成最小的数
//
//  Created by ZYJ on 16/8/6.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e4 + 10;
const int MAXA = 11;

struct num
{
    char A[MAXA];   //  数据
    int num;        //  值
    int len;        //  长度
} Num[MAXN];

bool cmp(num a, num b)
{
    //  长度相同则比较大小
    if (a.len == b.len)
    {
        return a.num < b.num;
    }
    
    int lenMin = a.len > b.len ? b.len : a.len;
    
    //  逐位比较 从小到大排
    for (int i = 0; i < lenMin; i++)
    {
        if (a.A[i] != b.A[i])
        {
            return a.A[i] < b.A[i];
        }
    }
    
    //  0~lenMin-1为相同部分（一个是另一个的前缀）
    //  如果lenMin位小于0位，则排在前边
    //  (1)、（2）是为了改变类似于4177、41774，4577、45774的顺序
    if (a.len > b.len)
    {
        int i = 0;
        while (a.A[lenMin] == a.A[i])
        {
            lenMin++;
            i++;
        }
        if (lenMin == a.len)        //  (1)
        {
            return a.A[1] > a.A[0];
        }
        return a.A[lenMin] < a.A[i];
    }
    else
    {
        int i = 0;
        while (b.A[lenMin] == b.A[i])
        {
            lenMin++;
            i++;
        }
        if (lenMin == b.len)        //  (2)
        {
            return b.A[1] < b.A[0];
        }
        return !(b.A[lenMin] < b.A[i]);
    }
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    freopen("/Users/zyj/Desktop/output.txt", "w", stdout);
    
    int N;
    cin >> N;
    
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", Num[i].A);
        Num[i].num = atoi(Num[i].A);
        Num[i].len = (int)strlen(Num[i].A);
        len += Num[i].len;
    }
    sort(Num, Num + N, cmp);
   
    //  输出（每行最多1000字符）
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        if (flag + Num[i].len < 1000)
        {
            flag += Num[i].len;
            cout << Num[i].A;
        }
        else
        {
            for (int j = 0; j < Num[i].len; j++)
            {
                cout << Num[i].A[j];
                if (++flag == 1000)
                {
                    cout << '\n';
                    flag = Num[i].len - j - 1;
                    printf("%s", Num[i].A + j + 1);
                    break;
                }
            }
        }
    }
    
    cout << '\n';
    
    return 0;
}
