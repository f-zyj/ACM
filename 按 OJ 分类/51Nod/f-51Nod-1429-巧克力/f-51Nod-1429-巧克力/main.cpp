//
//  main.cpp
//  f-51Nod-1429-巧克力
//
//  Created by ZYJ on 2017/6/24.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//const int MAXN = 5;
//
//int a1, b1; //  A a1 b1
//int a2, b2; //  B a2 b2
//int cnt_2[MAXN];
//int cnt_3[MAXN];
//
//void get_cnt(int cnt[], int &x1, int &x2, int &y1, int &y2, int div)
//{
//    while (x1 % div == 0)
//    {
//        cnt[0]++;
//        x1 /= div;
//    }
//    while (x2 % div == 0)
//    {
//        cnt[1]++;
//        x2 /= div;
//    }
//    while (y1 % div == 0)
//    {
//        cnt[2]++;
//        y1 /= div;
//    }
//    while (y2 % div == 0)
//    {
//        cnt[3]++;
//        y2 /= div;
//    }
//}
//
//int main()
//{
//    cin >> a1 >> b1;
//    cin >> a2 >> b2;
//    
//    int x_A = a1, x_B = a2, y_A = b1, y_B = b2;
//    
//    get_cnt(cnt_2, x_A, x_B, y_A, y_B, 2);
//    get_cnt(cnt_3, x_A, x_B, y_A, y_B, 3);
//    
//    
//    if (x_A * y_A != x_B * y_B)
//    {
//        cout << -1 << endl;
//    }
//    else
//    {
//        int ans = 0;
//        int cnt_A_2 = cnt_2[0] + cnt_2[2];
//        int cnt_B_2 = cnt_2[1] + cnt_2[3];
//        int cnt_A_3 = cnt_3[0] + cnt_3[2];
//        int cnt_B_3 = cnt_3[1] + cnt_3[3];
//        
//        int A_B_3 = 0, B_A_3 = 0, A_B_2 = 0, B_A_2 = 0;
//        if (cnt_A_3 > cnt_B_3)
//        {
//            A_B_3 = cnt_A_3 - cnt_B_3;
//            cnt_A_2 += A_B_3;
//            ans += A_B_3;
//        }
//        else
//        {
//            B_A_3 = cnt_B_3 - cnt_A_3;
//            cnt_B_2 += B_A_3;
//            ans += B_A_3;
//        }
//        
//        if (cnt_A_2 > cnt_B_2)
//        {
//            A_B_2 = cnt_A_2 - cnt_B_2;
//            ans += A_B_2;
//        }
//        else
//        {
//            B_A_2 = cnt_B_2 - cnt_A_2;
//            ans += B_A_2;
//        }
//        cout << ans << endl;
//    }
//    
//    return 0;
//}

#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int a1, b1; //  A a1 b1
int a2, b2; //  B a2 b2
ll area_A, area_B;
int cnt_A_2, cnt_B_2;
int cnt_A_3, cnt_B_3;

void get_cnt(int &cnt_A, int & cnt_B, int div)
{
    while (area_A % div == 0)
    {
        cnt_A++;
        area_A /= div;
    }
    while (area_B % div == 0)
    {
        cnt_B++;
        area_B /= div;
    }
}

int main()
{
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    
    area_A = 1LL * a1 * b1;
    area_B = 1LL * a2 * b2;
    
    get_cnt(cnt_A_2, cnt_B_2, 2);
    get_cnt(cnt_A_3, cnt_B_3, 3);
    
    if (area_A != area_B)
    {
        cout << -1 << endl;
    }
    else
    {
        int ans = 0;
        int A_B_3 = 0, B_A_3 = 0, A_B_2 = 0, B_A_2 = 0;
        if (cnt_A_3 > cnt_B_3)
        {
            A_B_3 = cnt_A_3 - cnt_B_3;
            cnt_A_2 += A_B_3;
            ans += A_B_3;
        }
        else
        {
            B_A_3 = cnt_B_3 - cnt_A_3;
            cnt_B_2 += B_A_3;
            ans += B_A_3;
        }
        
        if (cnt_A_2 > cnt_B_2)
        {
            A_B_2 = cnt_A_2 - cnt_B_2;
            ans += A_B_2;
        }
        else
        {
            B_A_2 = cnt_B_2 - cnt_A_2;
            ans += B_A_2;
        }
        cout << ans << endl;
    }
    
    return 0;
}
