//
//  main.cpp
//  f-使序列有序的最少交换次数
//
//  Created by ZYJ on 2017/5/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

//int getMinSwaps(vector<int> &A)
//{
//    //  排序
//    vector<int> B(A);
//    sort(B.begin(), B.end());
//    map<int, int> m;
//    int len = (int)A.size();
//    for (int i = 0; i < len; i++)
//    {
//        m[B[i]] = i;    //  建立每个元素与其应放位置的映射关系
//    }
//    
//    int loops = 0;      //  循环节个数
//    vector<bool> flag(len, false);
//    //  找出循环节的个数
//    for (int i = 0; i < len; i++)
//    {
//        if (!flag[i])
//        {
//            int j = i;
//            while (!flag[j])
//            {
//                flag[j] = true;
//                j = m[A[j]];    //  原序列中j位置的元素在有序序列中的位置
//            }
//            loops++;
//        }
//    }
//    return len - loops;
//}
//
//vector<int> nums;
//
//int main()
//{
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(4);
//    nums.push_back(3);
//    nums.push_back(5);
//    
//    int res = getMinSwaps(nums);
//    
//    cout << res << '\n';
//    
//    return 0;
//}

/*
 *  默认目标映射关系是 key 1 => val 1 …… key n => val n
 *  如果序列不是 1~n 可以通过 map 建立新的目标映射关系
 */
const int MAXN = 30;

int n;
int vis[MAXN];
int A[MAXN], B[MAXN];

int getMinSwaps()
{
    memset(vis, 0, sizeof(vis));
    
    for (int i = 1; i <= n; i++)
    {
        B[A[i]] = A[i % n + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        B[i] = (B[i] - 2 + n) % n + 1;
    }
    
    int cnt = n;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        vis[i] = 1;
        cnt--;
        for (int j = B[i]; j != i; j = B[j])
        {
            vis[j] = 1;
        }
    }
    
    return cnt;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    
    int res = getMinSwaps();
    
    cout << res << '\n';
    
    return 0;
}
