//
//  main.cpp
//  f-51Nod-1272-最大距离
//
//  Created by ZYJ on 16/8/11.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 5e4 + 10;
//
//struct num
//{
//    int num;
//    int key;
//} A[MAXN];
//
//int AA[MAXN] = {1};   //  标记A状态
//
//bool cmp(num a, num b)
//{
//    if (a.num == b.num)
//    {
//        return a.key < b.key;
//    }
//    return a.num < b.num;
//}
//
//int main(int argc, const char * argv[])
//{
////    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    int N;
//    cin >> N;
//    
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", &A[i].num);
//        A[i].key = i;
//    }
//    
//    sort(A + 1, A + N + 1, cmp);
//    
//    int flag = 1;
//    int dis = 0;
//    for (int i = N; i > 1; i--)
//    {
//        if (dis < A[i].key - flag)
//        {
//            dis = A[i].key - flag;
//        }
//        AA[A[i].key] = 1;
//        if (A[i].key == flag)
//        {
//            while (AA[flag])
//            {
//                flag++;
//            }
//        }
//    }
//    
//    std::cout << dis << '\n';
//    return 0;
//}


#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 10;

struct node
{
    int index, value;
} item[MAXN];

int main()
{
    stack<node> s_1, s_2;
    int n;
    scanf("%d", &n);
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        item[i].index = i;
        scanf("%d", &item[i].value);
        //  s_1单调递增栈
        if (s_1.size() == 0 || s_1.top().value > item[i].value)
        {
            s_1.push(item[i]);
        }
        else
        {
            while (s_1.top().value <= item[i].value)
            {
                ans = max(ans, i - s_1.top().index);
                s_2.push(s_1.top());    //  将s_1的栈顶入s_2
                s_1.pop();              //  出栈
                if (s_1.empty())
                {
                    break;
                }
            }
            while (!s_2.empty())
            {
                s_1.push(s_2.top());    //  重新入队列
                s_2.pop();
            }  
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
