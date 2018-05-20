#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> h, w;

int main()
{
    int x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        h.push_back(x);
    }
    
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        w.push_back(x);
    }
    
    sort(h.begin(), h.end());
    sort(w.begin(), w.end());
    
    int cnt = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (h[i] <= w[j])
        {
            cnt++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}
