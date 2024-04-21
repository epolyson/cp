#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, t;
    cin >> n >> q;
    map<int, int> mp;
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        mp[t]++;
    }

    for (const auto &[_, value] : mp)
    {
        if (value % 2 != 0)
        {
            n--;
        }
    }

    cout << n << endl;
    return 0;
}