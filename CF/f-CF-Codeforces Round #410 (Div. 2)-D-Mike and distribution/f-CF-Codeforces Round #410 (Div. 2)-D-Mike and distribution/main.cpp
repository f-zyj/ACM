////
////  main.cpp
////  f-CF-Codeforces Round #410 (Div. 2)-D-Mike and distribution
////
////  Created by ZYJ on 2017/4/23.
////  Copyright © 2017年 ZYJ. All rights reserved.
////
//
////#include <iostream>
////#include <algorithm>
////#include <ctime>
////
////using namespace std;
////
////typedef long long ll;
////
////const int MAXN = 1e5 + 10;
////
////int n;
////int pos[MAXN];
////int a[MAXN], b[MAXN];
////ll sumA, sumB;
////
////int main(int argc, char const *argv[])
////{
////    scanf("%d", &n);
////    for (int i = 0; i < n; i++)
////    {
////        scanf("%d", a + i);
////        sumA += a[i];
////        a[i] <<= 1;
////        pos[i] = i;
////    }
////    for (int i = 0; i < n; i++)
////    {
////        scanf("%d", b + i);
////        sumB += b[i];
////        b[i] <<= 1;
////    }
////    
////    int mid = n / 2 + 1;
////    srand((int)time(0));
////    while (1)
////    {
////        ll s1 = 0, s2 = 0;
////        random_shuffle(pos , pos + n);
////        for (int i = 0; i < mid; i++)
////        {
////            s1 += a[pos[i]];
////            s2 += b[pos[i]];
////        }
////        if (s1 > sumA && s2 > sumB)
////        {
////            printf("%d\n%d", mid, pos[0] + 1);
////            for (int i = 1; i < mid; i++)
////            {
////                printf(" %d", pos[i] + 1);
////            }
////            puts("");
////            return 0;
////        }
////    }
////    
////    return 0;
////}
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//const int MAXN = 1e5 + 5;
//
//struct abpos
//{
//    int a;
//    int b;
//    int pos;
//};
//
//abpos c[MAXN];
//vector<int> ans;
//
//int n;
//int a[MAXN], b[MAXN];
//
//bool cmp(abpos a, abpos b)
//{
//    return a.a < b.a;
//}
//
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> a[i];
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> b[i];
//    }
//    
//    c[0].a = c[0].b = c[0].pos = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        c[i].a = a[i];
//        c[i].b = b[i];
//        c[i].pos = i;
//    }
//    sort(c + 1, c + n + 1, cmp);
//    
//    ans.push_back(c[n].pos);
//    
//    for (int i = n - 1; i >= 1; i -= 2)
//    {
//        if (c[i].b > c[i - 1].b)
//        {
//            ans.push_back(c[i].pos);
//        }
//        else
//        {
//            ans.push_back(c[i - 1].pos);
//        }
//    }
//    
//    cout << ans.size() << endl;
//    for (int i = 0; i < ans.size(); i++)
//    {
//        cout << ans[i] << ' ';
//    }
//    
//    return 0;
//}

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tp;

const int MAXN = 1e5 + 5;

tp tpThree[MAXN];
vector<int> ans;

int n;
int a[MAXN], b[MAXN];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        tpThree[i] = tp(a[i], b[i], i);
    }
    tpThree[0] = tp(0, 0, 0);
    sort(tpThree + 1, tpThree + n + 1);
    
    int pos;
    tie(ignore, ignore, pos) = tpThree[n];
    ans.push_back(pos);
    
    int y, y_, pos_;
    for (int i = n - 1; i >= 1; i -= 2)
    {
        tie(ignore, y, pos) = tpThree[i];
        tie(ignore, y_, pos_) = tpThree[i - 1];
        if (y > y_)
        {
            ans.push_back(pos);
        }
        else
        {
            ans.push_back(pos_);
        }
    }
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    
    return 0;
}
