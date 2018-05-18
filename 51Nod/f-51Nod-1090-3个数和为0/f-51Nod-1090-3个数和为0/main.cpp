//
//  main.cpp
//  f-51Nod-1090-3个数和为0
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

int A[MAXN];

int main(int argc, const char * argv[])
{
//    freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A, A + N);
    int flag_1 = 0, flag_2 = N - 1;
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] < 0 && A[i + 1] >= 0)
        {
            flag_1 = i;
        }
        if (A[i] <= 0 && A[i + 1] > 0)
        {
            flag_2 = i + 1;
            break;
        }
    }
    bool tag = true;
    int sum;
    for (int i = 0; i < flag_2; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            sum = A[i] + A[j];
            if (sum < 0)
            {
                for (int k = flag_2 > (j + 1) ? flag_2 : (j + 1); k < N; k++)
                {
                    if (sum + A[k] == 0)
                    {
                        printf("%d %d %d\n", A[i], A[j], A[k]);
                        tag = false;
                    }
                }
            }
            else if (sum == 0)
            {
                for (int k = j + 1; k < flag_2; k++)
                {
                    printf("0 0 0\n");
                    tag = false;
                }
            }
        }
    }
    if (tag)
    {
        puts("No Solution");
    }
    
    return 0;
}
