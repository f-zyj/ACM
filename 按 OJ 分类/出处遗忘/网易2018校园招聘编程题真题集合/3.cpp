#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    cin >> s;
    
    double len = s.length();
    
    char c = '?';
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != c)
        {
            cnt++;
            c = s[i];
        }
    }
    
    printf("%.2f\n", len / cnt);
    
    return 0;
}
