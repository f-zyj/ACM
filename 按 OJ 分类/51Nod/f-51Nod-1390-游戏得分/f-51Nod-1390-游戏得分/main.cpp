//
//  main.cpp
//  f-51Nod-1390-游戏得分
//
//  Created by ZYJ on 16/9/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//const int INF = 0x3f3f3f3f;
//
//int ans;
//long long x, y;
//
//void dfs(long long round, long long tmp, int count)
//{
//    if (tmp == 0 && count < ans)
//    {
//        ans = count;
//        return ;
//    }
//    for (long long i = round; i > 0; i--)
//    {
//        if (ans != INF)
//        {
//            break;
//        }
//        if (2 * i - 1 > tmp)
//        {
//            continue;
//        }
//        if (i * i < tmp)
//        {
//            break;
//        }
//        dfs(i - 1, tmp - 2 * i + 1, count + 1);
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
//    int T;
//    cin >> T;
//    while (T--)
//    {
//        cin >> x >> y;
//        int round = (int)sqrt(x + y);
//        if (round != sqrt(x + y) || x == 2 || y == 2)
//        {
//            cout << "-1\n";
//            continue;
//        }
//        
//        ans = INF;
//        
//        dfs(round, x, 0);
//        
//        cout << ans << '\n';
//    }
//    
//    return 0;
//}
//
//#include <iostream>
//#include <cmath>
//
//#define LL long long
//
//using namespace std;
//
//int main()
//{
//    LL a, b, sum;
//    LL T;
//    cin >> T;
//    while (T--)
//    {
//        cin >> a >> b;
//        sum = a + b;
//        double tmp = sqrt(sum * 1.0);
//        LL count;
//        if (tmp != floor(tmp) || a == 2 || b == 2)
//        {
//            cout << -1 << endl;
//            continue;
//        }
//        else
//        {
//            count = tmp;    //  回合总数
//        }
//        
//        if (!b)             //  当b为0时可以直接输出回合总数
//        {
//            cout << count << endl;
//            continue;
//        }
//        LL t = 0;
//        bool flag = false;
//        LL num = 0;
//        for (LL i = 1; i <= count; ++i)
//        {
//            if (i * i > a)
//            {
//                break;
//            }
//            t = a + i;
//            num = (2 * count - i + 1) * i / 2;
//            if (t % 2 == 0 && ((LL)(t / 2.0 + 0.5) <= num))
//            {
//                cout << i << endl;
//                flag = true;
//                break;
//            }
//        }
//        if (!flag)
//        {
//            cout << 0 << endl;
//        }
//    }
//    return 0;
//}

#include <iostream>
#include <cmath>

using namespace std;

int T;
long long x, y;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> x >> y;
        long long up = (long long)sqrt(x + y);
        bool flag = false;
        if ((x + y) == up * up)
        {
            if (x == 0)
            {
                cout << 0 << endl;
                continue;
            }
            long long i = 1;
            if ((x & 1) == 0)
            {
                i += 1;
            }
            
            for (; i <= up; i += 2)
            {
                if (i * i <= x && x <= 2 * i * up - i * i)
                {
                    flag = true;
                    cout << i << endl;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
