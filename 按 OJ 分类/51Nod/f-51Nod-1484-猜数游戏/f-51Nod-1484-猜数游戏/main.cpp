#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAXH = 55;

typedef long long ll;

int h, q;
ll res = 0;
int vis[MAXH];
vector<pair<ll, ll> > route[MAXH];
vector<pair<ll, ll> >::iterator it;

void pri(int i)
{
    if (i == 1)
    {
        cout << "Game cheated!\n";
    }
    else if (i == 2)
    {
        cout << "Data not sufficient!\n";
    }
    else
    {
        if (res == 0)
        {
            cout << "Game cheated!\n";
        }
        else
        {
            cout << res << '\n';
        }
    }
    res = -1;
}

void dfs(ll L, ll R, int high)
{
    vector<pair<ll, ll> >::iterator it_;
    if (high == h)
    {
        for (it_ = route[high].begin(); it_ != route[high].end(); it_++)
        {
            if ((*it_).first >= L && (*it_).second <= R)
            {
                if ((*it_).first != (*it_).second || res > 0)
                {
                    pri(2);
                }
                else if (res != -1)
                {
                    res = (*it_).first;
                }
            }
            else if ((*it_).first < L && (*it_).second <= R)
            {
                if ((*it_).second != L || res > 0)
                {
                    pri(2);
                }
                else if (res != -1)
                {
                    res = L;
                }
            }
            else if ((*it_).first >= L && (*it_).second > R)
            {
                if (R != (*it_).first || res > 0)
                {
                    pri(2);
                }
                else if (res != -1)
                {
                    res = R;
                }
            }
            else if ((*it_).first < L && (*it_).second > R)
            {
                if (L != R || res > 0)
                {
                    pri(2);
                }
                else if (res != -1)
                {
                    res = L;
                }
            }
        }
        return ;
    }
    
    for (it_ = route[high].begin(); it_ != route[high].end(); it_++)
    {
        if ((*it_).first >= L && (*it_).second <= R && !res)
        {
            dfs((*it_).first * 2, (*it_).second * 2 + 1, high + 1);
        }
        else if ((*it_).first < L && (*it_).second <= R && (*it_).second >= L && !res)
        {
            dfs(L * 2, (*it_).second * 2 + 1, high + 1);
        }
        else if ((*it_).first >= L && (*it_).first <= R && (*it_).second > R && !res)
        {
            dfs((*it_).first * 2, R * 2 + 1, high + 1);
        }
        else if ((*it_).first < L && (*it_).second > R && !res)
        {
            dfs(L * 2, R * 2 + 1, high + 1);
        }
    }
}

int main(int argc, const char * argv[])
{
    //    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    cin >> h >> q;
    
    int i, ans;
    ll L, R;
    for (int j = 0; j < q; j++)
    {
        scanf("%d%lld%lld%d", &i, &L, &R, &ans);
        
        if (ans)
        {
            if (!vis[i])
            {
                route[i].push_back({L, R});
            }
            else
            {
                for (it = route[i].begin(); it != route[i].end(); )
                {
                    if ((*it).second < L || (*it).first > R)
                    {
                        it = route[i].erase(it);
                    }
                    else
                    {
                        if ((*it).first < L)
                        {
                            (*it).first = L;
                        }
                        if ((*it).second > R)
                        {
                            (*it).second = R;
                        }
                        it++;
                    }
                }
                if (route[i].empty())
                {
                    pri(1);
                    return 0;
                }
            }
        }
        else
        {
            if (!vis[i])
            {
                if (L != pow(2, i - 1))
                {
                    route[i].push_back({pow(2, i - 1), L - 1});
                }
                if (R != pow(2, i) - 1)
                {
                    route[i].push_back({R + 1, pow(2, i) - 1});
                }
                if (route[i].empty())
                {
                    pri(1);
                    return 0;
                }
            }
            else
            {
                if (route[i].empty())
                {
                    pri(1);
                    return 0;
                }
                for (it = route[i].begin(); it != route[i].end(); )
                {
                    if ((*it).first >= L && (*it).second <= R)
                    {
                        it = route[i].erase(it);
                        if (route[i].empty())
                        {
                            pri(1);
                            return 0;
                        }
                    }
                    else
                    {
                        if ((*it).first < L && (*it).second > R)
                        {
                            ll r = (*it).second;
                            (*it).second = L - 1;
                            route[i].push_back({R + 1, r});
                            it = route[i].begin();
                        }
                        else
                        {
                            if ((*it).first <= R && (*it).second > R)
                            {
                                (*it).first = R + 1;
                            }
                            if ((*it).second >= L && (*it).first < L)
                            {
                                (*it).second = L - 1;
                            }
                            it++;
                        }
                    }
                }
            }
        }
        vis[i] = 1;
    }
    
    for (int j = 1; j <= h; j++)
    {
        if (!vis[j])
        {
            route[j].push_back({pow(2, j - 1), pow(2, j) - 1});
        }
    }
    
    dfs(1, 1, 1);
    
    if (res != -1)
    {
        pri(3);
    }
    
    return 0;
}
