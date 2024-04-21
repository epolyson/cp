#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n, a, sum = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a;
        sum += a;
    }
    cout << -sum << endl;
    return 0;
}