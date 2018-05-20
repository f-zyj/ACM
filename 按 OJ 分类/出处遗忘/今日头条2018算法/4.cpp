#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;  //  设置数组最大长度
const int MAX_NUM = 100;    //  设置元素最大值

int n;
int a[MAXN];                //  题目给定数组序列
int l[MAXN];                //  l[i] 表示第 i 个元素作为最小值最大区间的左界
int r[MAXN];                //  r[i] 表示第 i 个元素作为最小值最大区间的右界
int s[MAXN];                //  s[i] 表示前 i 个元素的和

//  初始化函数，预处理前缀和
void init()
{
    s[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }
}

int main()
{
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
    }
    
    init();
    
    //  从左往右遍历，获取 l
    int L, R;
    for (int i = 1; i <= MAX_NUM; ++i)
    {
        L = 1;
        for (int j = 1; j <= n; ++j)
        {
            if (a[j] < i)
            {
                L = j + 1;
            }
            if (a[j] == i)
            {
                l[j] = L;
            }
        }
    }
    
    //  从右往左遍历，获取 r
    for (int i = 1; i <= MAX_NUM; ++i)
    {
        R = n;
        for (int j = n; j >= 1; --j)
        {
            if (a[j] < i)
            {
                R = j - 1;
            }
            if (a[j] == i)
            {
                r[j] = R;
            }
        }
    }
    
    //  枚举取最优解
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, (s[r[i]] - s[l[i] - 1]) * a[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}
